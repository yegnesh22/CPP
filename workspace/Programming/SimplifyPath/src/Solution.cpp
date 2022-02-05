/*
 * Solution.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//#define DEBUG

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string i;
	string eo;
	string ao;
};

class Solution {
public:
    string simplifyPath(string path);
};

string Solution::simplifyPath(string path)
{
	size_t ns = path.size();
	stack<string> subtokens;
	size_t i = 0;
	size_t ts = 0;
	size_t te = 0;
	string cp;

	while(i < ns) {
		if (path[i] == '/') {
			te = i;
			if (ts != te) {
				string tok = path.substr(ts + 1, te - 1 - ts);
				if (tok == "..") {
					if (!subtokens.empty())
						subtokens.pop();
				} else if (tok != "." && !tok.empty())
					subtokens.push(tok);

				ts = te;
				te = i + 1;
			}
		}
		i++;
	}

    // Process the last string
    if (path[i - 1] != '/') {
        te = i;
        string tok = path.substr(ts + 1, te - 1 - ts);

        if (tok == "..") {
            if (!subtokens.empty())
                subtokens.pop();
        } else if (tok != ".") {
            subtokens.push(tok);
        }
    }

	while (!subtokens.empty()) {
		cp.insert(0,subtokens.top());
		cp.insert(0,"/");
		subtokens.pop();
	}

	return cp.empty() ? "/" : cp;
}


vector<ti> t = {
		{
				.i = "/home/",
				.eo = "/home",
		},
		{
				.i = "/../",
				.eo = "/",
		},
		{
				.i = "/a/../../b/../c//.//",
				.eo = "/c",
		},
		{
				.i = "/home/yegnesh/../user/",
				.eo = "/home/user",
		},
		{
				.i = "/a/b/c/d/./..",
				.eo = "/a/b/c",
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->simplifyPath(t[i].i);
		cout << i << flush;
#ifdef DEBUG
		cout << " -- i: " << t[i].i
			<< " -- ao: " << t[i].ao
			<< " -- eo: " << t[i].eo << flush;
#endif
		cout << " -- " << result(t[i]) << endl;
	}

	return 0;
}

