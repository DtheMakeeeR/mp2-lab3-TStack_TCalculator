#include <stdlib.h>
#include <iostream>
#include "TCalc.h"
using namespace std;
static enum test {
	a = 'a',
	b = 'c',
	c 
};
int main() {
	/*string s = "sin(4)";
	string ss = s.replace(0, s.size(), "sin(");
	cout << ss;*/

	/*test tes = test('c');
	string s = "";
	s += tes;
	cout << tes << endl;
	cout << s;*/

	TStack<double> stack(10);
	TCalc calc;
	calc.setInfix("sin(-190)^5");
	calc.toPostfix();
	cout << calc.getPostfix();
	cout << endl << calc.CalcPostfix();
	try {
		calc.setInfix("sin((-1))");
		cout << calc.Calc();
	}
	catch (string e) { cout << "error" << endl << e; }

	//calc.setInfix("(((1 / 2 * 3) / 4 - 5) + 6) / 7");
	//calc.toPostfix();
	//cout << calc.getPostfix() << endl << calc.CalcPostfix() << " " << 0.19642857142 << endl;
	//calc.setInfix("1*2-3*4/5+6");
	//calc.toPostfix();
	//cout << calc.getPostfix() << endl << calc.CalcPostfix() << " " << 5.6 << endl;
	//calc.setInfix("((7+5)*(3-2)+4) ^ 2");
	//calc.toPostfix();
	//cout << calc.getPostfix() << endl << calc.CalcPostfix() << " " << 256 << endl;
}