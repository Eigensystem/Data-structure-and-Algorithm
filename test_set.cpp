#include <iostream>
#include "myset.hpp"

using namespace Myset;

int main(){
    set<int> myset;
    myset.insert(5);
    myset.insert(10);
    myset.insert(25);
    myset.insert(100);
    std::printf("%d\n", myset.empty());
    std::printf("%ld\n", myset.size());
    myset.clear();
    std::printf("%ld\n", myset.size());
    std::printf("Succeed!");
    return 0;
}



