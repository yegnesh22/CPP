/*
 * Solution.cpp
 *
 *  Created on: Mar 7, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	int minFlips(string s);
};

int Solution::minFlips(string s)
{
	int originalStringLength= s.length();
	int ans = originalStringLength;
	string doubleLengthString= s+s;
	char c[2] = {'0', '1'};
	bool b = false;
	int diff1 = 0;
	int diff2 = 0;
	int start = 0;
	string as;

	for(int i=0; i < doubleLengthString.length(); i++) {
		if(doubleLengthString[i]!= c[b])
			diff1++;
		else
			diff2++;
		as += c[b];
		b ^= true;

		if (i-start+1 > originalStringLength) {
			if(doubleLengthString[start] != as[start])
				diff1--;
			else
				diff2--;
			start++;
		}

		if (i-start+1 == originalStringLength)
			ans = min(ans,min(diff1,diff2));
	}
	return ans;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.s = "111000",
				.eo = 2,
		},
		{
				.s = "010",
				.eo = 0,
		},
		{
				.s = "1110",
				.eo = 1,
		},
		{
				.s = "110",
				.eo = 0,
		},
		{
				.s = "0111111010111011111000101100101011001001111100101010010000011110011010101010000\
						00110101000001000011101111100011101111000011000001101100001000110101010101000101\
						10011011011100001000100110011001011110011110101110110110000111000101110110001101\
						01111010110000011111110000011111001000000010110100010011100010001000000011111001\
						01010110111001111001000100110110000111011001101011110011011101001110011000111010\
						10010101000010010001101101000001110010000100001011010010101111001001001000011111\
						00110000011110110001100110010111111001100001011111010110101010011010101011010110\
						11110101010001111111000101011101011011110101010000001001001110011110000100101110\
						00010010011001110001110110011010110001011000001001011110001001111111110001111000\
						01000000010110000011111011011011110111100010100010111010101001111000010011111000\
						00110100111010001001111000100011000111001100000010111100110101010111011011001101\
						11111000101010101110011001111110110101111000100001111110111100101100110001011101\
						00100110100110100011110100010000000011010001110010101110011110111110000000111110\
						11110110101010100011000111010101010000101101010001000001001111111100111111111100\
						01010001001101011110101101111100100111110011111110110001000101100000000001000100\
						01110100111110101111000000001010011010000000100101001000110100001110011000011101\
						11100100111000000101001111111011001101001011111010011011111100101110101001011100\
						01110010101111110010110001010100010100110101010010011011010100001011010110010101\
						11001110111011010000100100100010010001011011010000001110010110001010101111111110\
						10100110000110011010001111101001010111001101111101000000000011010010001010110111\
						10011001111010011100100111111001001000100011010101101010100110001001000010111100\
						11100000000010101001001010001100110011100001100110000010111010011110001011001100\
						00101001001000011011011111110111110010110101011011101001001110010011101101101100\
						01011100000010101011100111000010001110110110110010111100001010100111101111010101\
						11101111011110011110011100110110010111011100111100000000000111101100110010000111\
						01101101101100111101011001011110110100001011100011001100101110100100010011000010\
						11001011000100101001010001000100001011011101000010010111110110111101001001110010\
						01110110001000100101100011001101110111010001110110111100100001110100010011111000\
						11111001001011110011010011101111011001010101011010010110110111110000011010110001\
						10111001010011011101111001110110101100010010011111110100001001100010111000111001\
						10011001001011101010011010101000011111101101111110010001100110111100000010101010\
						01100000100001111001110111000110111111101101100100010011110101001001011011101011\
						10001000000100100101001100110000110011100000011100000100001001001100111110001011\
						11111111100000100110001101010001010000111000110111111100010111100110100001000011\
						10100110010010111110110111100001011011001101001001111100100010101001010001110001\
						11011101001001111011000101101110000100001110110010101000100101011110011111101000\
						01100111101101000101001011000110011000110100010011101111011000010100011110001100\
						10010111110010011001100000111111001000111011111101110000110100101010100011011111\
						00000010100100001101110111111100010100111110011100100011000010110011010110100101\
						10101010000010001001011111011011000001000111100111001011001000111101010001001000\
						00111110100101110101101100110101101101001111000100000110101010111000001010011010\
						00010101010001001101111100111100111010001000101101100111111011101010100101011111\
						10001000101011101011100100000110001100101100111110100011110010110101010100101111\
						11100101101100000000010010110110010010001110011111110101000101111011111101110000\
						00101010011011001111010101110111000111101010111101011001111110111001000010010110\
						10000011110110101110010111001001000110001000101000100101001011111101111000000010\
						01111101100011100010111011111010011110001111000000110100010011100010111101110000\
						10010100001100010000010110100110000110100100000100110110000100000001101101010110\
						01010101100000110110100111111010010100101010010000101000111010011001001000000011\
						01010010001111011111000111011110111110100001011010101010100011110001110100010110\
						11110100011011000101111100010011111110110001001101101010010000010000010101001110\
						11101001101001010110000000101101000001101111111101101000111001011100000101001110\
						01100111001110010000011001111100001100111100110111111110101110100011111101111010\
						01011100001110110110111000011000101100110111011001101100011111001000011000001000\
						00101101111110110100010100010101110010000111001100100010100111101100101100101111\
						01010101111111010011010110010110000111001001011010010011110101010000011001001100\
						11110101000001000000101010001100110100001010101100010000001010011011000011111111\
						00101110100111001111011111011011000111001000100000100011011100100010010111110111\
						01111111010010111111000000111110000111010100000011110101111011101110000010100101\
						10001110111011100010111110111110010000101000010000110111001000111100101011011010\
						01010001110100110001011100010010101111101011100011101001001010100111111011111101\
						01111110111011000101100100101011111001111011110101010011111001000010000100110001\
						01001010100111111100001101110110101111000001010001000100111010111000000000010100\
						01100110010111110011100111010000011100101101010001001000100001110101101000000101\
						00010000101010000001001001001011001011110001111001001000000101101100100001100001\
						11101110111101010011110000001111111011110101001100000001110001001101111011111011\
						11000111010010100000010100110110111010001001001100000011001011000000101101110110\
						11001000010000101100110011111101100101100100100010001000010011111110000111000100\
						01001111001110001110010001010000010111101000000001011001011100100100101000001110\
						10011110010010001110101010111110010110000101000111111011001010110111010111100010\
						11010101100000011101001111100010011111011011011110010101001101110100101111000100\
						00011001100101111111001001010111111111100010000100101010010111001010101111101011\
						00110010101001100100011100010110100001001111100101110100100110011110110110111111\
						11011000000110101110011001101100000011001111111010110100010110110010110001100110\
						10111100000001101100100111000001011100010001111101110110011111111000001010010011\
						00101111001000111011001110010000110010101001000010110010111000111010001100011000\
						10111111000011001011011001000011101000011110000101000110100100101001100101101001\
						00110000101011010111101010100011110101110001000011010110001111100111001010100110\
						10110110011100101001011010110011011101010110110110010001110101101001001110101110\
						10110000000111111010100011111101000011111111111011001110110001011001111110100100\
						01010000111000000011000100100011010000010101010001110101100011101110111111010100\
						10001000110001010011000111100101001110100011001000111110011110011011000001100110\
						00111010101111100110110111111101100010101110000111100100101101001010110101111110\
						11001010001100000110010010101101010110101111100011111000010101111101001011100100\
						10000010011101110101100101011000010111011110111100101101010010111001011111111111\
						00100001011110001000110101000000101001000000011000100001100001000001010000010110\
						01010100111110111010101000010011111111110000110111001010111111111011010010110011\
						01100001110011111100011000000111010101101100011100101000101011101000011110101001\
						00011100111100110101110101011110110111101100100000011011100111011000011101001011\
						00111110100001001101001110001110000111101101010101100101100001011101111111100011\
						10001111111000011101110101110110101100100110110000010000000001111000010010000111\
						11000101011111111100110010101010101101001101101111100100100001100111001010110110\
						11000001101101111011000111001110010101011000011111000000011100110111000000000110\
						11100010011000110001010000111011001101000010001101100000000000001100000001011011\
						10001110011111011111101011100110000000000000111000101100010011110010100111000000\
						00111111000010011101000101001000001001100110011011001001010011100011101001100011\
						10000010101001011000110111001100001100000001111001110100110110101011100010000110\
						10000111011011110100101110010010000011110011110010011000110111011100110011111101\
						00110000110010110111111110100110110110110010111010111101101010111010100000101100\
						11100010001100000010110111001111100100111110000110000100010001101000101011011110\
						10011111111001100111100110111101111111010010001110010101010101011110110000010001\
						01000001001010011110101111011111000110011000111011000111100101100110011001111010\
						01110101000100111011000111010100000101011010001011011101011000111001011000100000\
						11010101110101111101100101110011100000010000010111111101001011000100010101100111\
						11000110100001001011010110010100001011110000110100010011000101001111000101010110\
						10111110111001000000001101100001101110001111110010011010100001000111101001001101\
						01011100111010110000100000010100000010101111100000110001011111111000011111111100\
						00101010000110111000100011011100110100110111001110101000001001001001000111000011\
						10001110101011111000110110100001010101010000010101111110100000101111000010110001\
						00110000101011011101011100000111011010100100111011000111100110101100101010011111\
						10101000011110001001010001100001001000000111101000001010111110100010101111001001\
						00001101100101110000101000010000010000101110100110110100001110110000100110011011\
						11101001101111010000100101001100100111100001111001110000000001110001100101111110\
						11010001100001100100100011101110100100101001110010010000100000100010110111011001\
						11111101111100001011111001001001000001010000111101110110011000010101111010000110\
						11000011100111001110010011101101101000011001100110001100101011011011010111010101\
						01101000011100011110010001000111000001001101100111110001001110101011111111011011\
						00011010000010110111110101101011111111010000101010101011100101101011111011111010\
						00011111100000000010111100001101100101011011111001100011001010100100000010110101\
						11000110011111010110011011000111101001111001001111010011111101010001011100111100\
						10101001111111001100011101111110011100011101000000100110110011010111000010110111\
						01000011011110010110000100001101110101100101000010011110101000110000000110010011\
						10101011110111111001111110010011010011000011010011101110011010101011010001111110\
						10111111011001100101101100100000010111110011010110010001111011000010110001000110\
						01010111011000011001101100010110111100111010000001111110110000101001001011010001\
						10001100001101001100011100101101011010110011010001100110001011101111111111110110\
						10111111000001000100000011110100010110011110100000001001111000011101011100011000\
						11100111111101111000101101101000101110010000111111111010001101001011110101010010\
						00110010010100010101011100010111001100010111101101010100011000001100010100010000\
						01011000001010000100010111111010000100101101100001010000001010001100110100110000\
						00111100010101000011001001011000011101110001001111011010111101110100001111101000\
						00101110011100111111011100110011010100001010000101000001100000011100101101101000\
						00111100011110001110011000100001101101101111100010010101011111101110110011000001\
						11011110000001101000110100100101010000100001011101101010100010110100111111110000\
						00110101000011101010101101111011111011111001110000101010101100010001000000011010\
						11111110100111000101010000100110010001001010010010110000010110001000100010100110\
						10001011000100010000010001111110100010010010001011001011001011100111111000010010\
						11010110000000111110101011100101101001001010100100011001111000011100100111000011\
						11100000000010111001110101100111010101100010011001011001001011010000000011010111\
						11100011011000001000000001111000110101000110001111111011000010100101010111100011\
						11111110000111001111101010100011011000101111100001001101001011010010001100110011\
						01001110100101111110000000110101011101110011110101010101101000101011111100111001\
						01111001101001000011100011110111001100000101101101000010101110000011101011010101\
						01001010100001110111111010101011101010000000110101000111101100011000001111001011\
						00100110011010110110111111111011111010000001110110100110101111011101011110100110\
						01010100000111001001000101100000110011110001111110110101001111111111011001010000\
						00001101011011000100100011010111001001011110100010100110110011001010111010010001\
						01110001000101011000001111110001101000001100010111011001001010111010111011111010\
						00010000101000110101101011010010111000000000111100111011110001001111010110000101\
						11010100011101110010101110000111000010110010101111010011010001000111111110111110\
						10010101011001111100001000101010100011000010101110100010100011110110101100000001\
						10000100011101111010111011010010100001111000000110010000001111111111011001001100\
						11000110101011111100001000110010001001101010001101000000011101001100100111001011\
						01001111000101010110001101001110110011111111001110110100000001001010010011111101\
						10001111100010100111001110010111011011111011010101111001101010000111111001101101\
						00010001101100100111101110001111110011111100100011110011101100010001111010010011\
						11110000011101101011111101001010110001011011101100001000000100010001110100011111\
						11110001100101010001111011010001001001011011110000001010001111111011101101110001\
						01101110111110111000001110110100110100010100011010111010101001000010111000110100\
						10101011001100100101000001001100100011001010101110110011000100110100001101001111\
						11000011110101111000000000010010001111100011011011100001011110110101111010000000\
						11100110000111001110111010111001100001010100011010011110111100000000101011000000\
						11101011101001100010001001001000111011110111011001011100010111000110011100000011\
						10010000101011101110011100011100100101100100100000010011110000111100001111010110\
						10010001110100010110001100111110100111010010110111011010100010000001011110100110\
						00001100100000011110011111101101011000011101011001111000011000100111010110101001\
						00101001111111111100110111000000010110001000111011010101100010110010111100011000\
						01110101110010011001100010011100011101101101010101011110100100010110000101011111\
						11110100110011001101111111110110111010010101001110000000011011001110110100011000\
						10000000001110001010110000101011001110110100110111110011110100010100100100010010\
						11101001000111111001001011010000101110011010000110011011010101001100110001101101\
						11111011101100101111111001010110011001011001010011110111001110011010100110001110\
						10100110011100001110000000001101111100011110100011101101110010101110101001011100\
						11100011011100110011100000101011010011001011100011110011001001000101100111010111\
						11100101111111111110101111101000101101110011011110010011001001101001100100101011\
						11001100110101001101111110111001110000011110101011010001111001110010001010000110\
						00111100011101100001110111011000110111010011000111110100011111101100110000000100\
						11111101001011011010010000010101100110110101110101001110000000100010101001011110\
						01111110101000110100001000101011000011000010000101100110100100000110110010000111\
						11011110001110100111001101111101001110110111110011100001011100111000011000100001\
						01100101010010111110000010101111010000000110000101011101011000011000000110101110\
						11001100000001000110010110110000011111001000111111001010000100110100010100000001\
						00011100101110110011001010000000101010011011111111101110110011111000010101111010\
						00100001000110000010010110001000000110011001101000100010100011010010100111010111\
						11010110111000100001001011000110001000000111101000000010011010011100100010100011\
						01100101101001100000100011001011100011101000101001001001100000100111101011111100\
						10000110111101100100000010001011000111101111100110101011011111111101001100010110\
						11001000010100010011000000011001010101001000110111101000000100111000011100101101\
						01000101100111011100000101010111000100100111011001000111010111000111000100011101\
						01100111100011101011101111010110100001010110111001001011011001100000111101010010\
						01011100100101100100010001001011111110101101100010001000001100111101001111011011\
						01011110111011100010000101010111100100000111001001010000010010000011110110101100\
						11100110010110100110010001110001000110111111110001100100100001100011010100110011\
						01000100010001000001111101011010000000101011111001001010001101110011001001110001\
						10111000100101001000000000010010111001001100011010011110101100110011100011001101\
						01011001111111110000010101010111010111000000111100010001110101100011000110000100\
						11011101010111001011011010110111111010101110100100011000111000100010101000111011\
						01010000011110011101001110010100000011110111100010111011000011100101010111110110\
						11111101101010011110111010011100101000010100001000101111010101001001011001001010\
						10110110111101100000110000010110000011010110010010111111100011000100100001110001\
						11100001010001010010100111111111100000111101101001111001110011011100100101100100\
						00100101110001011011101000111111011101100010011000111100101010000010000011111011\
						00101101000001001100101010111100011111010110100010010000000011000101101000010000\
						00111100110101011000001010111111001001001111010010001101011001000000101101010000\
						10100001100100101100000001111110000010000010011100010010010111100001011011001011\
						01100111001111110110001101101001100110111001001011111101001100101101101110011111\
						00101110000000100110110000000000111011110000101011010000000100100111100110111011\
						01111001100001111001011110001100011111001100111111100011100011001001101110111010\
						10101011001010101001100001111101100100101001010110111111110101101001011110111100\
						01000110101001110100100101110001010010110101000111101111010000101101000011111110\
						00110001111111011010000000101101111110000101010010000010011111110110101010000111\
						00100011111001111110111001000100100111101011011011000010100101011110001001111101\
						11101010010011110001100011111101110010110010001010010100110010010011100000111011\
						01010110001111100101011100111111000101000011101000011001011011001110001100100101\
						01111001011101100111011110010000010010010111101100011010010011011011000011000101\
						00110010011100011111000000100000110010010110101111101011011010001011000010100110\
						00010011101110111011111111000110011011101110011100110101110011110111100011101000\
						10101000000010011001011011111010011010000001010101101111010000110111110110010011\
						10111001111101011110011000011000100000010001111111101010010101010010001010101100\
						01100101100101000111011101111011111000011010000111001001100111010110110110010111\
						00011001000111011010111111100110110100101100010000100001100001000110101100111000\
						01111001010000010110101101001010111011110011010001011000011010001111001000110010\
						11101110111000010011000111111110111010110010111100111000101001011010001000110001\
						11100001111111110011000011100000100000000101000110010110010000001100001000111100\
						00111100010001000010010011010001111110001110001111100110000100001011100100101000\
						00101010010011111100110000110101111011100010011100101100001010000100101010100111\
						11111011110111100101011100010000101010100011100110011010000111110100100000111110\
						11000010010111000100110110010100100010110010001000000000100000010000101111010100\
						01011010110000110010001011001000011001101101010100001100110011000011101100000000\
						01010001011001001000101001010110100101011001111000111101111111000000111111001101\
						10001001110111110111101111111010000110101110110011010010101100010110101011111011\
						01000010110000010000011100100110001000000011111011010111111000100101010110001100\
						00000010111010010000111111110000100000110100011100100010100011110111000100001011\
						10111001000110100001010111110001111111000001011010101001101011110000111101010010\
						01000110001001011110000001000111101100101110010010001011001110011001010101100111\
						01111011100001101001110111110110000010001100100100101000011010100101111000001111\
						00010101100111010010011000011111001001010000001111011111011101000101001000011010\
						10010100101001110101001101110101111110100011111010100101000010000110001011101001\
						01010101111010101110000001101010111101011011011100101001001110110001011010111110\
						01101101000011011000001101110001101110100011101001100100010011010100111010001110\
						11010110000110111001111000001000001001001001001000001011110011100101101111010010\
						00110101011000010101111111111000010100110110000001001001110111000110100101101011\
						00010110100110000010100011100111101110101100000001000100101110111101001010010111\
						11011110110101001000111100011000100110011001100101010101000001010110101001010000\
						01010111111111000011010101111101111011010000100000001011011111101110000011110000\
						10000000111000101100011100011001111011000110101011111000100000111100010011000111\
						00101101101011001101100010110001111010010001100101011100001101100000000100110011\
						10011010111000100001000001010001100100000100000000001101010100011010110110100100\
						00101101101001000011001101000010111010111111010011111100011101011011001111110101\
						11000010000010010100011101011111010100100111000111111000010011101000111100011111\
						10111101101010110110011100100110000101001001001100000110101100011000100110010000\
						00100100011111000100101100101111110100100101000010110001101100000110101101110110\
						11111010101111111011101011111001101000110011110111000101011111100111010001111100\
						11110101111110010010100011001101101010001101111000110001110101111101100011001111\
						11000111000000110010101000100111110110110011010100101000000011110111001111110100\
						10100101011100111101111111011010111110000010000101110000111100100110011011100010\
						00000101001100110000111001010101101101010101111000100100001001011001110000011001\
						10011010111001110110011001101110000110100101110000010001011100111100001101000001\
						10001100111110011110101000100110010011110010101010010101000110010011001000011101\
						11101110001101111011001010010011111110111011001011101100001100110100000000011010\
						11010101101100011111011000001111101001101000110001011010010101100001011010010011\
						10000010010100001110000001011100100010010100100111100000000100011001011010011100\
						10110100010100101000001101101111111000100011101101010111100001011001010111001111\
						11110010100010010110010011011101100011110110000010100110110101110010110110101001\
						11001101011011001000000101111110111111111001010010000111001100010000000001010101\
						01101010001010010101100100100001101100110111101100101110110001000100101000000000\
						00011000111010110001100010110000101010010000011011010101110111001000000001111000\
						00000010111100101100011001111111100001101011111101001110101100000011101011011000\
						00101001101011011101001111010100000011111011001111100100101110111011000101010111\
						10101001010100000010000000010110011110110000101010001110000000111010001111010000\
						00110110001101010111111000011000101011100101001001111110110000000110011111110010\
						10000001010101000101010011001001000110100011001101101100100100000011111001011111\
						01010001011000100101101010111110001011100100001101100111101110110000011101010000\
						00111000111111100001101000101100000000100111010010111110001101011010110110011000\
						01110110001010101101001101110110011111001100010001101000000101000000000001100101\
						00110011100001111000111000001100001010000011010101100100011010001100111010001111\
						11101110100100000011000101110011001011000011110000111101010111000101101101101010\
						01110001011000011000011110101011000110101100001010000000101001110000000100001111\
						10000111000000111111011100000111100111010001101101001110110111000011001110000101\
						01100011010010001010101001111100001000010011011001111001011000111101111000101111\
						10010110111101000000101100000101111100110011010110001111010101010000100001001100\
						10010101001010001110111111011001111110101101011000101100100001001000101001111111\
						00100000000110001110100000010011010001110001100110010110000100101001100000011011\
						10010010111001001110000110011111001001100100001010100110011111101000100000101101\
						10010111000011000000000100100100100111111101010111000010011011000110010111010010\
						11010100001100101111010000001100100110001111110011100011100100001010111011101111\
						00011111110101010011100100010100111001010011110001011100011001001101011011010101\
						00001101011011101011010100110000011101001010101110001001011001100010111100011001\
						10111010011001001001110111100100001111000100110011010011001011111000111011000010\
						00101010001000000011111100101110001111000101101001100010100111110010001110011011\
						01111011000100000100000000010011101110001111110011100001101010111011001111011001\
						10110010101011010110101100000001101101010000101010010111010011000111011100110100\
						01001001000000110101001000010000100011101001000001001010010001100110100001010000\
						11111101110010001010010111101111110110110011010111010001110000110100001110110011\
						00111110001011011001100110100010111011101101010000100101110110010110011000011001\
						11101100110011000001110011100011111100001001000100000011011011001010011111010101\
						11111100011000000101101001110110110000000111101011110001010011101100100010000100\
						10101111001111101101110000101010001100000011000111111110000010011100011111010110\
						10010100000111110101110011010100111001001000010011010001101101110110000000001001\
						01110101001000111110111111100010000110100110100101010001001000011001001100111111\
						10101001110000111111101101111101011001011011100101010001010101000101001001000111\
						11010101111100000110110000110001111100101111010101111000000001111101011100001110\
						10110011111011111110110000011110100011001010110110110110111011000010011100000111\
						11010100011110101010000100101110100111001101000101001001000110010101001011110011\
						00111110001110111000011010000001110101111100010111001000000100001101000010000111\
						01111001110000100011110101011110111101111010010001111110011001100000110111000001\
						10110110101011010100001100001110101010110010011000011100010110101110101111101111\
						11111111101000010111010110001001010011001100101001100100101110011001110011001010\
						00011101100100111110110000110111010100001001001000101111111111000000000110111101\
						10011011110100001011110001001000000011001111001001111100011110000010111101001100\
						10010110001111001001000110101111100110110010011101000011000001000101111101010011\
						10100011001000000011000111011000010110101100011110100111110101011011101100000010\
						01011001101011011011101010110110011001100111010111011111001101001001000011010011\
						01101100101101011011111111101111011000110010101000011010011010001001010011000000\
						10110001000001001011110011111100100011100100000100110101000010010000010000011110\
						11011111110001000010111000111001100101101010110011000101001011011000111010000101\
						01110010110011111100010100011110011001101011011111011001110110011010111011001001\
						01101111011001000111110100000110101111011010010100001010001111101011000011100101\
						01001101100000001101110101101100011111101011111001101111000111101010110001000101\
						01110110100110001010101100100110000001000010110101001110100110100100110000100011\
						00010010111000001110000011010111000011100001000000100000111100000000110011011101\
						00010000110000111111110001100100100111100110101001101100001101111000000111101111\
						01110010010111000100101000000100111110110001000100000110000111101001001011101100\
						11100000010000000011111110110011001100011001111000001111110010100000010100010111\
						10100101101010100001000101001001111001111100011010100010101101011001011001110101\
						01101100001000010011101100010100000100001010000010110010101011101001101111011111\
						00111100001100100100110111001011000001001101111110000100000111100101101011100110\
						11011111000100111100000000100100101010000101000011001011001010001001100011001011\
						01000000110110100011111110010100110010001001010001001111101001011011011100110011\
						10011100000011111110010000011010000100100000010111000111100010110111001000101000\
						00110110000110100011011111111110110010011000100010000110101111001001101011101101\
						11111101110110000110000100100110000101001001111001000110110100001000100110101010\
						11110010101011011001000100110111111101001100010111111010110111101110110111001011\
						01100000001101011011100101001101010001111110010000100010111100011101101110011110\
						11100011000010100111110111000000111010111001011011010101100001010111010011111101\
						11110100001101010010101000111101010110101000000000101010001000000011001010010100\
						00101100111000000110101011010101110101001111101111100100001111001111111101011111\
						01011101010101001011100110101111100111011100010110100011011110111011101110101010\
						10100101110110000011011010000001101010101111000111010100111011111111100000110001\
						01001110001011001101011110111100110001001110111000110001101100100001100111011010\
						10100101101010111110100111111011000000110010001110011011101101011010101001001110\
						11110101011110111010101110000010011001000100101000010101110100100011110010010111\
						01101101110010110010111000111001111101011100000110100011111000101101100011011001\
						01010111010001001101011100011001101111001111111111101101111101011010011110000100\
						11010111100001111010000000001001101001001111000011111011110011001100100011101011\
						11110011110100001010111011001111100011000111101011000001001011111111011100110100\
						10001001000100111110010101011000011101001011010000010001011101001000011000101011\
						00010111010110001000100101011000000100010110001000010101111010011011100010011011\
						10111101000100100001010000011110010010110101100000011000001010101011001001001000\
						10000110100110010010010011001111111011100011000011001110000110101100101110101010\
						00000011100001111001100111001011011110101110011100111001101010000010001100001110\
						00010101000101101001010010011101101101111010000011101110100111100110000110010000\
						01110110001111010100000100010011011000000001110111010101110001111110001111100101\
						10101001100110100011110001100001111101010010100101111000001011011101110000111111\
						01111100011011110100100010000110101010110111000110011111000001111010001100001111\
						00111000110000011010001010111100100011100010101001011100101000101011000100011111\
						11111000011101100011100101010110100101011111010111010101110100010101101011000110\
						00111101100100011100011011001111100001010001000000010100000001010001100110111001\
						00101101010011101011010000001110101101001100100100011001110001111011001100100110\
						10100100101001011000011011100001111001110000000100110101000101010000011010100110\
						11010110100001010010000000111101101001110111111111101001110010010001010010011010\
						00101110011011110010110011110100101000101000100101000010101000001010101100000010\
						00111101011010100100011000011000101110100100110001100000001010000110001000110111\
						01010011101101100100010111110101011010000101000000010011101100010101111011010000\
						01110001011100111110000010101101011111111101010111010111001000101110111011100100\
						10000000001011111000101010010100111101111001101111101011110000001010100101010010\
						00000001100011101101011111101100111101100011010100110111100011001111111111011011\
						01111010110100101101111101101111000100011000000000001001010101010111110100110001\
						00010101100001001100000111011011010011111001101110110011100010111001010100110100\
						01010000000001010010011000111101011101101011100111000001010001011011001111011000\
						11100010000001110000001001011110000011000000100000101101100101111000011001000110\
						01011111001011110000111100010000011111111011111100100010100000111100001000111010\
						00011101010011011010110010101100110100110000010111000001001010010011001011001100\
						00010101101010111001000101000110011110000100100010011110000000111011101101111001\
						00111101010010011010000110101000011011001010111000001111000100101001100111111110\
						10010100011011111010100110000010001011111011011011001110011110110001000010000000\
						10111111010111100011111100110100101100110001111010100100100100111000001100011100\
						00100010100110101001101010001011011001001001101010110010010001000010011111100011\
						01000100011110000010101010111101100110000000010100011100011101100010001010000101\
						01111011000101000100011101100000011101011000111011100101000111000011111100110111\
						11001000101110010101101101111111010000010111011011111001101101110011100100011011\
						11100010001010010011101110011011101100011000111000110001000000011000100001111011\
						01101111100101111110101111010101111100000010010010101110111111101101100011001111\
						10010110111101110101111000000111110110011001011110110111111010110101000011101000\
						01111111111110101000110001001110011001011110001010001000111111010111101111100000\
						11000011111000101100000111101110110000111101101011010111100100101100110010111010\
						10101001111011100111001100010000010111101000110101000100011110100011111101001001\
						01111111100011101100110000111011011011001111010011111011011000000001100111111101\
						01001111110100000001011111010000011010101010110111001010000010101001111100001111\
						10110100010000010101010010100111001111111100101011111001010000011011110010100001\
						11100110100001100001000110010001001111111100010011100101010000011100011100011101\
						00000001010001001111011100101010100110100011010101010011101100110011011011001010\
						00111001101010111011100011100111011111100101000000011001011100111111110110101100\
						10011110111101101000011001100010010111010011101010000010011101011100000000000011\
						00110011111100100011010111110010010101001111111011110101011000001011001001110111\
						00110101001010100001110011101011010011100010100011011111011010001111100101001110\
						10101110010010111010110011001100111110011101011100010000000110010111000100110101\
						10011011101100110111011111000100101110011011000001011000011100100000001100110101\
						00101010010110001001001100100110000111011010110101011100101011110110001101100111\
						01111010011101000011110100010101001000011111101110000100000011000000010011001011\
						11010100011111000001110011100110011101010000110001111111001010111110001011110011\
						11100001011100001111001000001010001111111101110000001110101110100111011101111010\
						10111110010001011001101111000000000110000001000011000100100101000100010111111000\
						00001000000100000000011001001001101010101101101100111101011000011110011111110100\
						00100101100010111000101111000010101011110001110000100000000110001100001111011100\
						10100001011010100001110100111010010100010110011100001010011111001110110001000100\
						01001111111001010010111001000101100101010000100100011100100001010100110111001010\
						10110010000011000011100100011110011101010101001001101011010011010110001111000000\
						11001010011000110011110111000001100110000101000001001101011111000110100100110010\
						10110111011010101010010100100001111111100000110011100100011010010000010100001110\
						000101110011000101101010011000011010101100011000",
						.eo = 16378,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minFlips(t[i].s);
		//cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}