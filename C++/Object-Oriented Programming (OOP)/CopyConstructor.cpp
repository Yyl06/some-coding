#include <cstring>
#include <iostream>

class PersonInfo{
    private:
    char *name;
    int age;
    
    public:
    PersonInfo(const char *n, int a){
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        this -> age = a;
    }
    
    //Copy constructor
    PersonInfo(const PersonInfo &obj){
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        age = obj.age;
    }
    
    ~PersonInfo(){
        delete [] name;
    }

    const char *GetName(){
        return name;
    }
};

int main(){
    PersonInfo person1("John", 25);
    PersonInfo person2 = person1;

    std::cout << "Person 1: " << person1.GetName() << std::endl;
    std::cout << "Person 2: " << person2.GetName() << std::endl;

    person1.~PersonInfo();
    std::cout << "Person 1: " << person1.GetName() << std::endl;
    std::cout << "Person 2: " << person2.GetName() << std::endl;
    
    return 0;
}