#include <iostream>
#include <string>
using std::string;

typedef struct QUeue{
    string data;
    QUeue *Next;

    QUeue(string data){
        this->data = data;
        this->Next = nullptr;
    }
}Queue;

class Queues{
    Queue *front, *rear;
    int size;
    
    public:
        Queues(){
            this->front = this->rear = nullptr;
            this->size = 0;
        }

        bool isEmpty(){
            return front == nullptr;
        }

        bool Enqueue(string data){
            if(!isEmpty()){
                return false;
            }else{
                Queue *NewQueue = new Queue(data);
                NewQueue->data = data;
                NewQueue->Next = nullptr;
                if(rear == nullptr && front == nullptr){
                    front = rear = NewQueue;
                    size++;
                    return true;
                }else{
                    rear->Next = NewQueue;
                    rear = NewQueue;
                    size++;
                    return true;
                }
            }
            return false;
        }

        bool Dequeue(string *data){
            Queue *temp;
            if(isEmpty()){
                std::cerr << "Queue Underflow." << "\n";
                return false;
            }else{
                data = &front->data;
                temp = front;
            }

        }
};