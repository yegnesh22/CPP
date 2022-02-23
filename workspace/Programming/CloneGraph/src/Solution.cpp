/*
 * Solution.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
 */

class Solution {
public:
	Node* cloneGraph(Node* node);
};

Node* Solution::cloneGraph(Node* node)
{
	map<Node*, Node*> lkp;
	Node* root = nullptr;
	set<Node*> visited;
	queue<Node*> wq;

	if (node != nullptr)
		wq.push(node);

	while (!wq.empty()) {
		Node* c = wq.front();
		wq.pop();
		if (lkp.find(c) == lkp.end()) {
			Node* cnc = new Node (c->val);
			lkp.insert(pair<Node*, Node*>(c, cnc));
		}
		Node* nc = lkp[c];

		if (visited.find(c) != visited.end())
			continue;

		visited.insert(c);
		for (int i = 0; i < c->neighbors.size(); i++) {
			if (lkp.find(c->neighbors[i]) == lkp.end()) {
				Node* nn = new Node(c->neighbors[i]->val);
				lkp.insert(pair<Node*, Node*>(c->neighbors[i], nn));
			}
			nc->neighbors.push_back(lkp[c->neighbors[i]]);

			if (visited.find(c->neighbors[i]) == visited.end())
				wq.push(c->neighbors[i]);
		}
	}

	return lkp[node];
}
