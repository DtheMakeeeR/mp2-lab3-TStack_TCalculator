#include <stdlib.h>
#include <iostream>
#include "TStack.h"
using namespace std;
bool Check(string str) {
	TStack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push('(');
		if (str[i] == ')') if (st.isEmpty()) return false;
		else st.pop();
	}
	if (!(st.isEmpty())) return false;
}
int main() {

}