/*
 * Solution.cpp
 *
 *  Created on: Apr 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Node {
	int key;
	int value;
	Node* front;
	Node* back;
	Node(): key(0), value(0), front(nullptr), back(nullptr) {}
	Node(int key, int value): key(key), value(value), front(nullptr), back(nullptr) {}
	Node(int key, int value, Node* front, Node* back): key(key), value(value), front(front), back(back) {}
};

class LRUCache {
private:
	map<int, Node*> m_cache;
	int m_capacity;
	Node* start;
	Node* last;

public:
	LRUCache(int capacity) {
		m_capacity = capacity;
		start = nullptr;
		last = nullptr;
	}

	int get(int key) {
		// Key does not exist
		if (m_cache.find(key) == m_cache.end()) {
			return -1;
		} else { // key exists. // fetch the value and push the node to the tail
			Node* u = m_cache[key];
			int v = u->value;
			if (u == last)
				return v;
			if (u->front != nullptr)
				u->front->back = u->back;
			if (u->back != nullptr)
				u->back->front = u->front;
			if (start == u)
				start = u->back;
			u->front = last;
			last->back = u;
			u->back = nullptr;
			last = u;
			return v;
		}
	}

	void put(int key, int value) {
		// key does not exist
		if (m_cache.find(key) == m_cache.end()) {
			Node* n = new Node(key, value, last, nullptr);
			m_cache.insert(pair<int, Node*>{key, n});
			if (last != nullptr)
				last->back = n;
			last = n;
			if (start == nullptr)
				start = n;
			if (m_cache.size() > m_capacity) {
				Node* s = start;
				m_cache.erase(start->key);
				if (start->back != nullptr)
					start->back->front = nullptr;
				start = start->back;
				delete(s);
			}
		} else { // key exists. update and push it to the back of the list
			Node* u = m_cache[key];
			u->value = value;
			if (u == last)
				return;
			if (u->front != nullptr)
				u->front->back = u->back;
			if (u->back != nullptr)
				u->back->front = u->front;
			if (u == start)
				start = u->back;
			u->front = last;
			last->back = u;
			u->back = nullptr;
			last = u;
			return;
		}
		return;
	}
};

int main()
{
	LRUCache* c = new LRUCache(2);
#if 0
	c->put(1,1);
	c->put(2,2);
	cout << c->get(1) << endl;
	c->put(3,3);
	cout << c->get(2) << endl;
	c->put(4,4);
	cout << c->get(1) << endl;
	cout << c->get(3) << endl;
	cout << c->get(4) << endl;
#endif
	c->put(2,1);
	c->put(1,1);
	c->put(2,3);
	c->put(4,1);
	cout << c->get(1) << endl;
	cout << c->get(2) << endl;
	return 0;
}
