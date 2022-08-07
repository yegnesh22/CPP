#include <bits/stdc++.h>

using namespace std;

void printV(set<vector<int>> ss) {
	for (auto it = ss.begin(); it != ss.end(); it++) {
		vector<int> v = *it;
		cout << "{ " << flush;
		for (size_t j = 0; j < v.size(); j++)
			cout << v[j] << " " << flush;
		cout << "}" << endl;
	}
	return;
}

set<vector<int>> findAllSubsets(vector<int> s) {
	size_t sl = s.size();
	queue<vector<int>> wq;
	set<vector<int>> result;

	wq.push(s);

	while (!wq.empty()) {
		vector<int> ir = wq.front();
		size_t irl = ir.size();

		result.insert(ir);
		wq.pop();
		for(size_t i = 0; i < irl; i++) {
			vector<int> t = ir;
			t.erase(t.begin()+i);
			if (!t.empty())
				wq.push(t);
		}
	}
	vector<int> e = {};
	result.insert(e);
	cout << "Number of subsets:" << result.size() << endl;
	return result;
}

int main()
{
	vector<int> s = {1,2,3,4};
	set<vector<int>> ss;
	
	ss = findAllSubsets(s);
	printV(ss);

	return 0;
}
