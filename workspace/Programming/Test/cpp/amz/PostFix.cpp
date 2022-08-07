#include <bits/stdc++.h>

using namespace std;

typedef enum {
	STATUS_SUCCESS,
	STATUS_INVALID,
	STATUS_DIVIDE_BY_ZERO
} FuncStatus_t;

bool isOperator(const char* oper)
{
	if (strlen(oper) == 1) {
		switch(oper[0]) {
			case '*':
				return true;
			case '/':
				return true;
			case '+':
				return true;
			case '-':
				return true;
		}
	}

	return false;
}

int EvaluateExpression(int op1, int op2, const char* op, FuncStatus_t& status) {
	status = STATUS_SUCCESS;
	switch(op[0]) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '/':
			if (op2 == 0)
				status = STATUS_DIVIDE_BY_ZERO;
			else
				return op1 / op2;
		case '*':
			return op1 * op2;
	}
	status = STATUS_INVALID;
	return -1;
}

FuncStatus_t EvaluatePostfix(int& result, unsigned char PostfixSize, const char** Postfix)
{
	FuncStatus_t status;
	stack<int> stk;

	for (int i = 0; i < PostfixSize; i++) {
		if (isOperator(Postfix[i])) {
			int op1;
			int op2;
			int opc = 0;
			const char* op = Postfix[i];
			if (!stk.empty()) {
				op2 = stk.top();
				stk.pop();
				opc++;
			}
			if (!stk.empty()) {
				op1 = stk.top();
				stk.pop();
				opc++;
			}

			if (opc != 2)
				return STATUS_INVALID;
			stk.push(EvaluateExpression(op1, op2, op, status));
			if (status != STATUS_SUCCESS)
			       return status;
		} else {
			stk.push(atoi(Postfix[i]));
		}
	}

	if (stk.size() != 1)
		return STATUS_INVALID;
	result = stk.top();
	return STATUS_SUCCESS;
}

int main(int argc, const char* argv[]) {
	if (argc <= 3) {
		cout << argv[0] << " <post fix expression size> <postfix expression>" << endl;
		exit(-1);
	}

	int result;
	FuncStatus_t s = EvaluatePostfix(result, atoi(argv[1]), &argv[2]);
	if (s == STATUS_SUCCESS)
		cout << "Result " << result << endl;
	else if (s == STATUS_INVALID) 
		cout << "invalid" << endl;
	else
		cout << "divide by zero" << endl;

	return 0;
}
