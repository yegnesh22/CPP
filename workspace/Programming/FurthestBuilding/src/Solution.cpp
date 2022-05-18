/*
 * Solution.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define PQ

#ifdef PQ

class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		priority_queue<int, vector<int>, greater<int>> ljumps;
		int hs = heights.size();
		int b = bricks;
		int diff;

		for (int i = 1; i < hs; i++) {
			diff = ((heights[i] - heights[i-1]) > 0) ? (heights[i] - heights[i-1]) : 0;
			if (diff == 0)
				continue;
			if (ljumps.size() < ladders) {
				ljumps.push(diff);
				continue;
			}
			if (!ljumps.empty() && ljumps.top() < diff) {
				b -= ljumps.top();
				ljumps.pop();
				ljumps.push(diff);
			} else
				b -= diff;

			if (b < 0)
				return i-1;
		}

		return hs-1;
	}
};

#else
	
class Solution {
public:
	int furthestBuilding(vector<int>& heights, int bricks, int ladders);
};

int Solution::furthestBuilding(vector<int>& heights, int bricks, int ladders)
{
	int hs = heights.size();
	multiset<int> ljumps;
	int bcount = 0;
	int diff  = 0;
	int sljump;
	int i;

	if (hs == 1)
		return 0;

	for (i = 1; i < hs; i++) {
		diff = (heights[i] > heights[i-1]) ? heights[i] - heights[i-1] : 0;
		if (diff == 0)
			continue;
		if (ladders > 0) {
			if (ljumps.size() < ladders) {
				//cout << "1. adding jump: " << diff << endl;
				ljumps.insert(diff);
			} else {
				sljump = *(ljumps.begin());
				if (sljump < diff) {
					//cout << "2. removing jump: " << sljump << endl;
					ljumps.erase(ljumps.begin());
					ljumps.insert(diff);
					//cout << "3. adding jump: " << diff << endl;
					bcount += sljump;
					if (bcount > bricks) {
						//cout << "bcount: " << bcount << " bricks:" << bricks << endl;
						//cout << "A. returning " << i - 1 << endl;
						return i - 1;
					}
				} else {
					bcount += diff;
					if (bcount > bricks) {
						//cout << "bcount: " << bcount << " bricks:" << bricks << endl;
						//cout << "B. returning " << i - 1 << endl;
						return i - 1;
					}
				}
			}
		} else {
			bcount += diff;
			if (bcount > bricks) {
				//cout << "bcount: " << bcount << " bricks:" << bricks << endl;
				//cout << "C. returning " << i - 1 << endl;
				return i - 1;
			}
		}
	}

	//cout << "D. returning " << i - 1 << endl;
	return i-1;
}
#endif

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> h;
	int b;
	int l;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.h = {4,2,7,6,9,14,12},
				.b = 5,
				.l = 1,
				.eo = 4,
		},
		{
				.h = {4,12,2,7,3,18,20,3,19},
				.b = 10,
				.l = 2,
				.eo = 7,
		},
#if 1
		{
				.h = {14,3,19,3},
				.b = 17,
				.l = 0,
				.eo = 3,
		},
		{
				.h = {1, 2},
				.b = 0,
				.l = 0,
				.eo = 0
		},
		{
				.h = {515303,480083,512691,607914,827755,271753,886840,862756,852366,748700,840783,644675,
						318914,191583,464943,166766,148987,166069,181515,976604,962766,60764,175677,246968,
						123365,111519,845775,214045,919197,176367,601766,700160,689020,659469,238284,956141,
						714194,513694,223960,603626,385131,924768,790652,204408,364781,322556,858987,346935,
						555541,1009,606053,914345,317768,298672,302816,360015,594265,945287,583381,188527,
						77014,852533,934756,71671,929679,319068,745700,338236,649572,934036,520907,519835,
						251274,107867,840695,165824,923482,967595,777047,814149,239061,894308,970104,895666,
						695928,468329,604080,789347,106872,937735,465953,841031,912603,681934,708394,704772,
						828211,195076,659888,1784,988151,366639,848900,73563,275135,881937,868785,498048,
						8348,766833,432485,690938,957393,1043,433466,197595,12338,10825,820063,321880,590680,
						119522,63463,800392,23615,92097,506350,316235,856956,708554,757924,74760,115549,117877,
						291063,514958,597855,732228,466401,524316,290886,45969,216459,519996,271581,905921,
						377052,122761,529546,193109,1571,187026,685517,14111,593565,290903,170261,389393,
						896867,810096,250751,53936,752179,712781},
				.b = 12455147,
				.l = 17,
				.eo = 151,
		}
#endif
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->furthestBuilding(t[i].h, t[i].b, t[i].l);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
