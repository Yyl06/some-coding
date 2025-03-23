#include <deque>
#include <iostream>

using namespace std;

int main() {
    //Double ended-queue(deque)
    //Basically vector + list
    deque<int> dq = {1, 2, 3};

    dq.push_front(0); // [0, 1, 2, 3]
    dq.push_back(4);  // [0, 1, 2, 3, 4]

    dq.pop_front();   // [1, 2, 3, 4]
    dq.pop_back();    // [1, 2, 3]

    cout << dq.front() << " "; // 1
    cout << dq.back() << " ";  // 3
    cout << dq[1];        // Direct access (like vector)
    cout << dq.at(2);     // Safe access (throws out_of_range exception)

    for (auto it = dq.begin(); it != dq.end(); ++it){
        cout << *it << " ";  // Iterator-based loop
    }

    for(int x : dq){
        cout << x << " ";
    }   // Range-based loop

    deque<int>::reverse_iterator rit;
    for (rit = dq.rbegin(); rit != dq.rend(); ++rit){
        cout << *rit << " "; // Reverse iteration
    }
    return 0;
}