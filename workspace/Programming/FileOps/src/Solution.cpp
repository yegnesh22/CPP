/*
 * Solution.cpp
 *
 *  Created on: Jun 26, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> splitLine(string& line, const char& delim) {
	vector<string> tokens;
	size_t pos = 0;
	size_t di = line.find_first_of(delim, pos);

	while (di != line.npos) {
		string key = line.substr(pos, di-pos);
		tokens.push_back(key);
		pos = di+1;
		di = line.find_first_of(delim, pos);
	}
	tokens.push_back(line.substr(pos));
	return tokens;
}

bool findIndex(const string& k, const vector<string>& keys, size_t& index) {
	for (size_t i = 0; i < keys.size(); i++) {
		if (keys[i] == k) {
			index = i;
			return true;
		}
	}
	return false;
}

bool checkCap(string ServerName) {
	// Read first line and identify the headers
	ifstream wl ("C:\\Users\\ysiyer\\eclipse-workspace\\FileOps\\src\\wl.csv");
	string wlh;

	getline(wl, wlh);

	vector<string> wlKeys = splitLine(wlh, ',');
	size_t wlComputeIndex;
	size_t wlCapIndex;

	if (!findIndex("COMPUTE", wlKeys, wlComputeIndex))
		return false;
	if (!findIndex("CAP", wlKeys, wlCapIndex))
		return false;

	string wlDline;
	map<string, int> computeReq;
	while (getline(wl, wlDline)) {
		vector<string> wlData = splitLine(wlDline, ',');
		assert(wlData.size() == wlKeys.size());
		computeReq[wlData[wlComputeIndex]] += stoi(wlData[wlCapIndex]);
	}
	wl.close();

	// Read each server's compute capability and reduce it from req.
	ifstream dc ("C:\\Users\\ysiyer\\eclipse-workspace\\FileOps\\src\\servers.csv");
	string dch;
	getline(dc, dch);

	vector<string> dcKeys = splitLine(dch, ',');
	size_t dcComputeIndex;
	size_t dcNameIndex;
	size_t dcCapIndex;

	if (!findIndex("NAME", dcKeys, dcNameIndex))
		return false;
	if (!findIndex("COMPUTE", dcKeys, dcComputeIndex))
			return false;
	if (!findIndex("CAP", dcKeys, dcCapIndex))
			return false;

	string dcl;
	while (getline(dc, dcl)) {
		vector<string> dcData = splitLine(dcl, ',');
		assert(dcData.size() == dcKeys.size());
		if (dcData[dcNameIndex] != ServerName) {
			computeReq[dcData[dcComputeIndex]] -= stoi(dcData[dcCapIndex]);
			cout << "cReq[" << dcData[dcComputeIndex] << "] = " <<  computeReq[dcData[dcComputeIndex]] << endl;
		}
	}

	// After reducing each requirement if any of the requirements has +ve need,
	// then return false. Else return true.
	bool status = true;
	for (auto it = computeReq.begin(); it != computeReq.end(); it++) {
		if (it->second > 0) {
			cout << it->first << ":" << it->second << endl;
			status = false;
		}
	}

	return status;
}

int main()
{
	string ServerName = "NORTH_AMERICA_01";

	if (checkCap(ServerName))
		cout << "Can be taken out" << endl;
	else
		cout << ServerName << " cannot be taken out" << endl;

	return 0;
}
