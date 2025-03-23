#include <iostream>
#include <fstream>
#include <string>
using std::string;

void AddFile(const std::string& recordFile, const std::string& record) {
    std::ofstream outFile(recordFile, std::ios::app);
    if (outFile) {
        outFile << record << "\n";
        std::cout << "Record added successfully.\n";
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
    outFile.close();
}

void SearchFile(const std::string& recordFile, const std::string& keyword) {
    std::ifstream inFile(recordFile);
    std::string line;
    bool found = false;

    if (inFile) {
        while (std::getline(inFile, line)) {
            if (line.find(keyword) != std::string::npos) {
                std::cout << "Found: " << line << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "No matching record found.\n";
    } else {
        std::cerr << "Error: Unable to open file for reading.\n";
    }
    inFile.close();
}

void RemoveFile(const std::string& recordFile, const std::string& keyword) {
    std::ifstream inFile(recordFile);
    std::ofstream tempFile("temp.txt");
    std::string line;
    bool deleted = false;

    if (inFile && tempFile) {
        while (std::getline(inFile, line)) {
            if (line.find(keyword) == std::string::npos) {
                tempFile << line << "\n";
            } else {
                deleted = true;
            }
        }
        inFile.close();
        tempFile.close();

        // Replace original file with temp file
        if (deleted) {
            std::remove(recordFile.c_str());
            std::rename("temp.txt", recordFile.c_str());
            std::cout << "Record deleted successfully.\n";
        } else {
            std::remove("temp.txt");
            std::cout << "No matching record found to delete.\n";
        }
    } else {
        std::cerr << "Error: Unable to open file.\n";
    }
}

void Display(const string &recordFile){
    std::ifstream InFile(recordFile);
    string line;

    if(InFile){
        while(std::getline(InFile , line)){
            std::cout << "All Elements :" << "\n";
            std::cout << line << "\n";
        }
    }else{
        std::cerr << "Unable to Detect File Directory." << "\n";
    }
    InFile.close();
}

int main() {
    std::string fileName = "Records.txt";
    int choice;
    std::string record, keyword;

    do {
        std::cout << "\nStudent Record System\n";
        std::cout << "1. Add Record\n";
        std::cout << "2. Search Record\n";
        std::cout << "3. Delete Record\n";
        std::cout << "4. Display All Records\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // Clear input buffer
        switch (choice) {
            case 1:
                std::cout << "Enter record (format: Name,ID,Department): ";
                std::getline(std::cin, record);
                AddFile(fileName, record);
                break;
            case 2:
                std::cout << "Enter keyword to search: ";
                std::getline(std::cin, keyword);
                SearchFile(fileName, keyword);
                break;
            case 3:
                std::cout << "Enter keyword to delete: ";
                std::getline(std::cin, keyword);
                RemoveFile(fileName, keyword);
                break;
            case 4:
                Display(fileName);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}