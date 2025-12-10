#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <ctime>

class Missions{
    private:
        std::vector<std::string> missionList;


    public:
        Missions(){
            missionList = {"Explore the ancient ruins", "Rescue the captured ally", "Retrieve the lost artifact"};
        }

        void updateUser(){
            std::cout << "Available Missions:\n";
            std::srand(std::time(0));
            for(const auto& mission : missionList){
                if(std::rand() % 2){
                    std::cout << "- " << mission << "\n";
                }
            }
        }
};


int main(){
    Missions missions;
    for(int i = 0; i < 1000 ; i++){
        missions.updateUser();
    }

    return 0;
}