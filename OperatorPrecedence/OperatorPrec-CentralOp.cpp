#include <iostream>
#include <stack>
using namespace std;

//#define DEBUG

int calculate(int op1, int op2, char op)
{
	switch (op) {
		case '*':
		return (op1 * op2);
		case '/':
		return (op1 / op2);
		case '+':
		return (op1 + op2);
		case '-':
		return (op1 - op2);
	}
}

size_t find_central_op(string expr)
{
	size_t i1, i2;
	char c;

	// First check if the expression has a + or -
	// Since these operations are of lower precedence than *, /, and %
	// +, - should be evaluated last. So make them as last operation
	i1 = expr.find_last_of('+', expr.size()); 
	i2 = expr.find_last_of('-', expr.size());
#ifdef DEBUG
	cout << expr << " " << i1 << " " << i2 << endl;
	getc(stdin);
#endif
	// If + and - are found, make the right most as the central operator
	// as these operators are evaluated from left to right.
	// Hence the left most expression should be evaluated first.
	if ((i1 != expr.npos) && (i2 != expr.npos))
		return max(i1, i2);
	if (i1 != expr.npos)
		return i1;
	if (i2 != expr.npos)
		return i2;

	// Control reaches here if operands + or - is not found
	i1 = expr.find_last_of('*', expr.size());
	i2 = expr.find_last_of('/', expr.size());
#ifdef DEBUG
	cout << expr << " " << i1 << " " << i2 << endl;
	getc(stdin);
#endif
	// If * and / are found, make the right most as the central operator
	// as these operators are evaluated from left to right.
	// Hence the left most expression should be evaluated first.
	if ((i1 != expr.npos) && (i2 != expr.npos))
		return max(i1, i2);
	if (i1 != expr.npos)
		return i1;
	if (i2 != expr.npos)
		return i2;

	// Return npos if operator is not found in the expression
	return expr.npos;
}

int evaluate(string expr)
{
	int op1, op2, result = 0;
	stack<int> operand;
	size_t central_op;

#ifdef DEBUG
	cout << "Substring: " << expr << endl;
#endif

	for (size_t i = 0; i < expr.size(); i++) {
		central_op = find_central_op(expr);
#ifdef DEBUG
		cout << "central_op index = " << central_op << endl;
		getc(stdin);
#endif
		if (central_op == expr.npos) {
#ifdef DEBUG
			cout << expr[0] << endl;
#endif
			return (expr[0] - '0');
		}
		op1 = evaluate(expr.substr(0, central_op));
		op2 = evaluate(expr.substr((central_op + 1), (expr.size() - (central_op + 1))));
		result = calculate(op1, op2, expr[central_op]);
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