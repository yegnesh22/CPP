#include "Solution.h"
#include "input.h"

extern vector<ti> tests;

stack<int> tstack;

void printS(int r, set<int>* s) {
	cout << r << " -- " << flush;
	for (auto it = s->begin(); it != s->end(); it++)
		cout << *it << " " << flush;
	cout << endl;
}

int getMaxVisitableWebpages(int N, vector<int> L) {
	// Write your code here
	vector<int>* inStack = new vector<int> (N+1, 0);
	vector<int>* len = new vector<int>(N+1, 0);
	set<int> *s = nullptr;
	bool traverse;
	int from, to;
	int max = 0;
	int index;
	int incr;
	int scs;
	int sc;

	for (int i = 1; i <= N; i++) {
		traverse = false;
		index = 1;
		sc = 0;
		cout << "root:" << i << endl;
		if (len->at(i) == 0) {
			s = new set<int>;
			tstack.push(i);
			traverse = true;
			while (traverse == true) {
				from = tstack.top();
				inStack->at(from) = index;
				s->insert(from);
				to = L[tstack.top()-1];
				cout << "dfs -- from:" << from << ":" << to << endl; 
				cout << "inStack[" << from << "]=" << inStack->at(from) << endl;
				cout << "inStack[" << to << "]=" << inStack->at(to) << endl;
				// the node is not visited before nor is in the stack
				if (len->at(to) == 0 && inStack->at(to) == 0) {
					cout << "pushing " << to << endl;
					tstack.push(to);
					index++;
				} else
					traverse = false;
			}

			scs = to;
			cout << "scc root " << scs << endl;
			// Visiting the connected component for the first time
			if (len->at(to) == 0) {
				len->at(to) = s->size() - inStack->at(scs) + 1;
				cout << "setting the length of scc @" << to << " to " << len->at(to) << endl;
			}

			while (!tstack.empty()) {
				from = tstack.top();
				len->at(from) = len->at(to) - inStack->at(scs) + 1;
				inStack->at(from) = 0;
				to = from;
				cout << "popped " << from << endl;
				tstack.pop();
			}
		}
		if (max < len->at(i))
			max = len->at(i);
		if (s != nullptr) {
			free(s);
			s = nullptr;
		}
	}

	cout << "returning max " << max << endl;
	return max;
}

int main()
{
	int i = 1;

	for (auto t: tests) {
		t.AO = getMaxVisitableWebpages(t.N, t.L);
		assert(t.EO == t.AO);
		cout << i++ << "-- pass" << endl;
	}

	return 0;
}

