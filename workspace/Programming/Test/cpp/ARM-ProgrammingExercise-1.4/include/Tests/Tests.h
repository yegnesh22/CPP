/*
 * Tests.h
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#ifndef INCLUDE_TESTS_H_
#define INCLUDE_TESTS_H_

#include <bits/stdc++.h>

#include <Tests/ByteTypeTests.h>
#include <Tests/PointerTypeTests.h>
#include <Tests/FixedStringTypeTests.h>
#include <Tests/StructPointTypeTests.h>
#include <Tests/Base1Tests.h>
#include <Tests/Base2Tests.h>
#include <Tests/DerivedTests.h>

using namespace std;

typedef void (*TestFunc) ();
const vector<TestFunc> tests = {
		// ByteType Tests
		TestByteTypeVar,
		TestByteTypePtr,
		TestByteTypeMulti,

		// PointerType Tests
		TestPointerTypeVar,

		// FixedStringType tests
		TestFixedStringTypePtr,

		// StructPointType tests
		TestStructPointTypePtr,

		// Base1Type tests
		TestBase1Ptr,

		// Base2Type tests
		TestBase2Ptr,

		// DerivedType tests
		TestDerivedPtr,
};

#endif /* INCLUDE_TESTS_H_ */
