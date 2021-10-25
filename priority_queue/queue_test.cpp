#include <iostream>
#include "Priority_Queue.hpp"

int main(){
    Myqueue::priority_queue<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(-5);
    // p.push(4);
    std::cout << p.top() << std::endl;
    return 0;
}