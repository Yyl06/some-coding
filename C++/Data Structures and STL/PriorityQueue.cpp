#include <iostream>
#include <queue>

int main(){
    //Priority queue, for Min Heap and Max Heap
    std::priority_queue<int> pq;  // Max-heap by default

    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        std::cout << pq.top() << " ";  // Output: 30 20 10
        pq.pop();
    }

    return 0;
}