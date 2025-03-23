#include <iostream>
#include <queue>

int main(){
    //Normal Queue
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.front() << std::endl;
    while(!q.empty()){
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << q.front() << std::endl;
    std::cout << q.size() << std::endl;

    return 0;
}