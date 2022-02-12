/*
 * O1.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

/*
 * Algorithm
 * ---------
 * This approach relies on the observation that the rectangle with maximum area will be the maximum of:
 * 1. The widest possible rectangle with height equal to the height of the shortest bar.
 * 2. The largest rectangle confined to the left of the shortest bar(subproblem).
 * 3. The largest rectangle confined to the right of the shortest bar(subproblem).
 */

/* Excessive recursive calls for larger array causing Time limit exceeded */

#include <O1.h>

int O1::calcArea(vector<int>& h, int start, int end)
{
    int ma;
    int mi;

	if (start == end)
		return h[start];
    else if (start > end)
        return 0;

    mi = min_element(hb + start, hb + end + 1) - hb;

    ma = max(h[mi] * (end - start + 1), calcArea(h, start, mi - 1));
	ma = max(ma, calcArea(h, mi + 1, end));

	return ma;
}

int O1::largestRectangleArea(vector<int>& heights)
{
    hb = heights.begin();
	return calcArea(heights, 0, heights.size() - 1);
}
