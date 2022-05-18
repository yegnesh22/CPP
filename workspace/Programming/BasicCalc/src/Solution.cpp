/*
 * Solution.cpp
 *
 *  Created on: Apr 21, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int do_op(int n1, int n2, char op) {
	switch(op) {
	case'*':
		cout << n1 << op << n2 << "=" << (n1 * n2) << endl;
		return n1 * n2;
	case '/':
		cout << n2 << op << n1 << "=" << (n2 / n1) << endl;
		return n2 / n1;
	case '%':
		cout << n2 << op << n1 << "=" << (n2 % n1) << endl;
		return n2 % n1;
	case '+':
		cout << n1 << op << n2 << "=" << (n1 + n2) << endl;
		return n1 + n2;
	case '-':
		cout << n2 << op << n1 << "=" << (n2 - n1) << endl;
		return n2 - n1;
	}
}

int precedence_of(char o) {
	if (o == '+' || o == '-')
		return 1;
	if (o == '*' || o == '/' || o == '%')
		return 2;
}

int calculate(string s)
{
	size_t cs = s.length();
	stack<int> nums;
	stack<char> op;
	size_t i = 0;
	int n1;
	int n2;
	char o;

	while (i < cs) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		int num = 0;
		bool isNum = false;
		while (s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
			i++;
			isNum = true;
		}
		if (isNum) {
			cout << "pushing num " << num << endl;
			nums.push(num);
		}
		while (s[i] == ' ') i++;
		while (!op.empty() && precedence_of(s[i]) <= precedence_of(op.top())) {
			n1 = nums.top();
			nums.pop();
			n2 = nums.top();
			nums.pop();
			o = op.top();
			op.pop();
			nums.push(do_op(n1, n2, o));
		}
		if (i < cs)
			op.push(s[i]);
		i++;
	}

	while (!op.empty()) {
		cout << "residue " << endl;
		n1 = nums.top();
		nums.pop();
		n2 = nums.top();
		nums.pop();
		o = op.top();
		op.pop();
		nums.push(do_op(n1, n2, o));
	}

	cout << "returning " << nums.top() << endl;
	return nums.top();
}

int main()
{
	string inp("3 * 2 + 4");
	cout << calculate(inp) << endl;

	return 0;
}
