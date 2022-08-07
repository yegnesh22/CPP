/*
 * Tests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */


#include <Tests/Tests.h>

int main()
{
	for (auto t: tests)
		t();
	return 0;
}

