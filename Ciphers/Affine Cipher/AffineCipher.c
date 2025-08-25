#include <stdio.h>
#include <string.h>

const int a = 11;
const int b = 5;

void Encryption(const char msg[], char cipher[]){
    int i;
    for (i = 0; msg[i] != '\0' ; i++){
        if(msg[i] != ' '){
            cipher[i] = (char)((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        }else{
            cipher[i] = ' ';
        }
    }
    cipher[i] = '\0';
}

void Decryption(const char cipher[], char msg[]){
    int a_inv = 0;
    int flag, i;

    for(i = 0; i < 26; i++){
        flag = (a * i) % 26;
        if(flag == 1){
            a_inv = i;
            break;
        }
    }

    for(i = 0; cipher[i] != '\0'; i++){
        if(cipher[i] != ' '){
            int val = (cipher[i] - 'A' - b);
            if(val < 0) val += 26;
            msg[i] = (char)(((a_inv * val) % 26) + 'A');
        }else{
            msg[i] = ' ';
        }
    }
    msg[i] = '\0';
}

int main(){
    char msg[1000];
    char cipher[1000];
    char backToPlain[1000];

    printf("Enter Plaintext for encryption: ");
    fgets(msg, sizeof(msg), stdin);

    msg[strcspn(msg, "\n")] = '\0';

    Encryption(msg, cipher);
    printf("Ciphertext: %s\n", cipher);

    Decryption(cipher, backToPlain);
    printf("Decrypted Text: %s\n", backToPlain);

    return 0;
}
