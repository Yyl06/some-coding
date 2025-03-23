#include <iostream>
#include <string>
using std::string;

typedef struct Queue{
    string data;
    Queue *Next;

    Queue(string data){
        this->data = data;
        this->Next = nullptr;
    }
}Queues;

class QueueList{
    private:
        Queues *front, *rear;
        int size;
        const int MaximumSize = 10;
        bool status;
    
    public:
        QueueList(){
            this->front = this->rear = nullptr;
            this->size = 0;
        }

        //Adding Data to the Queue, Front is the first element and Rear is the last element
        void Enqueue(string data){
            Queues *NewQueue = new Queue(data);
            if(rear == nullptr){
                front = rear = NewQueue;
                size++;
                return;
            }else{
                rear->Next = NewQueue;
                rear = NewQueue;
                size++;
                return;
            }
        }

        //Removing Data from the Queue, the first element is removed
        void Dequeue(string &data){
            if(front == nullptr){
                std::cerr << "Queue Underflow." << "\n";
                data = "";
                return;
            }else{
                // We Need to Traverse the Queue to find the book to be removed
                Queues *temp = front, *previous = nullptr;
                while (temp != nullptr && temp->data != data) {
                    previous = temp;
                    temp = temp->Next;
                }
                if (temp == nullptr){
                    std::cerr << "Book not found in queue.\n";
                    return;
                }
                // If book to be removed is the top,1st element
                if (temp == front){
                    front = front->Next;
                    if (front == nullptr) rear = nullptr; // If removed book was the only element
                }else{
                    previous->Next = temp->Next;
                    if (temp == rear) rear = previous; // If removed book was the last element
                }
                delete temp;
                size--;
                std::cout << "Book Borrowed Successfully! " << "\n";
                return;
            }
        }

        //Peek the first element in the Queue
        string PeekFront(){
            return front ? front->data : "No Books Available.";
        }

        //Peek the last element in the Queue
        string PeekRear(){
            return rear ? rear->data : "No Books Available.";
        }

        bool isEmpty(){
            return front == nullptr;
        }

        //Size of the Queue
        int getSize(){
            return size;
        }

        void Display(){
            Queues *temp = front;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->Next;
            }
            std::cout << "\n";
        }

        void DefaultInitiallizeBooks(){
            string books[10] = {"Harry Potter", "The Alchemist", "The Da Vinci Code", "The Great Gatsby", "The Catcher in the Rye", "The Hobbit", "The Lord of the Rings", "The Chronicles of Narnia", "The Hunger Games", "The Fault in Our Stars"};
            for(int i = 0 ; i < 10 ; i++){
                Enqueue(books[i]);
            }
        }
};

int main(){
    int x, choice;
    const int Counters = 2;
    string repeat;
    QueueList *queue = new QueueList[Counters];

    for(int i = 0; i < Counters; i++){
        queue[i].DefaultInitiallizeBooks();
    }

    std::cout << "Enter Numbers of People on the Queue(Maximum 10): ";
    std::cin >> x;
    if(x > 10){
        std::cerr << "Queue Overflow." << "\n";
        return -1;
    }else{
        for(int i = 0; i < x; i++){
            do{
            std::cout << "1. Enqueue\n";
            std::cout << "2. Dequeue\n";
            std::cout << "3. Next Book In The Queue\n";
            std::cout << "4. Last Book In The Queue\n";
            std::cout << "5. Check the Remaining Size of the Queue\n";
            std::cout << "6. Display the Queue of Remaining Books\n";
            std::cout << "7. Check the Book Status\n";
            
            std::cout << "Queue: Person Number " << i + 1 << "\n";
            std::cout << "Enter Your Choice: ";
            std::cin >> choice;
            std::cin.ignore();
            string data, dequeuedData;

            
                switch(choice){
                case 1:
                    std::cout << "Enter The Book Name You Want To Return: ";
                    std::getline(std::cin, data);
                    queue->Enqueue(data);
                    break;

                case 2:
                    std::cout << "Enter The Book Name You Want To Borrow: ";
                    std::getline(std::cin, dequeuedData);
                    queue->Dequeue(dequeuedData);
                    break;

                case 3:
                    std::cout << "The First Book in the Queue is: " << queue->PeekFront() << "\n";
                    break;

                case 4:
                    std::cout << "The Last Book in the Queue is: " << queue->PeekRear() << "\n";
                    break;

                case 5:
                    std::cout << "The Size of the Queue is: " << queue->getSize() << "\n";
                break;

                case 6:
                    std::cout << "The Queue of Remaining People: ";
                    queue->Display();
                    break;

                case 7:
                    std::cout << "The Book Status is: " << (queue->isEmpty() ? "Empty" : "Not Empty") << "\n";
                    break;

                default:
                    std::cerr << "Invalid choice. Please try again." << "\n";
                    break;
                }
                std::cout << "Do you want to repeat the process? (Y/N): ";
                std::cin >> repeat;
            }while(repeat == "Y" || repeat == "y");
        }
    }
    delete [] queue;
    return 0;
}