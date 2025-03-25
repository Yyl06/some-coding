#include <iostream>
using namespace std;

class Engine {
public:
    string type;
    
    Engine(string t) { type = t; }

    void start() {
        cout << "Engine (" << type << ") is starting...\n";
    }
};

class Car {
private:
    Engine engine; // Composition: Car owns Engine

public:
    Car(string engineType) : engine(engineType) {} // Engine is created with Car

    void startCar() {
        cout << "Car is starting...\n";
        engine.start(); // Engine exists only as part of Car
    }
};

int main() {
    Car myCar("V8"); // Engine is created with the Car
    myCar.startCar();

    return 0;
}
