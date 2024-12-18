#include "LStack.h"
#include <iostream>
int main() {
	LStack<int> st1, st2;
	for (int i = 0; i < 5; i++) {
		st1.Push(i);
	}
	st1.Pop();
	st2 = st1;
	st1.Pop();
	if (st1 == st2) std::cout << "equals";
	else std::cout << "not equals";
}