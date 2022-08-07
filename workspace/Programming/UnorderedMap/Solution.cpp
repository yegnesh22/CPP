/*
 * Solution.cpp
 *
 *  Created on: Jul 26, 2022
 *      Author: ysiyer
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int key;
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): key(0), value(0), left(nullptr), right(nullptr) {}
	TreeNode(int key, int value): key(key), value(value), left(nullptr), right(nullptr) {}
};

// Unordered map as a binary search tree - where is hashing ???
class MyMap {
private:
	TreeNode* m_h {nullptr};
	size_t m_size {0};

	void InsertTree(TreeNode* n, int key, int value) {
		if (n->key == key) {
			n->value = value;
			return;
		}

		if (n->key > key) {
			if (n->left == nullptr)
				n->left = new TreeNode(key, value);
			else
				InsertTree(n->left, key, value);
		} else {
			if (n->right == nullptr)
				n->right = new TreeNode(key, value);
			else
				InsertTree(n->right, key, value);
		}
		return;
	}

	int FetchFrom(TreeNode* n, int key) {
		if (n == nullptr)
			return -1;

		if (n->key == key)
			return n->value;

		if (n->key > key)
			return FetchFrom(n->left, key);
		else
			return FetchFrom(n->right, key);

		return -1;
	}
public:
	int size(void) {
		return m_size;
	}

	int Fetch(int key) {
		return FetchFrom(m_h, key);
	}

	void Insert(int key, int value) {
		if (m_h == nullptr)
			m_h = new TreeNode(key, value);
		else
			InsertTree(m_h, key, value);
		m_size++;
		return;
	}
};


int main() {
	MyMap m;
	int key = 1;
	int value = 1024;

	cout << "size:" << m.size() << endl;
	m.Insert(key, value);
	cout << "size:" << m.size() << endl;
	cout << "fetch key:" << key << " value:" << m.Fetch(key) << endl;
	key = 2;
	value = 2048;
	m.Insert(key, value);
	cout << "size:" << m.size() << endl;
	cout << "fetch key:" << key << " value:" << m.Fetch(key) << endl;
	key = 3;
	cout << "fetch key:" << key << " value:" << m.Fetch(key) << endl;
	return 0;
}

