#include <iostream>
#include <string>
#include <cctype>
using std::string;

char matrix[5][5];
bool used[26];

void buildMatrix(const string &key){
    string filtered = "";
    for(char c : key){
        if(isalpha(c)){
            c = toupper(c);
            if(c == 'J')c = 'I';
            if(!used[c - 'A']){
                used[c - 'A'] = true;
                filtered += c;
            }
        }
    }
    for(char c = 'A'; c <= 'Z'; c++){
        if(c == 'J') continue;
        if(!used[c - 'A']){
            used[c - 'A'] = true;
            filtered += c;
        }
    }
    int k = 0;
    for(int i = 0 ; i < 5; i++){
        for(int j = 0 ; j < 5; j++){
            matrix[i][j] = filtered[k++];
        }
    }
}

void findPosition(char c, int &row, int &col){
    if(c == 'J') c = 'I';
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] == c){
                row = i;
                col = j;
                return;
            }
        }
    }
}

string prepareText(const string &text){
    string result = "";
    for(char c : text){
        if(isalpha(c)){
            c = toupper(c);
            if(c == 'J') c = 'I';
            result += c;
        }
    }
    string processed = "";
    for(size_t i = 0; i < result.length(); i++){
        processed += result[i];
        if(i + 1 < result.length() && result[i] == result[i+1]){
            processed += 'X';
        }
    }

    if(processed.length() % 2 != 0){
        processed += 'X';
    }
    return processed;
}

string cleanedText(const string &text){
    string result = "";
    for(size_t i = 0; i < text.length(); i++){
        if(i > 0 && i < text.length() - 1 && text[i] == 'X' && text[i - 1] == text[i + 1]){
            continue;
        }
        result += text[i];
    }
    if(!result.empty() && result.back() == 'X'){
        result.pop_back();
    }
    return result;
}

string encrypt(const string &text){
    string result = "";
    for(size_t i = 0; i < text.length(); i += 2){
        char a = text[i], b = text[i+1];
        int r1, c1, r2, c2;
        findPosition(a, r1, c1);
        findPosition(b, r2, c2);

        if(r1 == r2){
            result += matrix[r1][(c1 + 1) % 5];
            result += matrix[r2][(c2 + 1) % 5];
        }else if(c1 == c2){
            result += matrix[(r1 + 1) % 5][c1];
            result += matrix[(r2 + 1) % 5][c2];
        }else{
            result += matrix[r1][c2];
            result += matrix[r2][c1];
        }
    }
    return result;
}

string decrypt(const string &text){
    string result = "";
    for(size_t i = 0; i < text.length(); i += 2){
        char a = text[i], b = text[i + 1];
        int r1, c1, r2, c2;
        findPosition(a, r1, c1);
        findPosition(b, r2, c2);

        if(r1 == r2){
            result += matrix[r1][(c1 + 4) % 5];
            result += matrix[r2][(c2 + 4) % 5];
        }else if(c1 == c2){
            result += matrix[(r1 + 4) % 5][c1];
            result += matrix[(r2 + 4) % 5][c2];
        }else{
            result += matrix[r1][c2];
            result += matrix[r2][c1];
        }
    }
    return result;
}

int main(){
    string key, plaintext;
    std::cout << "Enter key: ";
    std::getline(std::cin, key);
    buildMatrix(key);

    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);
    string prepared = prepareText(plaintext);
    string cipher = encrypt(prepared);
    string dec = decrypt(cipher);
    string cleaned = cleanedText(dec);

    std::cout << "\nPrepared text: " << prepared;
    std::cout << "\nCiphertext: " << cipher;
    std::cout << "\nDecrypted text: " << dec;
    std::cout << "\nCleaned text: " << cleaned << "\n";

    return 0;
}