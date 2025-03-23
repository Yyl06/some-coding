#include <set>
#include <iostream>

using namespace std;

int main() {
    //set = Self Balancing Binary Search Tree
    set<int> s = {30, 10, 20, 50, 40};
    set<int> s1;                // Empty set
    set<int> s2 = {1, 2, 3};    // Initialize with values
    set<int> s3(s2.begin(), s2.end()); // Copy from another container

    s.insert(5);       // {5}
    s.insert(10);      // {5, 10}
    s.insert(5);       // {5, 10} (duplicate ignored)

    s.erase(5);        // {10}

    //Deletion by Traversal
    auto it = s.find(10);
    if (it != s.end()){
        s.erase(it);  // Erase by iterator
    }

    s.clear();         // Remove all elements

    //Searching(Non-Traversal/Traversal)
    if (s.count(10)) cout << "Found!";  // Returns 1 if exists, 0 if not
    auto its = s.find(10);
    if (its != s.end()) cout << "Found " << *it;

    //Iteration
    for (auto it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";  // Sorted order
    }
    for (int x : s){
        cout << x << " ";    // Range-based loop
    }
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit){
        cout << *rit << " "; // Reverse order
    }

    return 0;
}
