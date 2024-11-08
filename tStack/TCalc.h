#pragma once
#include <string>
#include "TStack.h"
using namespace std;
class TCalc {
	string infix;
	string postfix;
	TStack<double> stNum;
	TStack<char> stChar;
	int prior(char op); 
public:
	TCalc(string inf = "") : infix(inf), stNum(50), stChar(50) {}
	bool check(string str);
	void setInfix(string input);
	string getInfix() { return infix; }
	void setPostfix(string input) { postfix = input; }
	string getPostfix() { return postfix; }
	void toPostfix();
	double CalcPostfix(); 
	double Calc();
};