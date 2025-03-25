#include <iostream>
using namespace std;

class Professor {
public:
    string name;
    Professor(string n) { name = n; }
};

class University {
public:
    string uniName;
    Professor* professors[5]; // Aggregation: University "has" Professors
    int count;
    static const int SIZE;

    University(string n) : uniName(n), count(0) {}

    void addProfessor(Professor* p);
    void showProfessors();
};

const int University::SIZE = 5;

void University::addProfessor(Professor* p) {
    if (count < SIZE) {
        professors[count] = p;
        count++;
    }
}

void University::showProfessors() {
    cout << "Professors in " << uniName << ":\n";
    for (int i = 0; i < count; i++)
        cout << "- " << professors[i]->name << endl;
}

int main() {
    Professor p1("Dr. Gray"), p2("Dr. Black");
    University u("University Teknologi Malaysia");

    u.addProfessor(&p1); // University references professors but does not own them
    u.addProfessor(&p2);

    u.showProfessors(); // Aggregation: Professors exist even if University is deleted

    return 0;
}
