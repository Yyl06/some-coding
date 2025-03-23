#include <list>
#include <iostream>

using namespace std;

int main() {
    //List = Doubly Linked-List
    list<int> lst = {10, 20, 30};
    list<int> l1;                // Empty list
    list<int> l2(5, 100);        // {100, 100, 100, 100, 100}
    list<int> l3 = {1, 2, 3};    // {1, 2, 3}
    list<int> l4(l3.begin(), l3.end()); // Copy from another container

    lst.push_front(5);  // {5, 10, 20, 30}
    lst.push_back(40);  // {5, 10, 20, 30, 40}
    lst.push_front(0); // {0, 1, 2, 3}
    lst.push_back(4);  // {0, 1, 2, 3, 4}

    lst.pop_front();   // {1, 2, 3, 4}
    lst.pop_back();    // {1, 2, 3}

    auto it = lst.begin();
    advance(it, 1);   // Move iterator to 2nd element
    lst.insert(it, 99);  // {1, 99, 2, 3}

    cout << lst.front() << " ";  // 10
    cout << lst.back() << " ";   // 30
    // No lst[i] or lst.at(i), must use iterators
    auto ite = lst.begin();
    advance(ite, 2);  // Move to 3rd element
    cout << *it;     // Print value at that position

    //Iterations
    for (auto it = lst.begin(); it != lst.end(); ++it){
        cout << *it << " ";  // Iterator-based loop
    }
    for (int x : lst){
        cout << x << " ";    // Range-based loop
    }
    list<int>::reverse_iterator rit;
    for (rit = lst.rbegin(); rit != lst.rend(); ++rit){
        cout << *rit << " "; // Reverse iteration
    }

    if (lst.empty()){
        cout << "List is empty!";
    }
    cout << lst.size();  // Get size

    lst.reverse();       // Reverse list order
    lst.sort();          // Sort the list
    lst.unique();        // Remove consecutive duplicates
    lst.merge(l1);    // Merge two sorted lists
    lst.splice(lst.begin(), l1, l1.begin()); // Transfer elements
    std::swap(l1, l2);    // Swap lists

    return 0;
}
