#include <stdlib.h>
#include <iostream>
#include "TCalc.h"
using namespace std;

int main() {
	TStack<double> stack(10);
	TCalc calc;
	calc.setInfix("1 + 2 + 3 )");
	calc.toPostfix();
	cout << calc.getPostfix() << endl << calc.CalcPostfix() << endl;
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