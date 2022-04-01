/*
 * MyS.cpp
 *
 *  Created on: Mar 12, 2022
 *      Author: ysiyer
 */

#include <MyS.h>

cp MyS::getCType(char c) {
	if (c >= 'a' && c <= 'z')
		return LOWER_CASE;
	if (c >= 'A' && c <= 'Z')
		return UPPER_CASE;
	if (c >= '0' && c <= '9')
		return NUMBER;
	else
		return CTYPES;
}

int MyS::strongPasswordChecker(string password)
{
	int pl = password.length();
	vector<int> clookup(pl, 0);
	set<cp> essentials;

	for (int i = 0; i < pl;) {
		int j = i;
		essentials.insert(getCType(password[i]));
		while (i < pl && password[i] == password[j]) i++;
		clookup[j] = i - j;
	}

	/*
	 * Algorithm: The below priority queue maintains the repeating elements
	 * in the increasing order of % 3 values.
	 */
	priority_queue<int, vector<int>, cmp> cq;
	int essentials_c = 3 - essentials.size();
	int repeats = 0;

#ifdef DEBUG
	cout << "essentials_c:" << essentials_c << endl;
#endif
	for (int i = 0; i < pl; i++) {
		if (clookup[i] >= 3) {
#ifdef DEBUG
			cout << "pushing count:" << clookup[i] << endl;
#endif
			cq.push(clookup[i]);
			repeats += clookup[i] / 3;
		}
	}

	if (pl < 6) {
		return max(max(repeats, essentials_c), 6 - pl);
	} else if (pl >= 6 && pl <= 20) {
		return max(repeats, essentials_c);
	} else {
		int excess_len = pl - 20;
		int replacement_c = 0;
		int len_c = 0;
		int top;

		/*
		 * 1st pass: Length correction - Pop out repeating character instance 1 by 1
		 * and reduce the length by 1. Push back the reduced length of repeating char
		 * back to the queue.
		 * Logic: For e.g if there are 5 repeating instances of one type and 3 repeating
		 * characters of another type, remove the 1 character from 5 instances first for
		 * adjusting the length. By removing them, we keep the one with 3 repetitions
		 * as it requires only 1 replacement as the correction. For correcting 5 chars,
		 * we need 2 removals and 1 replacement. Hence for correcting the length, we choose
		 * the repeating ones which are more than the multiple of 3.
		 */
		while (!cq.empty() && excess_len > 0) {
			top = cq.top();
			cq.pop();
#ifdef DEBUG
			cout << "excess:" << excess_len << " top:" << top << endl;
#endif
			excess_len--;
			top--;
			if (top >= 3)
				cq.push(top);
		}

		if (len_c == 0) // No repeatitions
			len_c = pl - 20;
#ifdef DEBUG
		cout << "len_c:" << len_c << endl;
#endif
		/* 
		 * 2nd pass: replacements
		 * Each repeating element count / 3 is the number of replacements.
		 */
		while (!cq.empty()) {
#ifdef DEBUG
			cout << "2 -- top:" << cq.top() << endl;
#endif
			top = cq.top();
			cq.pop();
			replacement_c += top / 3;
		}
#ifdef DEBUG
		cout << "replacement_c:" << replacement_c << endl;
#endif
		return len_c + max(replacement_c, essentials_c);
	}

	return 0;
}
