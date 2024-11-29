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
	eminusbracket = 'z',
	esin = 'x',
	ecos = 'y'
};
class TCalc {
	std::string infix;
	std::string postfix;
	TStack<double> stNum;
	TStack<Opers> stOpers;
	int prior(Opers op);
public:
	TCalc(std::string inf = "") : infix(inf), stNum(50), stOpers(50) {}
	bool check(std::string str);
	void setInfix(std::string input);
	std::string getInfix() { return infix; }
	void setPostfix(std::string input) { postfix = input; }
	std::string getPostfix() { return postfix; }
	void toPostfix();
	double CalcPostfix(); 
	double Calc();
};