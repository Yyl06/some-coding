#ifndef DATA_hpp
#define DATA_hpp
#include "Node.hpp"
#include <thread>
#include <chrono>
#include <windows.h>
#include <sstream>
using std::string, std::max;

const int DotDuration = 150;
const int DashDuration = DotDuration * 3;
const int LetterGap = DotDuration * 3;
const int WordGap = DotDuration * 7;
const int ElementGap = DotDuration;

class Morse{
    int getHeight(AVLNode *Node){
        return Node ? Node->height : 0;
    }

    int getBalance(AVLNode *Node){
    return Node ? getHeight(Node->Left) - getHeight(Node->Right) : 0;
    }

    AVLNode *Root;
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* Insert(AVLNode* node, char letter, string morse);
    string searchMorse(AVLNode* node, char letter);

    public:
        Morse(){
            this->Root = nullptr;
        }

        void Insert(char letter, string Morse){
            Root =Insert(Root, letter, Morse);
        }
        string getMorse(char letter){ return searchMorse(Root, letter); }
        void BuildTree();
        string textToMorse(string text);
        void playMorseSound(const string &Morse);
};

inline AVLNode *Morse::rotateRight(AVLNode *y){
    AVLNode *x = y->Left;
    AVLNode *T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    y->height = max(getHeight(y->Left), getHeight(y->Right)) + 1;
    x->height = max(getHeight(x->Left), getHeight(x->Right)) + 1;

    return x;
}

inline AVLNode *Morse::rotateLeft(AVLNode *x){
    AVLNode *y = x->Right;
    AVLNode *T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    y->height = max(getHeight(y->Left), getHeight(y->Right));
    x->height = max(getHeight(x->Left), getHeight(x->Right));

    return y;
}

inline AVLNode *Morse::Insert(AVLNode *Node, char letter, string Morse){
    if(!Node){
        return new AVLNode(Morse, letter);
    }
    if(letter < Node->data){
        Node->Left = Insert(Node->Left, letter, Morse);
    }else if(letter > Node->data){
        Node->Right = Insert(Node->Right, letter, Morse);
    }else{
        return Node;
    }
    Node->height = 1 + max(getHeight(Node->Left), getHeight(Node->Right));
    int balance = getBalance(Node);
    if(balance > 1 && letter < Node->Left->data){
        return rotateRight(Node);
    }
    if(balance < -1 && letter > Node->Right->data){
        return rotateLeft(Node);
    }
    if(balance > 1 && letter > Node->Left->data){
        Node->Left = rotateLeft(Node->Left);
        return rotateRight(Node);
    }
    if(balance < -1 && letter < Node->Right->data){
        Node->Right = rotateRight(Node->Right);
        return rotateLeft(Node);
    }
    return Node;
}

inline string Morse::searchMorse(AVLNode *Node, char letter){
    if(!Node){
        return "";
    }else{
        if(Node->data == letter){
            return Node->Morse;
        }
    }
    return (letter < Node->data) ? searchMorse(Node->Left, letter) : searchMorse(Node->Right, letter);
}

inline string Morse::textToMorse(string text){
    string Morse = "";
    for(char c : text){
        c = toupper(c);
        string code = getMorse(c);
        if(!code.empty()){
            Morse += code + " ";
        }
    }
    return Morse;
}

inline void Morse::playMorseSound(const string& Morse) {
    for(size_t i = 0; i < Morse.length(); i++){
        char c = Morse[i];
        if(c == '.'){
            Beep(800, DotDuration);
            std::this_thread::sleep_for(std::chrono::milliseconds(ElementGap));
        } else if(c == '-'){
            Beep(800, DashDuration);
            std::this_thread::sleep_for(std::chrono::milliseconds(ElementGap));
        } else if(c == ' '){
            if(i + 1 < Morse.length() && Morse[i + 1] == ' '){
                std::this_thread::sleep_for(std::chrono::milliseconds(WordGap - ElementGap));
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(LetterGap - ElementGap));
            }
        }
    }
}

#endif