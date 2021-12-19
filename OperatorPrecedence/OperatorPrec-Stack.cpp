// Operator precedence - stack method

#include <iostream>
#include <map>
#include <stack>

using namespace std;

//#define DEBUG

map<char, int> precedence = {
	make_pair('%',3),
	make_pair('*',3),
	make_pair('/',3),
	make_pair('+',2),
	make_pair('-',2),
	make_pair('(',1),
	make_pair(')',1),
	make_pair('=',0),
};

bool isOperand(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

int compute(int op1, int op2, char opc)
{
	switch (opc) {
	case '%':
		return op1 % op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	case '-':
		return op1 - op2;
	case '+':
		return op1 + op2;
	}
}

int check_precedence(char c)
{
	map<char, int>::iterator it = precedence.find(c);
#ifdef DEBUG
	cout << "Precedence: " << it->first << " : " << it->second << endl;
#endif
	return it->second;
}

int evaluate(string expr)
{
	stack <int> value;
	stack <char> op;
	int result = 0;
	char operation;
	int v1, v2;

	for (int i = 0; i < expr.size(); i++) {
		if (isOperand(expr[i]) == true) { // 1. If operand push it to the value stack.
			value.push(expr[i] - '0');
		}
		else if (expr[i] == '(') { // 2. If left parenthesis, push it to the operator stack.
			op.push(expr[i]);
		}
		else if (expr[i] == ')') { // 3. If right parenthesis, pop until the corresponding left parenthesis
			while (op.top() != '(') {
				v2 = value.top();
				value.pop();
				v1 = value.top();
				value.pop();
				operation = op.top();
				op.pop();
				result = compute(v1, v2, operation);
				value.push(result);
#ifdef DEBUG
				cout << "intermediate op: "  << v1 << operation << v2 << "=" << result << endl;
#endif
			}
			op.pop(); // Pop out and discard the '('.
		}
		else {
			while (!(op.empty()) && (check_precedence(op.top()) >= check_precedence(expr[i]))) {
				v2 = value.top();
				value.pop();
				v1 = value.top();
				value.pop();
				operation = op.top();
				op.pop();
				result = compute(v1, v2, operation);
				value.push(result);
#ifdef DEBUG
				cout << "intermediate op: " << v1 << operation << v2 << "=" << result << endl;
#endif
			}
			op.push(expr[i]);
		}
	}

	while (!op.empty()) {
		v2 = value.top();
		value.pop();
		v1 = value.top();
		value.pop();
		operation = op.top();
		op.pop();
		result = compute(v1, v2, operation);
		value.push(result);
#ifdef DEBUG
		cout << "intermediate op: " << v1 << operation << v2 << "=" << result << endl;
#endif
	}

	return result;
}

int main()
{
	string expr;

	cin >> expr;
	cout << evaluate(expr) << endl;

	return 0;
}
