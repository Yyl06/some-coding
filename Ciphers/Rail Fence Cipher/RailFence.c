#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void Encryption(char text[], int key, char result[]){
    int len = strlen(text);
    char rail[key][len];

    for(int i = 0; i < key ; i++){
        for(int j = 0; j < len; j++){
            rail[i][j] = '\n';
        }
    }
    bool dir_down = false;
    int row = 0, col = 0;

    for(int i = 0; i < len; i++){
        if(row == 0 || row == key - 1){
            dir_down = !dir_down;
        }
        rail[row][col++] = text[i];
        row += dir_down ? 1 : -1;
    }
    int index = 0;
    for(int i = 0; i < key ; i++){
        for(int j = 0; j < len ; j++){
            if(rail[i][j] != '\n'){
                result[index++] = rail[i][j];
            }
        }
    }
    result[index] = '\0';
}

void Decryption(char cipher[], int key, char result[]){
    int len = strlen(cipher);
    char rail[key][len];

    for(int i = 0; i < key; i++){
        for(int j = 0; j < len; j++){
            rail[i][j] = '\n'; 
        }
    }
    bool dir_down;
    int row = 0, col = 0;

    for(int i = 0; i < len; i++){
        if(row == 0) dir_down = true;
        if(row == key - 1) dir_down = false;

        rail[row][col++] = '*';
        row += dir_down ? 1 : -1;
    }

    int index = 0;
    for(int i = 0; i < key ; i++){
        for(int j = 0; j < len; j++){
            if(rail[i][j] == '*' && index < len){
                rail[i][j] = cipher[index++];
            }
        }
    }

    row = col = 0;
    for(int i = 0; i < len; i++){
        if(row == 0) dir_down = true;
        if(row == key - 1) dir_down = false;

        if(rail[row][col] != '\n'){
            result[i] = rail[row][col];
        }
        col++;
        row += dir_down ? 1 : -1;
    }
    result[len] = '\0';
}

int main(){
    char text[1000], cipher[1000], decrypted[1000];
    int key;
    
    printf("Enter the Plaintext: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%d", &key);

    Encryption(text, key, cipher);
    printf("Ciphertext: %s\n", cipher);

    Decryption(cipher, key, decrypted);
    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}