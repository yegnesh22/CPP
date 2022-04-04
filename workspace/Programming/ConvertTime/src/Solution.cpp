/*
 * Solution.cpp
 *
 *  Created on: Apr 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <vector>

using namespace std;

int getT(string t)
{
	return (t[0] - '0') * 10 + (t[1] - '0');
}

struct m_time {
	int hh;
	int mm;
	m_time(string h, string m):hh(getT(h)), mm(getT(m)) {}
};

class Solution {
public:
	int convertTime(string current, string correct);
};

int Solution::convertTime(string current, string correct)
{
	m_time cu(current.substr(0,2), current.substr(3, 2));
	m_time co(correct.substr(0,2), correct.substr(3, 2));
	int mdiff;
	int count = 0;

	if (cu.mm > co.mm) {
		mdiff = 60 + co.mm - cu.mm;
		cu.hh++;
	} else {
		mdiff = co.mm - cu.mm;
	}

	mdiff += (co.hh - cu.hh) * 60;

	cout << mdiff << endl;
	while (mdiff > 0) {
		if (mdiff >= 60)
			mdiff -= 60;
		else if (mdiff >= 15)
			mdiff -= 15;
		else if (mdiff >= 5)
			mdiff -= 5;
		else
			mdiff--;
		count++;
	}

	cout << "returning count " << count << endl;
	return count;
}

struct ti {
	string current;
	string correct;
	int eo;
	int ao;
	ti(string cu, string co, int e): current(cu), correct(co), eo(e) {}
};

vector<ti> t = {
		ti("02:30", "04:35", 3),
		ti("11:00", "11:01", 1),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->convertTime(t[i].current, t[i].correct);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
