#include <iostream>
#include <cctype>
#include <map>
#include <vector>
using std::map, std::vector, std::string;

class BifidCipher{
    char grid[5][5] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };

    map<char, std::pair<int, int>> polybius;
    map<std::pair<int, int>, char> reversePolybius;

    public:
        BifidCipher(){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    polybius[grid[i][j]] = {i+1, j+1};
                    reversePolybius[{i+1, j+1}] = grid[i][j];
                }
            }
            polybius['J'] = polybius['I'];
        }

        string encrypt(string plaintext){
            vector<int> rows, cols;
            string prepared = "";
            for(char c : plaintext){
                if(isalpha(c)){
                    c = toupper(c);
                    if(c == 'J') c = 'I';
                    prepared += c;
                    auto pos = polybius[c];
                    rows.push_back(pos.first);
                    cols.push_back(pos.second);
                } 
            }

            vector<int> combined = rows;
            combined.insert(combined.end(), cols.begin(), cols.end());

            string cipher = "";
            for(size_t i = 0; i < combined.size(); i += 2){
                int r = combined[i];
                int c = combined[i + 1];
                cipher += reversePolybius[{r, c}];
            }
            return cipher;
        }

        string decrypt(string ciphertext){
            vector<int> nums;
            for(char c: ciphertext){
                if(isalpha(c)){
                    c = toupper(c);
                    if(c == 'J') c = 'I';
                    auto pos = polybius[c];
                    nums.push_back(pos.first);
                    nums.push_back(pos.second);
                }
            }

            int half = nums.size()/2;
            vector<int> rows(nums.begin(), nums.begin() + half);
            vector<int> cols(nums.begin() + half, nums.end());

            string plain = "";
            for(size_t i = 0; i < rows.size(); i++){
                plain += reversePolybius[{rows[i], cols[i]}];
            }
            return plain;
        }
};

int main(){
    BifidCipher cipher;

    string text;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, text);

    string enc = cipher.encrypt(text);
    std::cout << "Ciphertext: " << enc << "\n";

    string dec = cipher.decrypt(enc);
    std::cout << "Plaintext: " << dec << "\n";
}