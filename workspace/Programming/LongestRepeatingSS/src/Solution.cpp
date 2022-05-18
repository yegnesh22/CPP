/*
 * Solution.cpp
 *
 *  Created on: Apr 17, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
	int longestRepeatingSubstring(string s) {
		int sl = s.length();

		for (int i = (sl - 1); i >= 1; i--) {
			map<string, int> lkp;
			string key;
			for (int k = 0; k <= (sl - i); k++) {
				key = s.substr(k, i);
				lkp[key]++;
				if (lkp[key] > 1)
					return key.length();
			}
		}

		return 0;
	}
};

struct ti {
	string s;
	int eo;
	int ao;
	ti(string s, int eo): s(s), eo(eo) {}
};

vector<ti> tests = {
		ti("abcd", 0),
		ti("abbaba", 2),
		ti("aabcaabdaab", 3),
		ti("aaabaabaaaababaaaaaaaabaabaaabbbaaaabbbabbbaaaababbbababbbabaaabbaabaaabbaabbaaaabbbaaaabababbbbbaabbbabbaaabababbbbbbaabaaaabbbaaaaaabbbababbaabbbbaabaaabbababbbbabbbabbaabaaaaaabbabaabbbbbabaabababaabbabaaaabbbabbbbbabbaaaaabaababbbbabbaaaaaababbbbaabbbaabaaabaabbbbabbabaabaaaabaaabaaaaaabbbbabbbabbabaaabbbaaaaababaabaabbbbbababaaabbaaaabbbabababaabaabbababbbaaaaabbbabaabbbbbaaabbbaaaaaaabbbbbbbbabbaabbbabaaaabbbbabababababbabbbbbababaaaaababaabbabbbbaababaabbbbbabbbabbaaabbababaabbabbbbaaabaabbaaabbbababaabaaaaaabababaaababaaabaabaabaababaabbaaaaaabababbbabbaababbbababbabababbbabbababbbabbaaaabbbaaabbaababababaaaabbababbbbaaababababbabababbaaaaaabababbbabbabbbaabaaaaabbbbaabaababbbbbbbbbbbbaaaaaaababbbbbaaabaaaaaabaababaababaabaaabbbbaabbbaabbaaaaabaaabaaaababbaabaaaababbbaabbbabaabbaabbbbbabaaaaabaabbabaabbaaaabbababaaabaabbabbbaaaaaaababbbabaaaaaabbbaaabbbabaaabbaaaabbbaabaabbaaaaaaaaabababaaabbaabaaaaaaabbbbabbabbbbbbabbbbbbbaabbbaaaabbabbbbbaabaabbbbbbaabbabbabbaababbbaababbbaab", 20),
		ti("gymjkqexonleccucwuofmuirwtdvjescmjvdulychgavmbbgcluxbjrewurytkwxnpvgssttlcbrwysncyqxxmpajrgibnihjxchtsnwcwsmhndomnthvlehuynimnskqgeqbtyvcecdjrjtkuamswamunxhwlmiorxtlkogxetsuhijesobgsoylxqpmrolkhwywyktxthrhgiejavdjsxhhriamvegqeghmvbqxyetptucgtfmfjobqbunlxsoehkysdnqsxtdyjlrwifvytfgpsycaanqeusuluwyuclvybgnajospbhtjgfwujxorrtpnvcquecatqhvlitibjtclhqxjwjybggucayaifoidjupjixudfnehiuflscvejxvytsxobriympthgbtyllhcrfyblylsqrcmjvpatixxlgxlmftuildsukpiuvqnkkgblohmnbktdvqoaixxnmntjkjamodnkownuyypipmmtdcbxgxjkwsjlyehothcnkbtoyeyhclmpfygmtpvpyggbyjsbqpbidvrvukwdbconiuqcetidiwuxldmcufxjqpdnuwjyfcfbjxvwsboqnbeghsulsjiceavpqeeixjgekgkppgqominhvsdfelxgjbapkhqfuyrdcugcphejatwnlcbgthirvwuhnecragftulfgkyvtrdnuycbpetoucrktynkdixnuxjwrsopofmkwclmtxexbkgywymsfphmvxcenhancsyeiwuqtewjvdvybfxjlppftktcwyphsyknhbucytepbokkvvhyklpuglhgcuonovhtdgifoxkqqvjnqctatdkeqaueygdptllxswgrrebmhrdedhhpnftmadskejjjwpvkfubonuoscyxkccsnskclfqfnjwgtmuxmttowolhxiwojhqnasxkikmpiolnqlvfroyvajjcqambwtfholxtnwfuylvnycoinulwargrikogjubn", 4),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->longestRepeatingSubstring(t.s);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
