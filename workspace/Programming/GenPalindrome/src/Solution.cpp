/*
 * Solution.cpp
 *
 *  Created on: Mar 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

#define DEBUG

class Solution {
public:
	vector<long long> kthPalindrome(vector<int>& queries, int intLength);
};

vector<long long> Solution::kthPalindrome(vector<int>& queries, int intLength)
{
	vector<long long> result;
	int qs = queries.size();
	long long m_factor = 1;
	long long m_start = 1;
	long long m_max_index;
	long long m_off;
	long long m_max;

	for (int i = 1; i < intLength; i++) {
		m_start = m_start * 10;
		if (i == (intLength / 2))
			m_factor = m_start;
	}

	m_max = m_start * 10;
	if (m_start != 1)
		m_start += 1;

	m_off = m_start / m_factor;
	if (m_off != m_factor)
		m_off += m_factor;
	m_max_index = (m_max - m_start + 1) / m_off;

#ifdef DEBUG
	cout << "m_max:" << m_max
			<< " m_max_index:" << m_max_index << endl;
#endif
	for (int i = 0; i < qs; i++) {
		int index = queries[i] - 1;
		long long num;
		if (index > m_max_index)
			num = -1;
		else {
			long long off_i = (index % m_off);
			long long base_i = index / m_off;
			num = (m_start * (base_i + 1)) + (off_i * m_off);
#ifdef DEBUG
			cout
					<< "index:" << index
					<< " start:" << m_start
					<< " m_off:" << m_off
					<< " off_i:" << off_i
					<< " base_i:" << base_i
					<< " num:" << num << endl;
#endif
		}
		result.push_back(num);
	}

	return result;
}

struct ti {
	vector<int> queries;
	int intLength;
	vector<long long> eo;
	vector<long long> ao;
	ti(vector<int> q, int iL, vector<long long> teo): queries(q), intLength(iL), eo(teo) {}
};

vector<ti> t = {
#ifndef DEBUG
		ti({1,2,3,4,5,90}, 3, {101,111,121,131,141,999}),
		ti({2,4,6}, 4, {1111,1331,1551}),
		ti({2,3,4}, 1, {2,3,4}),
		ti({2,201429812,8,520498110,492711727,339882032,462074369,9,7,6},1,{2,-1,8,-1,-1,-1,-1,9,7,6}),
		ti({733795536,540274789,80,22,29,58,86,176670151,793704731,37,3,18,160574937},4,{-1,-1,8998,3113,3883,6776,9559,-1,-1,4664,1221,2772,-1}),
		ti({289517270,867722538,877647319,64,33,10,532848524,48,101799647,96},5, {-1,-1,-1,16361,13231,10901,-1,14741,-1,19591}),
#endif
		ti({2,3,4}, 1, {2,3,4}),
		ti({5,6,9,44}, 2, {55,66,99,-1}),
		ti({1,2,3,4,5,90}, 3, {101,111,121,131,141,999}),
		ti({11,10},6,{110011,109901}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->kthPalindrome(t[i].queries, t[i].intLength);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
