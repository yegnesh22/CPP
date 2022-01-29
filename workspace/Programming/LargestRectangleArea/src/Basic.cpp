/*
 * Basic.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

/*
 * Algorithm:
 * Firstly, we need to take into account the fact that the height of the
 * rectangle formed between any two bars will always be limited by the height of
 * the shortest bar lying between them.
 *
 * Thus, we can simply start off by considering every possible pair of bars and
 * finding the area of the rectangle formed between them using the height of the
 * shortest bar lying between them as the height and the spacing between them as
 * the width of the rectangle. We can thus, find the required rectangle with the
 * maximum area.
 *
 * We can do one slight modification in the previous approach to optimize it to
 * some extent. Instead of taking every possible pair and then finding the bar of
 * minimum height lying between them everytime, we can find the bar of minimum
 * height for current pair by using the minimum height bar of the previous pair. In
 * mathematical terms, minheight=min(minheight,heights(j)), where heights(j)
 * heights(j) refers to the height of the jth bar.
 *
 */

int BasicSolution::largestRectangleArea(vector<int>& heights)
{
	vector<int> aL;
	int area;
	int mA;
	int h;
	int w;

	mA = heights[0] * 1;
	for (int i = 0; i < heights.size(); i++) {
		mA = max(mA, heights[i] * 1);
		h = heights[i];
		for (int j = i; j < heights.size(); j++) {
			h = min(h, heights[j]);
			w = (j - i + 1);
			area = h * w;
			mA = max(mA, area);
		}
	}

	return mA;
}

