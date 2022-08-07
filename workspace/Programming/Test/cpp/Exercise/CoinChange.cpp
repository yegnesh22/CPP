#include <bits/stdc++.h>

using namespace std;

void CoinChange(int a, vector<int> d, set<vector<int>>& result, vector<int> ir = {}) {
	cout << "f: " << __func__ << " a:" << a << endl;
	if (a == 0) {
		cout << "Pushing result: { " << flush;
		for (auto it: ir)
			cout << it << " " << flush;
		cout << "}" << endl;
		sort(ir.begin(), ir.end());
		result.insert(ir);
		return;
	}

	for (size_t i = d.size(); i > 0; i--) {
		int b = a - d[i-1];
		vector<int> irt = ir;
		if (b >= 0) {
			cout << "Deducting " << d[i-1] << " from " << a << endl;
			irt.push_back(d[i-1]);
			cout << "Calling coinChange for b:" << b << endl; 
			CoinChange(b, d, result, irt);
		}
	}
	return;
}

int main() {
	vector<int> d = {1,2,5};
	set<vector<int>> result;
	int a = 6;

	CoinChange(a, d, result);

	for (auto it = result.begin(); it != result.end(); it++) {
		vector<int> ir = *it;
		cout << "{ " << flush;
		for (auto c: ir)
			cout << c << " " << flush;
		cout << "}" << endl;
	}
	return 0;
}

