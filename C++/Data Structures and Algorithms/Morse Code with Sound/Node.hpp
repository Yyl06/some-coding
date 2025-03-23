#ifndef Node_h
#define Node_h
#include <iostream>
using std::string;

typedef struct Node{
    string Morse;
    Node *Left;
    Node *Right;
    char data;
    int height;

    Node(string M, char d) : Morse(M), Left(nullptr), Right(nullptr), data(d), height(1) {}
}AVLNode;

#endif