#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    //Basically map but didnt gives a shit about sequences
    //Hash table based associative container
    unordered_map<string, int> umap;
    unordered_map<int, string> um1;               // Empty map
    unordered_map<int, string> um2 = {{1, "one"}, {2, "two"}};  // Init list
    unordered_map<int, string> um3(um2.begin(), um2.end()); // Copy another map

    //Insertion and Deletion
    umap.insert({"grape", 20});
    umap["mango"] = 15;  // If key exists, it updates the value
    umap.erase("apple"); // Remove "apple"
    umap.clear();        // Delete all elements

    //Search
    if (umap.count("banana")) cout << "Exists!"; // Returns 1 if found, else 0
    //Traversal Search
    auto it = umap.find("banana");
    if (it != umap.end()){
        cout << "Banana price: " << it->second;
    }

    //Iteration
    for (auto it = umap.begin(); it != umap.end(); ++it){
        cout << it->first << " -> " << it->second << "\n";
    }

    for (auto [key, value] : umap){
        cout << key << " -> " << value << "\n";
    }  // C++17 structured bindings

    return 0;
}
