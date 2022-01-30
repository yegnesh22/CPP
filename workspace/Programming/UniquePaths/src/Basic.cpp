/*
 * Basic.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

int BasicSolution::uniquePaths(int m, int n)
{
	if (m == 1 || n == 1)
		return 1;
	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}
