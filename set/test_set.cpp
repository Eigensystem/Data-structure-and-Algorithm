#include <iostream>
#include "myset.hpp"

using namespace Myset;

void check(set<int> * myset, int number){
	myset->insert(number);
	// myset->show();
	// std::cout << std::endl;
}

int main(){
	set<int> * myset = new set<int>;
	check(myset, 20);
	check(myset, 28);
	check(myset, 27);
	check(myset, 26);
	check(myset, 25);
	check(myset, 24);
	check(myset, 23);
	check(myset, 22);
	check(myset, 21);
	check(myset, 35);
	check(myset, 33);
	check(myset, 34);
	check(myset, 31);
	check(myset, 32);
	check(myset, 30);
	check(myset, 29);
	check(myset, 38);
	check(myset, 36);
	check(myset, 37);
	check(myset, 39);
	check(myset, 40);
	myset->show();
	std::cout << std::endl;
	myset->erase(35);
	myset->show();
	// std::printf("%d\n", myset.empty());
	// std::printf("%ld\n", myset->size());
	// myset->clear();
	// std::printf("%ld\n", myset->size());
	return 0;
}