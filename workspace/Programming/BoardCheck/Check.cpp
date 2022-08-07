/*
 * Check.cpp
 *
 *  Created on: Aug 1, 2022
 *      Author: ysiyer
 */

#include <iostream>

using namespace std;

string eo = "DR!DDR!UULL!R!DDR!DLL!!D!UUUURRRR!DDLL!ULL!DRRRR!ULL!DL!UL!DDD!UUUURRR!UL!DDDDLLD!UR!UUUR!URR!DDDDLLLLD!UUU!D!UURRRR!DDDLLLLD!!URRR!UL!UUUR!DDR!ULLLL!URRR!DDD!ULLL!DRRR!!!DLL!U!URRR!DLLL!L!DR!R!RR!UUUULLL!DDDR!UULL!RRR!LL!DL!U!URRRR!DDLLLL!UURR!DDDDLL!D!UUR!UUURR!DDR!DLLLL!DRR!UULL!UR!DDDR!URR!UUULLLL!DRRRR!U!DDLLL!DL!U!D!DRRR!R!UULL!DDL!LD!UUUURRR!DLLL!DRR!UUU!DDDDRR!UU!ULLL!D!DDLD!UUUUURRRR!D!DD!UULLL!DDRR!UULL!DDDLD!UURRR!R!DLLLL!UURRR!";
string ao = "DR!DDR!UULL!R!DDR!DLL!!D!UUUURRRR!DDLL!ULL!DRRRR!ULL!DL!UL!DDD!UUUURRR!UL!DDDDLLD!UR!UUUR!URR!DDDDLLLLD!UUU!D!UURRRR!DDDLLLLD!!URRR!UL!UUUR!DDR!ULLLL!URRR!DDD!ULLL!DRRR!!!DLL!U!URRR!DLLL!L!DR!R!RR!UUUULLL!DDDR!UULL!RRR!LL!DL!U!URRRR!DDLLLL!UURR!DDDDLL!D!UUR!UUURR!DDR!DLLLL!DRR!UULL!UR!DDDR!URR!UUULLLL!DRRRR!U!DDLLL!DL!U!D!DRRR!R!UULL!DDL!DL!UUUURRR!DLLL!DRR!UUU!DDDDRR!UU!ULLL!D!DDLD!UUUUURRRR!D!DD!UULLL!DDRR!UULL!DDDLD!UURRR!R!DLLLL!UURRR!";

string in = "grfgruuzjrktmqkziczvhezkpjzzxrdofdsksssvqoqpvwybrfigkfekcuzqdopwkgwtajelpkpxymvzikrcyoglzejtgsgzstun";

int main()
{
	size_t mm = 0;
	for (size_t i = 0; i < eo.length(); i++) {
		if (eo[i] == '!')
			mm++;
		if (eo[i] != ao[i])
			break;
	}

	cout << "mismatched move from  " << in[mm-1] << " to " << in[mm] << " index " << mm << endl;
	return 0;
}
