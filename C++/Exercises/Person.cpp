#include <iostream>

class Teacher{
    public:
        void Teach(){
            std::cout << "Teaching Students..." << "\n";
        }
};

class Researcher{
    public:
        void Research(){
            std::cout << "Conducting Research..." << "\n";
        }
};

class Professor : public Teacher, public Researcher{
    public:
        void Actions(){
            Teach();
            Research();
        }
};

int main(){
    Professor Teach;
    Teach.Actions();
    return 0;
}