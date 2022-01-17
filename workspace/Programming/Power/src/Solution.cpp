/*
 * Solution.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ysiyer
 */
#include <iostream>
#include <vector>

using namespace std;

//#define BRUTE_FORCE
#define FAST_POW

#ifdef BRUTE_FORCE
class Solution {
public:
    double myPow(double x, int n) {
    	double prod = 1;
    	int ntimes = n;
    	int f;

    	if (x == double(1))
    		return x;

    	if (ntimes < 0)
    		f = 1;
    	else
    		f = -1;

    	while (ntimes) {
    		prod *= x;
    		ntimes += f;
    		//cout << ntimes << endl;
    	}

    	if (n < 0)
    		return (1 / prod);
    	else
    		return prod;
    }
};
#endif

#ifdef FAST_POW
class Solution {
public:
    double fastPow(double x, long long n) {
    	cout << n << endl;
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};
#endif

struct Test {
	double x;
	int n;
};

int main()
{
	vector<Test> t = {
			{.x = 2.00000, .n = -3},
			{.x = 2.10000, .n = 3},
			{.x = 2.00000, .n = -2},
			{.x = 2.00000, .n = 0},
			{.x = 2.00000, .n = 1},
			{.x = 2.00000, .n = -2147483648},
	};
	Solution s;

	for(int i  = 0; i < t.size(); i++) {
		cout << "pow(" << t[i].x << "," << t[i].n << ")="
			<< s.myPow(t[i].x, t[i].n) << endl;
	}
	return 0;
}
