/*
 * Solution.cpp
 *
 *  Created on: Mar 11, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <MyS.h>

vector<ti> t = {
#ifndef DEBUG
		ti("a", 5),
		ti("aA1", 3),
		ti("aaaB1", 1),
		ti("aa123", 1),
		ti("aaaaa", 2),
		ti("aaaa1", 1),
		ti("aaa111", 2),
		ti("aaa123", 1),
		ti("1111111111", 3),
		ti("ABABABABABABABABABAB", 2),
		ti("aaaabbbbccccddeeddeeddeedd", 8),
		ti("1337C0d3", 0),
		ti("bbaaaaaaaaaaaaaaacccccc", 8),
		ti("FFFFFFFFFFFFFFF11111111111111111111AAA", 23),
		ti("ABABABABABABABABABAB1", 2),
		ti("aaaaAAAAAA000000123456", 5),
#else
		ti("aaaabbbbccccddeeddeeddeedd", 8),
		ti("bbaaaaaaaaaaaaaaacccccc", 8),
		ti("FFFFFFFFFFFFFFF11111111111111111111AAA", 23),
#endif
};

int main()
{
	Solution* s = new MyS();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->strongPasswordChecker(t[i].p);
		cout << i << " -- " << t[i].p << " r:" << result(t[i]) << " eo:" << t[i].eo << " ao:" << t[i].ao << endl;
	}

	return 0;
}
