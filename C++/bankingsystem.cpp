#include <cstdlib>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>


using std::cin;
using std::cout;
using std::string;
double balance;

void Greeting(string &choice){
  cout << "******** Welcome To Wealthy Bank ********" << "\n";
  cout << "Your action : " << choice << " . " << "\n";
}


void AccCreate(){
  srand((time(0)));
  string name;
  double deposit = 20;
  string type[2] ={"Savings", "Checking"};
  string confirmation;
  int op;
  string number;
  string pin;
  
  int accnum = rand() % 90000 + 10000;
  std::stringstream ss;
  ss << std::setw(5) << std::setfill('0') << accnum;
  string newaccnum = ss.str();

  cout << "Enter Your Name : ";
  std::getline(cin >> std::ws, name) ;
  cout << "A RM 20 Deposit is required if making an account. Type ok" << "\n";
  cin >> confirmation;
  if (confirmation != "ok") {
    cout << "Confirmation Canceled.";
    return;
  }
  cout << "Savings Account(0) or Checking Account(1)?";
  cin >> type[op];
  while (op != 0 && op != 1) {
  cout << "Invalid Choice! Please try again. : ";
  cin >> op;
  }
  cout << "Your Contact Number : ";
  cin >> number;
  cout << "Please set your account safety pin (4 Digits):";
  cin >> pin;while(pin.length() != 4 ){
    cout << "Invalid Pin Digits. Try Again. : ";
    cin >> pin;
  }
  cout << "Your Account Number : " << newaccnum << "\n";
  cout << "Your Account Type : " << type[op] << "\n";
}

bool validateaccount(string &accnum, string &pin, string &inputpin, string &inputnum){
  return(accnum == inputnum && pin == inputpin);
}
void checkbalance(const string &accnum, const string &pin, const string &inputpin, const string &inputnum){
  if (validateaccount(accnum , pin, inputpin , inputnum)) {
    cout << "Your Balance : " << balance << "\n";
  }else {
  cout << "Invalid Account Number!" << "\n";
  }
}
void deposit(string &accnum, string &pin, double &balance){
string inputaccnum , inputpin;
cout << "Enter account number: " << "\n";
cin >> inputaccnum;
cout << "Enter Your PIN: " << "\n";
cin >> inputpin;

if (validateaccount(accnum, pin, inputpin, inputnum)){
  double depositamount;
  cout << "Enter deposit amount: " << "\n";
  cin >> depositamount;
  balance += depositamount;
  cout << "Deposit Successful! Your updated balance is : " << balance << "\n";
}else {
cout << "Invalid account number or pin! " << "\n";
}
}

void withdraw(string &accnum, string &accountpin, double &balance){
  string inputnumber, inputpin;
  cout << "Enter account number: ";
  cin >> inputnumber;
  cout << "Enter Your PIN";
  cin >> inputpin;
  if (validateaccount(accnum,pin, inputpin, inputnum)) {
  
  double withdrawamount;
  cout << "Enter withdraw amount: ";
  cin >> withdrawamount;
  if(withdrawamount <= balance){
    balance -= withdrawamount;
    cout << "Withdrawal Successful! Your updated balance is: " << balance << "\n"; 
  }
}
}
int main() {
  const string banking[5] = {"Create an Account" , "Check Balance" , "Deposit" , "Withdrawal" , "Exit"};
  int choice;

    cout << "******** Welcome To Wealthy Bank ********" << "\n";
    cout << "(0) Create an Account" << "\n";
    cout << "(1) Check Balance" << "\n";
    cout << "(2) Deposit" << "\n";
    cout << "(3) Withdrawal" << "\n";
    cout << "(4) Exit" << "\n";
    cout << "Your Choice : ";
    cin >> choice;
    if(choice == 0){
      string action = banking[0];
      Greeting(action);
      AccCreate();
    } else if (choice == 1) {
      string action = banking[1];
      Greeting(action);
      checkbalance();
    } else if (choice == 2) {
      string action = banking[2];
      Greeting(action);
    } else if (choice == 3){
      string action = banking[3];
      Greeting(action);
    } else if (choice == 4) {
      string action = banking[4];
      Greeting(action);
    }
    
  return 0;
}