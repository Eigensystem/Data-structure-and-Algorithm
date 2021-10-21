#include <iostream>
#include "myset.hpp"

using namespace Myset;

int main(){
	set<int> myset;
	myset.insert(5);
	myset.insert(55);
	myset.insert(27);
	myset.insert(26);
	myset.insert(25);
	myset.insert(24);
	myset.insert(23);
	myset.insert(22);
	myset.insert(21);
	myset.insert(100);
	std::printf("%d\n", myset.empty());
	std::printf("%ld\n", myset.size());
	myset.clear();
	std::printf("%ld\n", myset.size());
	return 0;
}