#include <bits/stdc++.h>
using std::string;

const int a = 11;
const int b = 5;

string encryptMessage(string msg){
    string cipher = "";

    for(int i = 0; i < msg.length(); i++){
        if(msg[i] != ' '){
            cipher = cipher + (char)((((a * (msg[i] - 'A'))+ b ) % 26)+ 'A');
        }else{
            cipher += msg[i];
        }
    }
    return cipher;
}

string decryptCipher(string cipher){
    string msg = "";
    int a_inv = 0;
    int flag = 0;

    for(int i = 0; i < 26; i++){
        flag = (a * i) % 26;
        if(flag == 1){
            a_inv = i;
        }
    }

    for(int i = 0 ; i < cipher.length(); i++){
        if(cipher[i] != ' '){
            int val = (cipher[i] - 'A' - b);
            if(val < 0) val += 26;
            msg = msg + (char)(((a_inv * val )% 26) + 'A');
        }else{
            msg += cipher[i];
        }
    }
    return msg;
}

int main(){
    string msg;

    std::cout << "Enter Plaintext for encryption: ";
    std::getline(std::cin, msg);

    string cipher = encryptMessage(msg);
    std::cout << "Ciphertext: " << cipher << std::endl;

    string decrypted = decryptCipher(cipher);
    std::cout << "Decrypted Text: " << decrypted << std::endl;

    return 0;
}