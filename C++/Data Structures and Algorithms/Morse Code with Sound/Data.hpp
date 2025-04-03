#ifndef DATA_hpp
#define DATA_hpp
#include "Node.hpp"
#include <thread>
#include <chrono>
#include <windows.h>
using std::string, std::max;

const int DotDuration = 200;
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

        void BuildTree() {
            string morseCodes[27] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                    "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
                                    
            char letters[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                                'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
        
            for (int i = 0; i < 27; i++) {
                Insert(letters[i], morseCodes[i]);
            }
}
        
        void Insert(char letter, string Morse){
            Root =Insert(Root, letter, Morse);
        }
        string getMorse(char letter){ return searchMorse(Root, letter); }
        string textToMorse(string text);
        void playMorseSound(const string &Morse);
        char searchCharacter(AVLNode *node, const string &morseSymbol);
        string morseToText(const string &morse);
};

inline AVLNode *Morse::rotateRight(AVLNode *y){
    if (!y || !y->Left) return y;
    AVLNode *x = y->Left;
    AVLNode *T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    y->height = max(getHeight(y->Left), getHeight(y->Right)) + 1;
    x->height = max(getHeight(x->Left), getHeight(x->Right)) + 1;

    return x;
}

inline AVLNode *Morse::rotateLeft(AVLNode *x){
    if (!x || !x->Right) return x;
    AVLNode *y = x->Right;
    AVLNode *T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    x->height = max(getHeight(x->Left), getHeight(x->Right)) + 1;
    y->height = max(getHeight(y->Left), getHeight(y->Right)) + 1;

    return y;
}

inline AVLNode *Morse::Insert(AVLNode *Node, char letter, string Morse) {
    if (!Node) {
        return new AVLNode(Morse, letter);
    }

    if (letter < Node->data) {
        Node->Left = Insert(Node->Left, letter, Morse);
    } else if (letter > Node->data) {
        Node->Right = Insert(Node->Right, letter, Morse);
    } else {
        return Node; // Duplicate letters are not inserted
    }

    Node->height = 1 + max(getHeight(Node->Left), getHeight(Node->Right));

    int balance = getBalance(Node);

    // **LEFT-LEFT (LL) CASE**
    if (balance > 1 && getBalance(Node->Left) >= 0) {
        return rotateRight(Node);
    }

    // **RIGHT-RIGHT (RR) CASE**
    if (balance < -1 && getBalance(Node->Right) <= 0) {
        return rotateLeft(Node);
    }

    // **LEFT-RIGHT (LR) CASE**
    if (balance > 1 && getBalance(Node->Left) < 0) {
        Node->Left = rotateLeft(Node->Left);
        return rotateRight(Node);
    }

    // **RIGHT-LEFT (RL) CASE**
    if (balance < -1 && getBalance(Node->Right) > 0) {
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

inline void Morse::playMorseSound(const string &Morse){
    for(char c : Morse){
        if(c == '.'){
            Beep(800, DotDuration);
            std::this_thread::sleep_for(std::chrono::milliseconds(ElementGap));
        }else if(c == '-'){
            Beep(800, DashDuration);
            std::this_thread::sleep_for(std::chrono::milliseconds(ElementGap));
        }else if(c == ' ' && (c == 0 || Morse[c - 1] != ' ')){
            std::this_thread::sleep_for(std::chrono::milliseconds(LetterGap));
        }else if(c == '/' && (c == 0 || Morse[c - 1] != '/')){
            std::this_thread::sleep_for(std::chrono::milliseconds(WordGap));
        }else{
            std::this_thread::sleep_for(std::chrono::milliseconds(ElementGap));
        }
    }
}

#endif