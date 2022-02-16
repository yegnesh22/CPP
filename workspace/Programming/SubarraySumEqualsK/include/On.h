/*
 * On.h
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#ifndef ON_H_
#define ON_H_

#include <Base.h>
#include <map>

//#define DEBUG

class On:public Base {
public:
    int subarraySum(vector<int>& nums, int k);
    template <typename t> void printD(t d) {
    	cout << "{ " << flush;
    	for (auto it = d.begin(); it != d.end(); it++)
    		cout << *it << " " << flush;
    	cout << "}" << endl;
    }
};

#endif /* ON_H_ */
