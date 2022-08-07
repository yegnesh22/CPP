/*
 * Solution.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
    string data;
    Node* left;
    Node* right;
    bool op;
};

class MyNode: public Node {
public:
	MyNode() {
		data = "";
		left = nullptr;
		right = nullptr;
		op = false;
	}
	MyNode(string d, bool f) {
		data = d;
		left = nullptr;
		right = nullptr;
		op = f;
	}
	bool isOperand() const {
			return op;
	}
	void setRight(Node* r) {
		right = r;
	}
	void setLeft(Node* l) {
		left = l;
	}
    virtual int evaluate() const {
        if (this->op == true) {
#ifdef DEBUG
        	cout << "returning operand " << stoi(this->data) << endl;
#endif
            return stoi(this->data);
        } else {
            try {
                int op1 = this->left->evaluate();
                int op2 = this->right->evaluate();
                switch (data[0]) {
                    case '*':
#ifdef DEBUG
                    	cout << op1 << " * " << op2 << "=" << op1 * op2 << endl;
#endif
                        return  op1 * op2;
                    case '/':
#ifdef DEBUG
                    	cout << op1 << " / " << op2 << "=" << op1 / op2 << endl;
#endif
                        return op1 / op2;
                    case '+':
#ifdef DEBUG
                    	cout << op1 << " + " << op2 << "=" << op1 + op2 << endl;
#endif
                        return op1 + op2;
                    case '-':
#ifdef DEBUG
                    	cout << op1 << " - " << op2 << "=" << op1 - op2 << endl;
#endif
                        return op1 - op2;
                }
            } catch (exception& e) {
                cout << "unsupported operation:" << endl;
            }
        }
        return -1;
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
private:
    size_t m_ps;
public:
    bool isOperand(string s) {
        return !((s.length() == 1) &&
                 ((s[0] == '*') || (s[0] == '/') || (s[0] == '+') || (s[0] == '-')));
    }

    Node* createSubTree(vector<string>& postfix) {
        MyNode* n = new MyNode(postfix[m_ps], isOperand(postfix[m_ps]));
#ifdef DEBUG
        cout << "node created " << postfix[m_ps] << " operand" << (isOperand(postfix[m_ps]) ? "true" : "false") << endl;
#endif
        if (m_ps == 0 || n->isOperand())
            return n;
        m_ps--;
        n->setRight(createSubTree(postfix));
        m_ps--;
        n->setLeft(createSubTree(postfix));
        return n;
    }

    Node* buildTree(vector<string>& postfix) {
        m_ps = postfix.size();
        if (m_ps == 0)
            return nullptr;
        m_ps--;
        return createSubTree(postfix);
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */

struct ti {
	vector<string> postfix;
	int eo;
	int ao;
	ti(vector<string> d, int e): postfix(d), eo(e) {}
};

vector<ti> tests = {
		ti({"3","4","+","2","*","7","/"}, 2),
		ti({"4","5","2","7","+","-","*"}, -16),
};

int main()
{
	for (auto& t: tests) {
		TreeBuilder* obj = new TreeBuilder();
		Node* expTree = obj->buildTree(t.postfix);
		t.ao = expTree->evaluate();
		//cout << "t.ao:" << t.ao << " t.eo:" << t.eo << endl;
		assert(t.eo == t.ao);
		cout << "passed" << endl;
	}

	return 0;
}
