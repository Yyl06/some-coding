#include <iostream>
#include <memory>
#include <new>

typedef struct Node{
    int data;
    std::shared_ptr<Node> Next;

    Node(int data){
        this->data = data;
        this->Next = nullptr;
    }
}Nodes;

class List{
    private:
        std::shared_ptr<Node> Head;
        std::shared_ptr<Node> Tail;
        int size;

    public:
        List(){
            Head = nullptr;
            Tail = nullptr;
            size = 0;
        }

        void Add(int data){
            try{
            std::shared_ptr<Node> NewNode = std::make_shared<Node>(data);
            if(Head == nullptr){
                Head = NewNode;
                Tail = NewNode;
            }else{
                Tail->Next = NewNode;
                Tail = NewNode;
            }
            size++;
            }catch(std::bad_alloc &){
                std::cerr << "Memory Allocation Failed." << "\n";
            }
        }

        void Remove(int data){
            std::shared_ptr<Node> Current = Head;
            std::shared_ptr<Node> Previous = nullptr;
            while(Current != nullptr){
                if(Current->data == data){
                    if(Previous == nullptr){
                        Head = Current->Next;
                    }else{
                        Previous->Next = Current->Next;
                    }
                }else{
                    Previous = Current;
                    Current = Current->Next;
                }
            }
            return;
        }

        void Display(){
            std::shared_ptr<Node> Current = Head;
            while(Current != nullptr){
                std::cout << Current->data << " ";
                Current = Current->Next;
            }
            std::cout << "\n"; 
        }
};

int main(){
    List list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Display();
    list.Remove(3);
    list.Display();

    return 0;
}