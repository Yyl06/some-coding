#include <iostream>
#include <cctype>
#include <string>
using std::string;

int charToInt(char c){
    return toupper(c) - 'A';
}

char intToChar(int c){
    return 'A' + (c % 26);
}

string Encrypt(const string &text, const string &key){
    string result = "";
    int keyLen = key.length();
    int textLen = text.length();

    for(int i = 0; i < textLen ; i++){
        if(isalpha(text[i])){
            int p = charToInt(text[i]);
            int k = charToInt(key[i % keyLen]);
            int c = (p + k) % 26;
            result += intToChar(c);
        }else{
            result += text[i];
        }
    }
    return result;
}

string decrypt(const string &cipher, const string &key){
    string result = "";
    int keyLen = key.length();
    int textLen = cipher.length();

    for(int i = 0;i < textLen; i++){
        if(isalpha(cipher[i])){
            int c = charToInt(cipher[i]);
            int k = charToInt(key[i % keyLen]);
            int p = (c - k + 26) % 26;
            result += intToChar(p);
        }else {
            result += cipher[i];
        }
    }
    return result;
}

int main(){
    string plaintext, key;
    std::cout << "Enter plaintext(Letters only): ";
    std::getline(std::cin, plaintext);

    std::cout << "Enter key: ";
    std::getline(std::cin, key);
    for(char &c : plaintext){ c = toupper(c);}
    for(char &c : key){ c = toupper(c);}
    if(key.length() < plaintext.length()){
        std::cout << "Error: Key must be at least long as plaintext." << "\n";
        return 1;
    }

    string trimKey = key.substr(0, plaintext.length());
    string cipher = Encrypt(plaintext, trimKey);
    string dec = decrypt(cipher, trimKey);

    std::cout << "Cipher Text: " << cipher << "\nDecrypted: " << dec << "\n";

    return 0;
}