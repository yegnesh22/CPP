/*
 * Solution.cpp
 *
 *  Created on: 06-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ans = 0, num = 0;
		for (int i = s.size()-1; ~i; i--) {
			switch(s[i]) {
			case 'I': num = 1; break;
			case 'V': num = 5; break;
			case 'X': num = 10; break;
			case 'L': num = 50; break;
			case 'C': num = 100; break;
			case 'D': num = 500; break;
			case 'M': num = 1000; break;
			}
			if (4 * num < ans) { // IV, IX kind of cases
#ifdef DEBUG
				cout << "Subtract case!!!" << endl;
#endif
				ans -= num;
			} else { // Normal case
#ifdef DEBUG
				cout << "Add case!!!" << endl;
#endif
				ans += num;
			}
#ifdef DEBUG
			cout << s[i] << " " << ans << " " << num << endl;
#endif
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<string> t = {
		"III",
		"IV",
		"VI",
		"IX",
		"LVIII",
		"MCMXCIV",
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << *it << " : " << s.romanToInt(*it) << endl;

	return 0;
}
