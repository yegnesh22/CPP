/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
char rotate(char c, int rf) {
	char iC;
	char mC;

	if (c >= 'a' && c <= 'z') {
		iC = 'a';
		mC = 26;
	} else if (c >= 'A' && c <= 'Z') {
		iC = 'A';
		mC = 26;
	} else if (c >= '0' && c <= '9') {
		iC = '0';
		mC = 10;
	} else {
		return c;
	}

	return (char) ((((c - iC) + rf ) % mC) + iC);
}

string rotationalCipher(string input, int rotationFactor) {
	// Write your code here
	int is = input.length();
	string res;

	for (int i = 0; i < is; i++)
		res.push_back(rotate(input[i], rotationFactor));

	return res;
}

int main()
{
	cout << rotationalCipher("Zebra-493?", 3) << endl;
	cout << rotationalCipher("abcdefghijklmNOPQRSTUVWXYZ0123456789", 39) << endl;
}
