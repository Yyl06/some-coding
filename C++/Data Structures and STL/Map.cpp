#include <map>
#include <iostream>

using namespace std;

int main() {
    //Map is also basically a self balancing BST
    map<string, int> mp;
    map<int, string> m1;                    // Empty map
    map<int, string> m2 = {{1, "one"}, {2, "two"}};  // Init list
    map<int, string> m3(m2.begin(), m2.end()); // Copy another map

    //Insertion
    mp["apple"] = 50;  // Insert key-value pair
    mp.insert({"grape", 20});
    mp["mango"] = 15;  // If key exists, it updates the value
    mp.erase("apple"); // Remove "apple"
    mp.clear();        // Delete all elements

    //Search
    if (mp.count("banana")) cout << "Exists!"; // Returns 1 if found, else 0
    //Traversal Search
    auto it = mp.find("banana");
    if (it != mp.end()) cout << "Banana price: " << it->second;

    //Iteration
    for (auto it = mp.begin(); it != mp.end(); ++it){
        cout << it->first << " -> " << it->second << "\n";
    }
    for (auto [key, value] : mp){
        cout << key << " -> " << value << "\n"; // C++17 structured bindings
    }

    //Bounds and Ranges
    auto it1 = mp.lower_bound("banana");  // First key >= "banana"
    auto it2 = mp.upper_bound("banana"); // First key > "banana"

    return 0;
}
