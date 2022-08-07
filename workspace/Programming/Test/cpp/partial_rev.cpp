#include <bits/stdc++.h>

using namespace std;

void printV(vector<char>& v) {
	for (auto& it: v)
		cout << it << "," << flush;
	cout << endl;
}

void partial_rev(vector<char>& v, int s, int e) {
#ifdef STACK
	cout << "stack" << endl;
	stack<char> stk;
	for (int i = s; i <= e; i++)
		stk.push(v[i]);

	for (int i = s; i <= e; i++) {
		v[i] = stk.top();
		stk.pop();
	}
#else
	cout << "2p" << endl;
	while (s < e) {
		char t = v[s];
		v[s] = v[e];
		v[e] = t;
		s++;
		e--;
	}
#endif
	return;
}

int main()
{
	vector<char> c = {'A', 'B', 'C', 'D', 'E'};

	printV(c);
	partial_rev(c,2,4);
	printV(c);

	return 0;
}
