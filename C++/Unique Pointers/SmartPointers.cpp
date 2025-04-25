#include <iostream>
#include <memory>
//Why smart pointers? Fuck "new" and "delete"🤣it shits to manage memory manually

//Unique Pointers, when it is out of scope the "delete" keyword is called automatically
//Shared Pointers, is used for shared ownership of an object.
//Weak Pointers, an unowning observer of Shared Pointers, it does not increase the reference count.
//Weak Pointers prevent cycles from memory which may cause memory leaks->Segfault

class Entity{
    public:
        Entity(){
            std::cout << "Entity Created" << "\n";
        }
        ~Entity(){
            std::cout << "Entity Destroyed" << "\n";
        }

        void Print(){
            std::cout << "Hello World" << "\n";
        }
};

int main(){
    //Unique Pointer
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    entity->Print();

    //Shared Pointer
    std::shared_ptr<Entity> e1;
    {
        std::shared_ptr<Entity> sEntity = std::make_shared<Entity>();
        //Weak Pointers
        std::weak_ptr<Entity> wEntity = sEntity;
        e1 = sEntity;
    }
    std::unique_ptr<Entity> e3 = std::make_unique<Entity>();
    e3->Print();
    return 0;
}