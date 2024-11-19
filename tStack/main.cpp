#include <stdlib.h>
#include <iostream>
#include "TCalc.h"
using namespace std;

int main() {
	/*string s = "sin(4)";
	string ss = s.replace(0, s.size(), "sin(");
	cout << ss;*/
	TStack<double> stack(10);
	TCalc calc;
	try {
		calc.setInfix("3.3 - 8/2^(-2)))");
		calc.toPostfix();
		cout << calc.getPostfix() << endl << calc.CalcPostfix() << endl;
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