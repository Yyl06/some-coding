#ifndef DATA_H
#define DATA_H
typedef struct DataLibrarys{
    int number;
    DataLibrarys *next;

    DataLibrarys(int number){
        this->number = number;
        this->next = nullptr;
    }
}DataLibrary;

#endif