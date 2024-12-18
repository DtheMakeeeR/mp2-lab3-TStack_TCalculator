#include "TCalc.h"
#include "TStack.h"
#include <math.h>
double TCalc::Calc() {
	stNum.Clear();
	stOpers.Clear();
	std::string tmp = '(' + infix + ')';
	for (int i = 0; i < tmp.size(); i++) {
		switch (tmp[i]) {
		case '(':
			stOpers.Push(eleftbracket);

			if (tmp[i + 1] == '-') {
				if (tmp[i + 2] == '(') {
					stOpers.Push(eminusbracket);
					i += 2;
				}
				else {
					size_t idx;
					double res = std::stod(&tmp[i + 1], &idx);
					stNum.Push(res);
					i += idx;
				}				
			}			
			break;
		case 's':
			if (tmp[i + 1] == 'i' && tmp[i + 2] == 'n' && tmp[i + 3] == '(') {
				stOpers.Push(esin);
				i += 3;
				if (tmp[i + 1] == '-') {
					size_t idx;
					double res = std::stod(&tmp[i + 1], &idx);
					stNum.Push(res);
					i += idx;
				}
			}
			break;
		case 'c':
			if (tmp[i + 1] == 'o' && tmp[i + 2] == 's' && tmp[i + 3] == '(') {
				stOpers.Push(ecos);
				i += 3;
				if (tmp[i + 1] == '-') {
					size_t idx;
					double res = std::stod(&tmp[i + 1], &idx);
					stNum.Push(res);
					i += idx;
				}
			}
			break;
		case '+': case '-': case '*': case '/': case '^':
		{
			Opers a = Opers(tmp[i]);
			while (prior(stOpers.Peek()) >= prior(a)) {
				Opers b = stOpers.Pop();
				double secOp = stNum.Pop();
				double frsOp = stNum.Pop();
				switch (b) {
				case eadd: stNum.Push(frsOp + secOp); break;
				case esub: stNum.Push(frsOp - secOp); break;
				case emul: stNum.Push(frsOp * secOp); break;
				case ediv: if (secOp == 0.0) throw -1; stNum.Push(frsOp / secOp); break;
				case epow: stNum.Push(pow(frsOp, secOp)); break;
				}
			}
			stOpers.Push(a);
			break;
		}
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
		{
			size_t idx;
			double res = std::stod(&tmp[i], &idx);
			stNum.Push(res);
			i += idx - 1;
			break;
		}
		case ')':
			while (!(stOpers.Peek() == eminusbracket || stOpers.Peek() == ecos ||
				stOpers.Peek() == esin || stOpers.Peek() == eleftbracket)) {
				
				switch (stOpers.Pop()) {
				case eadd: {
					double secOp = stNum.Pop();
					double frsOp = stNum.Pop();
					stNum.Push(frsOp + secOp);
					break;
				}
				case esub: {
					double secOp = stNum.Pop();
					double frsOp = stNum.Pop();
					stNum.Push(frsOp - secOp);
					break;
				}
				case emul: {
					double secOp = stNum.Pop();
					double frsOp = stNum.Pop();
					stNum.Push(frsOp * secOp);
					break;

				}
				case ediv: {
					double secOp = stNum.Pop();
					double frsOp = stNum.Pop();
					if (secOp == 0.0) throw - 1;
					stNum.Push(frsOp / secOp);
					break;
				}
				case epow: {
					double secOp = stNum.Pop();
					double frsOp = stNum.Pop();
					stNum.Push(pow(frsOp, secOp));
					break;
				}
				}				
			}
			switch (stOpers.Pop())
			{
			case eleftbracket:
				break;
			case esin:
				stNum.Push(sin(stNum.Pop()));
				break;
			case ecos:
				stNum.Push(cos(stNum.Pop()));
				break;
			case eminusbracket:
				stNum.Push(-stNum.Pop());
				break;
			}
		
		}
	}
	double res = stNum.Pop();
	if (!stNum.IsEmpty()) {
		std::string err = "Num is not empty";
		throw err;
	}
	return res;
}
double TCalc::CalcPostfix() {
	stNum.Clear();
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.'
			|| postfix[i] == '-' && postfix[i + 1] >= '0' && postfix[i + 1] <= '9') {
			size_t idx;
			double tmp = std::stod(&postfix[i], &idx);
			stNum.Push(tmp);
			i += idx - 1;
		}
		else if (postfix[i] == '+' || postfix[i] == '-' ||
			postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double secondOp = stNum.Pop();
			double firstOp = stNum.Pop();
			switch (postfix[i]) {
			case '+':
				stNum.Push(firstOp + secondOp);
				break;
			case '-':
				if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9') break;
				stNum.Push(firstOp - secondOp);
				break;
			case '*':
				stNum.Push(firstOp * secondOp);
				break;
			case '/':
				if (secondOp == 0.0) throw - 1;
				stNum.Push(firstOp / secondOp);
				break;
			case '^':
				stNum.Push(pow(firstOp, secondOp));
				break;
			}
		}
		else if (postfix[i] == 'c') {
			stNum.Push(cos(stNum.Pop()));
			i += 2;
		}
		else if (postfix[i] == 's') {
			stNum.Push(sin(stNum.Pop()));
			i += 2;
		}
	}
	double res = stNum.Pop();
	if (stNum.IsEmpty()) return res;
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
	case eleftbracket: case esin: case ecos: case eminusbracket:
		return 0;
		break;
	}
}
bool TCalc::check(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') stOpers.Push(eleftbracket);
		if (str[i] == ')') if (stOpers.IsEmpty()) return false;
		else stOpers.Pop();
	}
	if (!(stOpers.IsEmpty())) return false;
	return true;
}
void TCalc::toPostfix() {
	postfix = "";
	stOpers.Clear();
	std::string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++) {
		switch (tmp[i]) {
		case '(': 
			stOpers.Push(eleftbracket);
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = std::stod(&tmp[i + 1], &idx);
				postfix += std::to_string(res);
				i += idx;
			}
			break;
		case '-': case '+': case '*': case '/': case '^': 
		{
			Opers a = Opers(tmp[i]);
			postfix += ' ';
			while (prior(stOpers.Peek()) >= prior(a)) {
				postfix += stOpers.Pop();
				postfix += " ";
			}
			stOpers.Push(a);
			break;
		}
		case ')':
			//скобки для инициализации а
		{
			while (!(stOpers.Peek() == eleftbracket || stOpers.Peek() == esin || stOpers.Peek() == ecos)) {
				postfix += ' ';
				postfix += stOpers.Pop();
				postfix += " ";
			}
			switch (stOpers.Pop()) {
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
				stOpers.Push(esin);
			}
			i += 3;
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = std::stod(&tmp[i + 1], &idx);
				postfix += std::to_string(res);
				i += idx;
			}
			break;
		case 'c':
			if (tmp[i + 1] == 'o' && tmp[i + 2] == 's' && tmp[i + 3] == '(') {
				stOpers.Push(ecos);
			}
			i += 3;
			if (tmp[i + 1] == '-') {
				size_t idx;
				double res = std::stod(&tmp[i + 1], &idx);
				postfix += std::to_string(res);
				i += idx;
			}
			break;
		}	
	}
}
void TCalc::setInfix(std::string input) {
	if (check(input)) infix = input;
	else {
		std::string err = "wrong input";
		throw err;
	}
}