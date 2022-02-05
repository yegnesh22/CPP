/*
 * Solution.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#define check_result(x) 	{string r = b->getCur(); cout << x << ":" << ((r == x) ? "pass":"fail") << endl;}

class BrowserHistory {
private:
	string m_cur;
	stack<string> m_fstack;
	stack<string> m_bstack;
public:
    BrowserHistory(string homepage);
    void visit(string url);
    string back(int steps);
    string forward(int steps);
    string getCur();
};

BrowserHistory::BrowserHistory(string homepage)
{
	m_cur = homepage;
}

void BrowserHistory::visit(string url)
{
	m_bstack.push(m_cur);
	// Clear the forward stack
	while(!m_fstack.empty()) m_fstack.pop();

	m_cur = url;
}

string BrowserHistory::back(int step)
{
	while ((step > 0) && (!m_bstack.empty())) {
		m_fstack.push(m_cur);
		m_cur = m_bstack.top();
		m_bstack.pop();
		step--;
	}

	return m_cur;
}

string BrowserHistory::forward(int step)
{
	while ((step > 0) && (!m_fstack.empty())) {
		m_bstack.push(m_cur);
		m_cur = m_fstack.top();
		m_fstack.pop();
		step--;
	}

	return m_cur;
}

string BrowserHistory::getCur()
{
	return m_cur;
}

int main()
{
	BrowserHistory* b = new BrowserHistory("leetcode.com");

	check_result("leetcode.com");
	b->visit("google.com");
	check_result("google.com");
	b->visit("facebook.com");
	check_result("facebook.com");
	b->visit("youtube.com");
	check_result("youtube.com");
	b->back(1);
	check_result("facebook.com");
	b->back(1);
	check_result("google.com");
	b->forward(1);
	check_result("facebook.com");
	b->visit("linkedin.com");
	check_result("linkedin.com");
	b->forward(2);
	check_result("linkedin.com");
	b->back(2);
	check_result("google.com");
	b->back(7);
	check_result("leetcode.com");

	return 0;
}
