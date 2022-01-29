/*
 * O1.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <O1.h>

int O1::calcArea(vector<int>& h, int start, int end)
{
	if (start > end)
		return 0;
#ifdef DEBUG
	cout << "f: " << __func__
			<< " l:" << __LINE__
			<< " start:"<< start
			<< " end:" << end << endl;
#endif

	int mi = start;

	for (int i = start + 1; i <= end; i++) {
		if (h[mi] > h[i])
			mi = i;
	}

	int ma = max(h[mi] * (end - start + 1), calcArea(h, start, mi - 1));
	ma = max(ma, calcArea(h, mi + 1, end));

	return ma;
}

int O1::largestRectangleArea(vector<int>& heights)
{
	return calcArea(heights, 0, heights.size() - 1);
}
