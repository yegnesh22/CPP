/*
 * Backtrack.h
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#ifndef BACKTRACK_H_
#define BACKTRACK_H_

#include <Base.h>

class BacktrackSolution : public Solution
{
private:
	bool canJumpFromPosition(int pos, vector<int>& n);
public:
    bool canJump(vector<int>& nums);
};

#endif /* BACKTRACK_H_ */
