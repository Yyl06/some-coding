#include <iostream>
#include <sstream>
#include <string>
using std::string;

int main(){
    string studentName, courseName, icNumber, regYear, courseShort = "";

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, studentName);

    std::cout << "Enter IC Number(Without Dash -): ";
    std::cin >> icNumber;
    if(icNumber.length() != 12){
        std::cout << "Invalid IC Number\n";
        return -1;
    }

    std::cout << "Enter Course Name: ";
    std::cin.ignore();
    std::getline(std::cin, courseName);


    std::cout << "Enter Registration Year: ";
    std::cin >> regYear;

    std::cout << "\nThe following are the details of the student: -\n";
    std::cout << "Student Name: " << studentName << "\n";
    std::cout << "IC Number: " << icNumber << "\n";
    std::cout << "Course Name: " << courseName << "\n";
    std::cout << "Registration Year: " << regYear << "\n";

    std::stringstream ss(courseName);
    string temp;
    while(ss >> temp){
        courseShort += temp[0];
    }

    string digit2Year = regYear.substr(regYear.length()- 2);

    string StudentID = courseShort + digit2Year + "00" + icNumber.substr(icNumber.length()- 4);

    std::cout << "Student ID: " << StudentID << "\n";

    return 0;
}