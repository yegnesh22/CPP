#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> op;
	string expr;

	cin >> expr;

	for (int i = 0; i < expr.size(); i++) {
		if (IsOperand(expr[i])) {
			op.push(expr[i]);
		} else if (IsOpenBrace(expr[i])) {
			i ++;
			while (expr[i] != ')') {
				stack.push(expr[i]);
			}
		}
	}

}

