#include <iostream>
#include <ostream>
#include "Priority_Queue.hpp"

int main(){
    Myqueue::priority_queue<int> * p = new Myqueue::priority_queue<int>;
    p->push(1);
    p->push(2);
    p->push(3);
    p->push(4);
    p->push(6);
    p->push(7);
    p->push(8);
    p->push(9);
    p->push(10);
    p->push(11);
    p->push(12);
    p->push(13);
    p->push(14);
    p->push(15);
    p->push(16);
    p->push(17);
    p->push(18);
    p->push(19);
    p->push(20);
    p->push(35);
    p->push(50);
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();
    p->pop();

    std::cout << p->top() << std::endl;
    std::cout << p->size() << std::endl;
    std::cout << p->empty() << std::endl;
    delete p;
    return 0;
}
