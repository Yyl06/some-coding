#include <iostream>
using std::string, std::cout, std::cin;

class Inventory{
    string type;
    string status;

    public:
    Inventory(string t,string s) : type(t), status(s){}
};

class Manager{
    string Name;
    int ID;
    int phoneNo;
    string location;
    Inventory *Store;

    public:
    Manager(string n, int id, int num, string loc) : Name(n), ID(id), phoneNo(num), location(loc){}
    void PurchaseInventory() { std::cout << "Inventory purchased by " << Name << '\n'; }
    void RecordComplaints() { std::cout << "Complaint recorded." << '\n'; }
    void ManageStaff() { std::cout << "Staff managed by " << Name << '\n'; }
};

class Rooms{
    int RoomNo;
    string Location;

    public:
        Rooms(int num, string loc) : RoomNo(num), Location(loc){
            cout << "Room Number: " << RoomNo << "\n";
        }
        int getRoomNumber() { return RoomNo; }
        string getLocation() { return Location; }
};

class Bill{
    int Billno;
    string GuestName;

    public:
        Bill(int num, string name) : Billno(num), GuestName(name){
            cout << "Bill No: " << num << '\n';
            cout << "Guest Name: " << name << "\n";
        }
};

class Receptionist{
    string Name;
    int ID;
    int PhoneNo;
    string location;

    public:
    Receptionist(string n , int id, int num, string loc) : Name(n), ID(id), PhoneNo(num), location(loc){}

    bool CheckRoomAvailability(){
        return true;
    }
    Rooms BookRoom(int RoomNo, string Loc){
        cout << "Room booked sucessfully!\n";
        return Rooms(RoomNo, Loc);
    }
    Bill GenerateBill(string name){
        return Bill(1001, name);
    }
    void AcceptCustomerFeedback(string &feedback){
        std::cout << "Customer Feedback: " << feedback << '\n';
    }
    string getName() { return Name; }
};

class Foods{
    int id;
    string Name;

    public:
        Foods(int id, string name) : id(id), Name(name){
            std::cout << "Order ID: " << id << "\n";
            std::cout << "Ordered: " << name << "\n";
        }
};

class Chef{
    string Name;
    int id;
    string location;

    public:
    Chef(string name, int id, string loc) : Name(name), id(id), location(loc){}

    void takeOrders(int code, string Foodname){
        Foods Order(code , Foodname);
    }
};

class Housekeeping{
    string name;
    int id;
    string location;

    public:
        Housekeeping(string name, int id, string loc) : name(name), id(id), location(loc){}

        void CleanRoom(){
            cout << "Room cleaned by: " << name << '\n';
        }
};

class Guest{
    string Name;
    int id;
    int PhoneNo;
    string address;
    int RoomNo;
    Receptionist* Helper;
    Chef* chef;
    Housekeeping* housekeeper;

    public:
    Guest(string n, int id, int num, string a, int roomnum, Receptionist* helper, Chef* c, Housekeeping* h)
    : Name(n), id(id), PhoneNo(num), address(a), RoomNo(roomnum), Helper(helper), chef(c), housekeeper(h) {}

    void checkIn(){
        if(Helper->CheckRoomAvailability()){
            Helper->BookRoom(this->RoomNo, "Hotel Suite");
        }
    }
    void checkOut(){
        std::cout << "Checking Out..\n";
        Helper->GenerateBill(Name);
    }
    void payBill(){
        std::cout << Name << " had paid the bill.\n";
    }
    void OrderFood(string Foodname){
        chef->takeOrders(1, Foodname);
    }
    void submitFeedback(string &feedback){
        std::cout << "Your Feedback: ";
        std::getline(cin, feedback);
        Helper->AcceptCustomerFeedback(feedback);
    }
};

int main() {
    Receptionist john("John Smith", 101, 5551234, "Lobby");
    Chef mike("Mike Gordon", 301, "Kitchen");
    Housekeeping sarah("Sarah Lee", 401, "Service Wing");
    Guest alice("Alice Brown", 202, 9876543, "NY Street", 12, &john, &mike, &sarah);

    string food = "Pasta";
    string feedback;
    alice.checkIn();
    alice.OrderFood("Pasta");
    alice.checkOut();
    alice.payBill();
    alice.submitFeedback(feedback);
    return 0;
}