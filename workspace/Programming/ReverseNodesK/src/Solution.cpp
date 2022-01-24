/*
 * Solution.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mH;
	ListNode* mT;

	Solution() {
		mH = nullptr;
		mT = nullptr;
	}

	~Solution() {
		while(mH != nullptr) {
			ListNode *t = mH->next;
			delete mH;
			mH = t;
		}
		delete mT;
		mH = nullptr;
		mT = nullptr;
	}

	void Insert(int val) {
		ListNode* n = new ListNode(val);
		if (mH == nullptr) {
			mH = n;
			mT = n;
			return;
		}
		mT->next = n;
		mT = n;
	}

	vector<int> CreateVect() {
		vector<int> v;
		ListNode *t = mH;

		while (t != nullptr) {
			v.push_back(t->val);
			t = t->next;
		}
		return v;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		return mH;
	}
};

struct TestInput {
	vector<int> i;
	int k;
	vector<int> eo;
	vector<int> ao;
};

int main()
{
	vector<TestInput> t = {
			{
					.i = {1,2,3,4,5},
					.k = 2,
					.eo = {2,1,4,3,5},
			},
			{
					.i = {1,2,3,4,5},
					.k = 3,
					.eo = {3,2,1,4,5},
			},
	};

	for (int i = 0; i < t.size(); i++) {
		Solution *s = new Solution();

		for (int j = 0; j < t[i].i.size(); j++)
			s->Insert(t[i].i[j]);

		s->mH = s->reverseKGroup(s->mH, t[i].k);
		t[i].ao = s->CreateVect();

		cout << "t[" << i << "] -- " << ((t[i].eo == t[i].ao) ? "pass" : "fail") << endl;

		delete s;
	}

	return 0;
}

