// Definition of a Node in a singly linked list
#include <iostream>

struct Name{
    int data;
    Name * Next;

//A Constructor to initialize the data of the node
Name (int data){
    this->data = data;
    this->Next = nullptr;
}
};

// C++ Function to traverse and print the elements of the linked list
//Starting from the head of the linked list
//The function traverses the linked list and prints the data of each node until reaching the end of the linked list.
void traverseLinkedList(Name* head){
    // Start from the head of the linked list
    Name* current = head;

    // Traverse the linked list until reaching the end
    // (nullptr)
    //The function traverses the linked list and prints the data of each node until reaching the end of the linked list.
    while (current != nullptr) {
        
        // Print the data of the current node
        std::cout << current->data << " ";

        // Move to the next node
        current = current->Next;
    }

    std::cout << std::endl;
}

int main(){
    // Create a linked list with three node
    //Arrow Operator is used to access the members of a structure using a pointer variable. Syntax : Pointer -> Member
    Name* head = new Name(1);
    head->Next = new Name(2);
    head->Next->Next = new Name(3);

    // Traverse and print the linked list
    traverseLinkedList(head);

    return 0;
}