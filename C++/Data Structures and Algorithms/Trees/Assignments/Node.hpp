#ifndef NodeBT_hpp
#define NodeBT_hpp

typedef struct Node{
    int data;
    Node* Left;
    Node* Right;

    Node(int data){
        this->data = data;
        this->Left = this->Right = nullptr;
    }
}Nodes;

#endif