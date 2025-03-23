#include <iostream>
/*
class Name{
    private:
        int data;

    public:
        Name(int value) : data(value) {};

        friend void displayData(const Name &value);
};

void displayData(const Name &value){
        std::cout << "Data: " << value.data << "\n";
}

int main(){
    int value = 10;

    Name Names(value);
    displayData(Names);
    
    return 0;
}*/
/*
class ClassA;

class ClassB{
    public:
        void showData(const ClassA &value);
};

class ClassA{
        private:
        int PrivData;
    
    public:
        ClassA(int value) : PrivData(value) {};

        friend void ClassB::showData(const ClassA &value);
};

void ClassB::showData(const ClassA &value){
    std::cout << "Private Data of A : " << value.PrivData << "\n";
}

int main(){
    int value = 15;
    ClassA obja(value);
    ClassB objB;

    objB.showData(obja);
}*/

class B;

class A{
    private:
        int num1;

        friend class B;

    public:
        A(){num1 = 12;};
};

class B{
    private:
        int num2;

    public:
        B(){num2 = 1;};

    int add(){
        A objA;
        return objA.num1 + num2;
    }
};

int main(){
    B objB;
    std::cout << "Sum: " << objB.add();
    return 0;
}