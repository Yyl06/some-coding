#include "Book.hpp"
#include "Library.hpp"
#include "Users.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using std::string, std::cout, std::cin, std::getline;

//Declared functions written on cpp to improve code maintainability(changes made by YuanLin)
void Library::saveToFile(){
	std::ofstream File("Books.txt", std::ios::out);
	for(const auto &Book : Shelf){
		File << Book->getTitle()
		<< "," << Book->getAuthor() << "," << (Book->statusBook() ? "1" : "0") << ","
		<< (dynamic_cast<ReferenceBook *>(Book) ? "Reference" : "Normal") << "," << Book->getDueDate() << "\n";
		// use dynamic_cast when especially in cases where type safety is critical (e.g., when dealing with polymorphic classes)
	}
	File.close();
}

void Library::loadFromFile(){
	std::ifstream File("Books.txt", std::ios::in);
	string title, author, status, type, dueDateStr;
	Shelf.clear();

	while(getline(File, title, ',')
	&& getline(File, author, ',')
	&& getline(File, status, ',')
	&& getline(File, type, ',')
	&& getline(File, dueDateStr)){
		Book *b;
		if(type == "Reference"){
			b = new ReferenceBook(title, author);
		}else{
			b = new Book(title, author);
		}
		b->setAvailability(status == "1" ? false : true);  // 1 = Borrowed
		b->setDueDate(std::stoll(dueDateStr));  // Restore due date
		Shelf.push_back(b);
	}
	File.close();
}

void Library::saveUsersToFile(){
	std::ofstream File("Users.txt", std::ios::out);
	if (!File){
		std::cerr << "Error: Could not open Users.txt for writing!\n";
		return;
	}

	for (const auto &user : Users){
		File << user.getUsername() << "," << user.getPassword() << "," << user.getRole();
		for(const auto &book : user.borrowedBooks) {
			File << "," << book.first << " " << book.second;
		}
		File << "\n";
	}
	File.close();
}

void Library::loadUsersFromFile(){
	std::ifstream File("Users.txt", std::ios::out);
	string username, role, line, pass;
	while(std::getline(File, line)){
		std::istringstream iss(line);
		getline(iss, username, ',');
		getline(iss, pass, ',');
		getline(iss, role, ',');

		User newUser(username, pass, role);

		string bookTitle;
		time_t dueDate;
		while(iss >> bookTitle >> dueDate){
			newUser.borrowedBooks[bookTitle] = dueDate;
		}
		Users.push_back(newUser);
	}
	File.close();
}

void Library::addBook(string title, string author, bool isReference){
	if(isReference){
		Shelf.push_back(new ReferenceBook(title, author));
	}else{
		Shelf.push_back(new Book(title, author));
	}
	saveToFile();
	cout << "Book added Successfully! " << "\n";
}

void Library::removeBook(string title){
	for (auto it = Shelf.begin(); it != Shelf.end(); ++it) {
		if ((*it)->getTitle() == title){
			delete *it;
			Shelf.erase(it);
			saveToFile();
			cout << "Book Removed Successfully.\n";
			return;
		}
	}
	cout << "Book Not Found.\n";
}

bool Library::borrowBook(User &user, string title){
	if(!user.canBorrow()){
		std::cout << "You have reached the borrowing limit (3 books).\n";
		return false;
	}
	if(user.hasBook(title)){
		std::cout << "You already borrowed this book.\n";
		return false;
	}
	for(auto book : Shelf){
		if(book->getTitle() == title){
			if(!book->bookAvailability()){ // Check reference book
				std::cout << "This is a reference book and cannot be borrowed.\n";
				return false;
			}

			
			book->borrowBook();
			user.borrowBook(title);
			saveToFile();
			std::cout << "Book borrowed successfully.\n";
			return true;
		}
	}
	std::cout << "Book not found or unavailable.\n";
	return false;
}

void Library::returnBook(User &user, string title){
	for(auto book : Shelf){
		if (book->getTitle() == title && book->statusBook() == true){
			if(user.returnBook(title)){
			book->returnBook();
			saveToFile();
			}
			return;
		}
	}
	std::cerr << "Book return failed." << '\n';
}

void Library::searchByKeyWord(string keyword){
	std::cout << "Searching the Books for keyword.." << keyword << "\n";
	bool found = false;
	for(auto book : Shelf){
		if(book->getTitle().find(keyword) != string::npos || book->getAuthor().find(keyword) != string::npos){
			book->DisplayInfo();
			found = true;
		}
	}
	if(keyword.empty()){
		std::cout << "Invalid search keyword.\n";
		return;
	}
}

void User::borrowBook(string title){
	if(borrowedBooks.size() >= borrowLimit){
		std::cout << "Borrowing limit reached! You can only borrow up to " << borrowLimit << " books.\n";
		return;
	}
	time_t now = time(0); // Current time as borrowing timestamp
	time_t duedate = now + (maxBorrowDays * 86400);
	borrowedBooks[title] = duedate;
	std::cout << "Book '" << title << " borrowed successfully!\n";
	std::cout << "Due date: " << ctime(&duedate);
}

bool User::returnBook(string title){
	auto it = borrowedBooks.find(title);
	if(it == borrowedBooks.end()){
		std::cout << "You don't have this book.\n";
		return false;
	}

	time_t now = time(0);
	if(now > it->second){ // Fix: Only charge if past due
		int daysLate = (now - it->second) / 86400;
		double fine = daysLate * lateFeePerDay;
		std::cout << "Book returned late! Fine: $" << fine << "\n";
	}

	borrowedBooks.erase(it);
	std::cout << "Book returned successfully.\n";
	return true;
}

void User::checkOverDueBook(){
	time_t now = time(0);
	bool overdueFound = false;

	std::cout << "Checking overdue books...\n";
	for (const auto &book : borrowedBooks){
		time_t dueDate = book.second;
		if(now > dueDate){
			overdueFound = true;
			int daysOverdue = (now - dueDate) / 86400; // Convert seconds to days
			double fine = daysOverdue * lateFeePerDay;
			std::cout << "Overdue: " << book.first << " | Days overdue: " << daysOverdue << " | Fine: $" << fine << "\n";
		}
	}
	if(!overdueFound){
		std::cout << "No overdue books!\n";
	}
}

//Junyu
int main(){
	Library library;
	User *loggedInUser = nullptr; // Stores the logged-in user

	while(true){
		int choice, option;
		string title, author, username, password, role;

		while(!loggedInUser){
			cout << "1. Register User\n2. Login User\n";
			cout << "Choice: ";

			if (!(cin >> option)){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input! Enter a number.\n";
				continue;
			}
			cin.ignore();

			switch (option){
			case 1: { // Register User
				cout << "Enter username: ";
				std::getline(cin, username);

				cout << "Enter password: ";
				std::getline(cin, password);

				cout << "Enter role (User/Librarian): ";
				getline(cin, role);

				if(role != "User" && role != "Librarian"){
					cout << "Invalid role! Must be 'User' or 'Librarian'.\n";
					break;
				}

				library.registerUser(username, password, role);
				cout << "User registered successfully!\n";
				break;
			}
			case 2: { // Login
				cout << "Enter username: ";
				getline(cin, username);
				cout << "Enter password: ";
				getline(cin, password);

				loggedInUser = library.authenticateUser(username, password);
				if(loggedInUser){
					cout << "Login successful! Welcome, " << loggedInUser->getUsername() << ".\n";
				}else{
					cout << "Invalid username or password.\n";
				}
				break;
			}
			default:
				break;
			}
		}

		while(loggedInUser){
			cout << "\n\nLibrary System:";
			cout << "\n1. Add Book\n2. Add Reference Book\n3. Remove Book\n4. Search Book\n5. Borrow Book\n6. Return Book\n7. Display Books\n"
					"8. Logout\n9. Exit\nChoice: ";

			if(!(cin >> choice)){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input! Enter a number.\n";
				continue;
			}
			cin.ignore(); // Clear newline from buffer

			switch(choice){
			case 1: // Add Book
			case 2: // Add Reference Book
			case 3: // Remove Book(Fallthrough)
				if(!loggedInUser || loggedInUser->getRole() != "Librarian"){
					cout << "Access denied! Only librarians can manage books.\n";
					break;
				}
				cout << "Enter title: ";
				getline(cin, title);
				if(choice == 1 || choice == 2){
					cout << "Enter author: ";
					getline(cin, author);
					library.addBook(title, author, choice == 2); // True for ReferenceBook
				}else{
					library.removeBook(title);
				}
				break;

			case 4: // Search Book
				cout << "Enter keyword to search: ";
				getline(cin, title);
				library.searchByKeyWord(title);
				break;

			case 5: // Borrow Book
			case 6: // Return Book
				if(!loggedInUser){
					cout << "Please log in first.\n";
					break;
				}
				cout << "Enter book title: ";
				std::getline(cin, title);
				if(choice == 5){
					library.borrowBook(*loggedInUser, title);
				}else{
					library.returnBook(*loggedInUser, title);
				}
				break;

			case 7: // Display Books
				library.Display();
				break;

			case 8: // Logout
			//After logging out will back to the login section above
				if(loggedInUser){
					cout << "Logged out successfully.\n";
					loggedInUser = nullptr;
				}else{
					cout << "You're not logged in.\n";
				}
				break;

			case 9: // Exit
				cout << "Exiting system...\n";
				return 0;

			default:
				cout << "Invalid choice!\n";
			}
		}
	}
}