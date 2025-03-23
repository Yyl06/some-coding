#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using std::string;
//data.h
typedef string str;

//node.h
typedef struct BOOKCASE{
    str user;
    BOOKCASE *next;
    BOOKCASE(str name){
        this -> user = name;
        this -> next = nullptr;
    };
        }b_case;
    
#endif // !NODE_H

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>

class counter{
    private:
    b_case *front;
    b_case *rear;
    int size;
    const int maxSize = 10;

    public:
    counter(){
        front = rear = nullptr;
        this -> size  = 0;
    }


    bool enqueue(str dataIN){
        b_case *newB = new b_case(dataIN);
        if (isEmpty()){
            front = newB;
            rear = newB;
            size++;
            return true;
        }else if (maxSize >= size){
            std::cout << "already full" << std::endl;
            return false;
        }else{
            newB -> next = front;
            rear = newB;
            size ++;
            return true;
        }
    }

    bool dequeue(str &dataOUT){
        if (isEmpty()){
            std::cout << "this queue already empty" << std::endl;
            return false;
        }
        b_case *temp = front;
        front = front -> next;
        delete(temp);
        return true;
    }

    str peekFront(){
        if (isEmpty()){
            return "";
        }else{
            return front->user;
        }
    }

    str peekRear(){
        if (isEmpty()){
            return "";
        }else{
            return rear->user;
        }
    }

    int getSize(){
        return size;
    }

    void display(){
        b_case *temp = front;
        
        if (isEmpty()){
            std::cout << "this queue is empty" << std::endl;
        }
        
        while (front != NULL){
            std::cout << front -> next<<", "<< std::endl;
            temp = temp -> next;
        }
        std::cout<<std::endl;
    }   

    bool isEmpty(){
        if (front == NULL){
            return true;
        }else{
            return false;
        }
    }
};

#endif // !QUEUE.H