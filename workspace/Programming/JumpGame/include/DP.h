/*
 * DP.h
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#ifndef DP_H_
#define DP_H_

#include <Base.h>

class DP : public Solution
{
private:
	typedef enum {
		G,
		B,
		U
	} nodeType;

	vector<nodeType> m_memo;
	bool canJumpFromPosition(int pos, vector<int>& n);
public:
    bool canJump(vector<int>& nums);
};

#endif /* DP_H_ */
