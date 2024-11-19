#pragma once
#include <string>
#include "TStack.h"
enum Opers{
	eadd = '+',
	esub = '-',
	emul = '*',
	ediv = '/',
	epow = '^',
	eleftbracket = '(',
	esin = 'x',
	ecos = 'y'
};
using namespace std;
class TCalc {
	string infix;
	string postfix;
	TStack<double> stNum;
	TStack<Opers> stOpers;
	int prior(Opers op);
public:
	TCalc(string inf = "") : infix(inf), stNum(50), stOpers(50) {}
	bool check(string str);
	void setInfix(string input);
	string getInfix() { return infix; }
	void setPostfix(string input) { postfix = input; }
	string getPostfix() { return postfix; }
	void toPostfix();
	double CalcPostfix(); 
	double Calc();
};