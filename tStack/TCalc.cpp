#include "TCalc.h"
#include "TStack.h"
#include <math.h>
double TCalc::Calc() {
	stNum.clear();
	stOpers.clear();
	string tmp = '(' + infix + ')';
	for (int i = 0; i < tmp.size(); i++) {
		switch (tmp[i]) {
		case '(':
			stOpers.push(eleftbracket);
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				stNum.push(res);
				i += idx;
			}
			break;
		case 's':
			if (tmp[i + 1] == 'i' && tmp[i + 2] == 'n' && tmp[i + 3] == '(') {
				stOpers.push(esin);
				i += 3;
				if (tmp[i + 1] == '-') {
					size_t idx;
					double res = stod(&tmp[i + 1], &idx);
					stNum.push(res);
					i += idx;
				}
			}
			break;
		case 'c':
			if (tmp[i + 1] == 'o' && tmp[i + 2] == 's' && tmp[i + 3] == '(') {
				stOpers.push(ecos);
				i += 3;
				if (tmp[i + 1] == '-') {
					size_t idx;
					double res = stod(&tmp[i + 1], &idx);
					stNum.push(res);
					i += idx;
				}
			}
			break;
		case '+': case '-': case '*': case '/': case '^':
		{
			Opers a = Opers(tmp[i]);
			while (prior(stOpers.top()) >= prior(a)) {
				Opers b = stOpers.pop();
				double secOp = stNum.pop();
				double frsOp = stNum.pop();
				switch (b) {
				case eadd: stNum.push(frsOp + secOp); break;
				case esub: stNum.push(frsOp - secOp); break;
				case emul: stNum.push(frsOp * secOp); break;
				case ediv: stNum.push(frsOp / secOp); break;
				case epow: stNum.push(pow(frsOp, secOp)); break;
				}
			}
			stOpers.push(a);
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
		{
			size_t idx;
			double res = stod(&tmp[i], &idx);
			stNum.push(res);
			i += idx - 1;
			break;
		}
		case ')':
			while (!(stOpers.top() == ecos || stOpers.top() == esin || stOpers.top() == eleftbracket)) {
				double secOp = stNum.pop();
				double frsOp = stNum.pop();
				switch (stOpers.pop()) {
				case eadd: stNum.push(frsOp + secOp); break;
				case esub: stNum.push(frsOp - secOp); break;
				case emul: stNum.push(frsOp * secOp); break;
				case ediv: stNum.push(frsOp / secOp); break;
				case epow: stNum.push(pow(frsOp, secOp)); break;
				}				
			}
			switch (stOpers.pop())
			{
			case eleftbracket:
				break;
			case esin:
				stNum.push(sin(stNum.pop()));
				break;
			case ecos:
				stNum.push(cos(stNum.pop()));
				break;
			}
			break;
		}
	}
	double res = stNum.pop();
	if (!stNum.isEmpty()) {
		string err = "Num is not empty";
		throw err;
	}
	return res;
}
double TCalc::CalcPostfix() {
	stNum.clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.'
			|| postfix[i] == '-' && postfix[i + 1] >= '0' && postfix[i + 1] <= '9') {
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
		else if (postfix[i] == 'c') stNum.push(cos(stNum.pop()));
		else if (postfix[i] == 's') stNum.push(sin(stNum.pop()));
	}
	double res = stNum.pop();
	if (stNum.isEmpty()) return res;
	else throw - 1;
}
int TCalc :: prior(Opers op) {
	switch (op)
	{
	case eadd: case esub:
		return 1;
		break;
	case emul: case ediv:
		return 2;
		break;
	case epow:
		return 3;
		break;
	case eleftbracket: case esin: case ecos:
		return 0;
		break;
	}
}
bool TCalc::check(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stOpers.push(eleftbracket);
		if (str[i] == ')') if (stOpers.isEmpty()) return false;
		else stOpers.pop();
	}
	if (!(stOpers.isEmpty())) return false;
	return true;
}
void TCalc::toPostfix() {
	postfix = "";
	stOpers.clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++) {
		switch (tmp[i]) {
		case '(': 
			stOpers.push(eleftbracket);
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				postfix += to_string(res);
				i += idx;
			}
			break;
		case '-': case '+': case '*': case '/': case '^': 
		{
			Opers a = Opers(tmp[i]);
			postfix += ' ';
			while (prior(stOpers.top()) >= prior(a)) {
				postfix += stOpers.pop();
				postfix += " ";
			}
			stOpers.push(a);
			break;
		}
		case ')':
			//скобки для инициализации а
		{
			while (!(stOpers.top() == eleftbracket || stOpers.top() == esin || stOpers.top() == ecos)) {
				postfix += ' ';
				postfix += stOpers.pop();
				postfix += " ";
			}
			switch (stOpers.pop()) {
			case eleftbracket: break;
			case esin:
				postfix += " sin ";
				break;
			case ecos:
				postfix += " cos ";
				break;
			}
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
			postfix += tmp[i];
			break;

		case 's': 
			if (tmp[i + 1] == 'i' && tmp[i + 2] == 'n' && tmp[i + 3] == '(') {
				stOpers.push(esin);
			}
			i += 3;
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				postfix += to_string(res);
				i += idx;
			}
			break;
		case 'c':
			if (tmp[i + 1] == 'o' && tmp[i + 2] == 's' && tmp[i + 3] == '(') {
				stOpers.push(ecos);
			}
			i += 3;
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = stod(&tmp[i + 1], &idx);
				postfix += to_string(res);
				i += idx;
			}
			break;
		}	
	}
}
void TCalc::setInfix(string input) {
	if (check(input)) infix = input;
	else {
		string err = "wrong input";
		throw err;
	}
}