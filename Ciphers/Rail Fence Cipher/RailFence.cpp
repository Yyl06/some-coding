#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

string Encryption(string text, int key){
    vector<string> rail(key);
    int row = 0;
    bool down = false;

    for(char c : text){
        rail[row] += c;
        if(row == 0 || row == key -1){
            down = !down;
        }
        row += down ? 1 : -1;
    }
    string result;
    for(const string &r : rail){
        result += r;
    }
    return result;
}

string Decryption(string cipher, int key){
    int len = cipher.length();
    vector<vector<char>> rail(key, vector<char>(len, '\n'));
    
    bool down;
    int row = 0, col = 0;
    for(int i = 0; i < len; i++){
        if(row == 0) down = true;
        if(row == key - 1) down = false;

        rail[row][col++] = '*';
        row += down ? 1 : -1;
    }

    int index = 0;
    for(int i = 0; i < key ; i++){
        for(int j = 0; j < len; j++){
            if(rail[i][j] == '*' && index < len){
                rail[i][j] = cipher[index++];
            }
        }
    }

    string result;
    row = col = 0;
    down = true;
    for(int i = 0; i < len; i++){
        if(row == 0) down = true;
        if(row == key - 1) down = false;

        result.push_back(rail[row][col++]); 
        row += down ? 1 : -1;
    }
    return result;
}

int main(){
    string text;
    int key;

    std::cout << "Enter Plaintext: ";
    std::getline(std::cin, text);

    std::cout << "Enter Key: ";
    std::cin >> key;

    string cipher = Encryption(text, key);
    std::cout << "Ciphertext: " << cipher << std::endl;

    string dec = Decryption(cipher, key);
    std::cout << "Decrypted Text: " << dec << std::endl;

    return 0;
}