#include <iostream>
using std::string;

class Character{
    protected:
        string name;
        unsigned int health , attack , defence;
        string roles;

    public:
        Character(string n, unsigned int h , unsigned int atk, unsigned int def) : name(n), health(h), attack(atk), defence(def) {};

        virtual void Attacks(){
            std::cout << name.c_str() << " Uses Attack! " << "\n";
        }

        void DisplayStats(){
            std::cout << "Character Name: " << name.c_str() << "\nHealth: " << health << "\nAttack: " << attack << "\nDefence: " << defence << "\n";
        }

        void AttackEnemy(Character &enemy){
            int damage = attack - enemy.defence;
            if(damage < 0){
                damage = 0;
            }
            enemy.health -= damage;

            std::cout << name.c_str() << " Attacks Enemy for: " << damage << "\n";
        }

        bool isAlive(){
            return health > 0;
        }
};

//Warrior Role Derived Class
class Warrior : public Character{
    public:
    Warrior(string n) : Character(n, 150, 65, 100){}
        void Attacks() override{
            std::cout << name.c_str() << " Deals Slashes!" << "\n";
        }
};

//Mage Role Derived Class
class Mage : public Character{
    public:
    Mage(string n) : Character(n , 100, 60, 60){}
    void Attacks() override{
        std::cout << name.c_str() << " Chanted Spells! Dealt Damage!" << "\n";
    }
};

//Rogue Role Derived Class
class Rogue : public Character{
    public:
    Rogue(string n) : Character(n, 80, 105, 30){}
    void Attacks() override{
        std::cout << name.c_str() << " Dealt Massive Single Damage!" << "\n";
    }
};