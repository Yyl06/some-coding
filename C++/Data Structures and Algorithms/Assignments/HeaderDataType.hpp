/* ----------------- Lab Skill 2----------------------------
Section : 44
Name : YONG YUAN LIN
No Matric Card : A24DW0325
Topic : Stack
------------------------------------------------------------- */

#include <string>
using std::string;

//Data type of the linked list of Stack
#ifndef DATA_H
#define DATA_H

typedef struct Library{
    string datas;
    Library * Next;

    Library(string data){
        this->datas = data;
        this->Next = nullptr;
    }
}Librarys;

#endif //DATA_H