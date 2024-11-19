#include "TCalc.h"
#include "TStack.h"
#include <math.h>
double TCalc::Calc() {
	stNum.clear();
	stChar.clear();
	string tmp = '(' + infix + ')';
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] == '(') {
			stChar.push('(');
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				stNum.push(res);
				i += idx;
			}
		}
		else if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*'
			|| tmp[i] == '/' || tmp[i] == '^') {
			while (prior(stChar.top()) >= prior(tmp[i])) {
				char a = stChar.pop();
				double secOp = stNum.pop();
				double frsOp = stNum.pop();
				if (a == '+') stNum.push(secOp + frsOp);
				if (a == '-') stNum.push(frsOp - secOp);
				if (a == '*') stNum.push(secOp * frsOp);
				if (a == '/') stNum.push(frsOp / secOp);
				if (a == '^') stNum.push(pow(frsOp, secOp));
			}
			stChar.push(tmp[i]);
		}
		else if (tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] == '.') {
			size_t idx;
			double res = stod(&tmp[i], &idx);
			stNum.push(res);
			i += idx - 1;
		}
		else if (tmp[i] == ')') {
			while (stChar.top() != '(') {
				char a = stChar.pop();
				double secOp = stNum.pop();
				double frsOp = stNum.pop();
				if (a == '+') stNum.push(secOp + frsOp);
				else if (a == '-') stNum.push(frsOp - secOp);
				else if (a == '*') stNum.push(secOp * frsOp);
				else if (a == '/') stNum.push(frsOp / secOp);
				else if (a == '^') stNum.push(pow(frsOp, secOp));
			}
			stChar.pop();
		}
	}
	double res = stNum.pop();
	if (!stNum.isEmpty()) throw "Num is not empty";
	return res;
}
double TCalc::CalcPostfix() {
	stNum.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.'
			|| postfix[i] == '-' && postfix[i+1] >= '0' && postfix[i+1] <= '9') {
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			stNum.push(tmp);
			i += idx - 1;
		}
		else if (postfix[i] == '+' || postfix[i] == '-' ||
			postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double secondOp = stNum.pop();
			double firstOp = stNum.pop();
			switch (postfix[i]) {
			case '+':
				stNum.push(firstOp + secondOp);
				break;
			case '-':
				if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9') break;
				stNum.push(firstOp - secondOp);
				break;
			case '*':
				stNum.push(firstOp * secondOp);
				break;
			case '/':
				stNum.push(firstOp / secondOp);
				break;
			case '^':
				stNum.push(pow(firstOp, secondOp));
				break;
			}
		}
		//cout << stNum.top();
	}
	double res = stNum.pop();
	if (stNum.isEmpty()) return res;
	else throw - 1;
}
int TCalc :: prior(char op) {
	switch (op) {
	case '(':
		return 0;
		//break;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	}
}
bool TCalc::check(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stChar.push('(');
		if (str[i] == ')') if (stChar.isEmpty()) return false;
		else stChar.pop();
	}
	if (!(stChar.isEmpty())) return false;
}
void TCalc::toPostfix() {
	postfix = "";
	stChar.clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++) {
		switch (tmp[i]) {
		case '(': 
			stChar.push('(');
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				postfix += to_string(res);
				i += idx;
			}
			break;
		case '-': case '+': case '*': case '/': case '^': 
			postfix += ' ';
			while (prior(stChar.top()) >= prior(tmp[i])) {
				postfix += stChar.pop();
				postfix += " ";
			}
			stChar.push(tmp[i]);
			break;
		case ')':
			//скобки для инициализации а
		{
			char a = stChar.pop();
			while (a != '(') {
				postfix += a;
				postfix += " ";
				a = stChar.pop();
			}
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
			postfix += tmp[i];
		}	
	}
}
void TCalc::setInfix(string input) {
	if (check(input)) infix = input;
}