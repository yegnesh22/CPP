/*
 * Solution.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int val;
	Node* back;
	Node* front;
	Node(int x): val(x), back(nullptr), front(nullptr) {}
};

class MaxStack {
private:
	map<int, vector<Node*>> lkp;
	Node* stk_top;

public:
	MaxStack() {
		stk_top = nullptr;
	}

	void push(int x) {
		Node* n = new Node(x);
		if (stk_top != nullptr) {
			stk_top->front = n;
			n->back = stk_top;
		}
		stk_top = n;
		lkp[x].push_back(n);
	}

	int pop() {
		if (stk_top == nullptr)
			return -1;
		int v = stk_top->val;
		Node* n = stk_top;
		stk_top = stk_top->back;
        if (stk_top != nullptr)
		    stk_top->front = nullptr;
		lkp[n->val].erase(lkp[n->val].begin() + (lkp[n->val].size() - 1));
		if (lkp[n->val].empty())
			lkp.erase(n->val);
		delete(n);
		return v;
	}

	int top() {
		return stk_top->val;
	}

	int peekMax() {
		map<int, vector<Node*>>::iterator it = lkp.end();
		it--;
		return it->first;
	}

	int popMax() {
		if (stk_top == nullptr)
			return -1;

		map<int, vector<Node*>>::iterator it = lkp.end();
		it--;
		int v = it->first;
		Node *m = *(it->second.rbegin());

		// Rearrange the pointers
		if (m->back != nullptr)
			m->back->front = m->front;
		if (m->front != nullptr)
			m->front->back = m->back;
		else
			stk_top = m->back;
		delete(m);

		// Update the lookup
		it->second.erase(it->second.begin() + (it->second.size() - 1));
		if (it->second.empty())
			lkp.erase(it->first);
		return v;
	}
};


int main()
{
	MaxStack obj;
#if 0
	obj.push(5);
	obj.push(1);
	obj.push(5);
	cout << obj.top() << endl;
	cout << obj.popMax() << endl;
	cout << obj.top() << endl;
	cout << obj.peekMax() << endl;
	cout << obj.pop() << endl;
	cout << obj.top() << endl;
#endif
	obj.push(-2);
	cout << obj.popMax() << endl;
	obj.push(-45);
	obj.push(-82);
	obj.push(29);
	cout << obj.pop() << endl;
	cout << obj.peekMax() << endl;
	obj.push(40);
	cout << obj.pop() << endl;
	cout << obj.pop() << endl;
	obj.push(66);
	cout << obj.peekMax() << endl;
	cout << obj.peekMax() << endl;
	obj.push(-61);
	cout << obj.peekMax() << endl;
	obj.push(98);
	cout << obj.peekMax() << endl;
}
