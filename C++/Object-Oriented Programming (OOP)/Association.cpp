#include <iostream>
using std::string;

class Patient;  // Forward declaration

class Doctor {
    public:
        string name;

        Doctor(string n) { name = n; }
        void treatPatient(Patient &p);
};

class Patient {
    public:
        string name;

        Patient(string n) { name = n; }
};

int main() {
    Doctor d1("Smith");
    Patient p1("John");

    d1.treatPatient(p1);  // Association: Loose relationship
    return 0;
}
