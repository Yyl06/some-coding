#include <iostream>
#include <queue>

int main(){
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.front() << std::endl;
    q.pop();
    std::cout << q.front() << std::endl;
    std::cout << q.size() << std::endl;
    std::cout << q.empty() << std::endl;
    return 0;
}