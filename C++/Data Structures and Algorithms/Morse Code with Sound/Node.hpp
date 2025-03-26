#ifndef Node_h //If not defined Node_h
#define Node_h //Define Node_h
#include <string>
//Yong hern part
typedef struct Node{
    std::string Morse; //use string since morse code contains alphabet letters
    Node *Left; //AVL Trees contain Left node and Right node
    Node *Right;
    char data; //Morse code reads chars instead of strings one by one
    int height; //AVL Tree needed element for self balancing

    //Constructor that modifies member variables
    Node(std::string M, char d) : Morse(M), Left(nullptr), Right(nullptr), data(d), height(1) {}
}AVLNode;

#endif