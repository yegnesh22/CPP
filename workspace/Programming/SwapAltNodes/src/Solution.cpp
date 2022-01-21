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

	ListNode* swapPairs(ListNode* head) {
		ListNode* t1;
		ListNode* t2;
		ListNode* t3;

		if (head == nullptr)
			return head;

		if (head->next == nullptr)
			return head;

		t1 = head;
		t2 = t1->next;
		t3 = t2->next;
		if (!t3) {
			t2->next = t1;
		}
		head->next = nullptr;
		head = t2;

		while (t1 && t2) {
			if (t3 && t3->next != nullptr)
				t1->next = t3->next;
			else
				t1->next = t3;

			t2->next = t1;
			t1 = t3;

			if (t3 && t3->next != nullptr) {
				t2 = t3->next;
				t3 = t2->next;
			} else {
				t2 = nullptr;
				t3 = nullptr;
			}
		}
		return head;
	}
};

struct TestInput {
	vector<int> i;
	vector<int> eo;
	vector<int> ao;
};

int main()
{
	vector<TestInput> t = {
			{
					.i = {1,2,3,4,5},
					.eo = {2,1,4,3,5},
			},
			{
					.i = {},
					.eo = {},
			},
			{
					.i = {1},
					.eo = {1},
			},
			{
					.i = {1,2,3,4},
					.eo = {2,1,4,3},
			},
	};

	for (int i = 0; i < t.size(); i++) {
		Solution *s = new Solution();

		for (int j = 0; j < t[i].i.size(); j++)
			s->Insert(t[i].i[j]);

		s->mH = s->swapPairs(s->mH);
		t[i].ao = s->CreateVect();

		cout << "t[" << i << "] -- "
				<< ((t[i].eo == t[i].ao) ? "pass" : "fail")
				<< endl;

		delete s;
	}

	return 0;
}
