#include <iostream>
#include <stack>

int main(){
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;
    std::cout << s.empty() << std::endl;
    return 0;
}