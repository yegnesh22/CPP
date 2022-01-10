/*
 * Solution.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ysiyer
 */
#include <iostream>
#include <vector>

typedef enum {
	RIGHT,
	UP,
	LEFT,
	DOWN
} direction;

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
    	int startR = 0, startL = 0;
    	direction dir = RIGHT;
    	int row = 0, col = 0;
    	int move = 1;

    	cout << "Start: (" << row << "," << col << ")" << endl;
    	for (size_t i = 0; i < instructions.length(); i++) {
    		switch (instructions[i]) {
    		case 'G':
    			if (dir == UP || dir == DOWN)
    				row = row + move;
    			else if (dir == LEFT || dir == RIGHT)
    				col = col + move;
    			break;
    		case 'L':
    			if (dir == RIGHT) {
    				dir = UP;
    				move = -1;
    			} else if (dir == LEFT) {
    				dir = DOWN;
    				move = 1;
    			} else if (dir == UP) {
    				dir = LEFT;
    				move = -1;
    			} else if (dir == DOWN) {
    				dir = RIGHT;
    				move = 1;
    			}
    			break;
    		case 'R':
    			if (dir == RIGHT) {
    				dir = DOWN;
    				move = 1;
    			} else if (dir == LEFT) {
    				dir = UP;
    				move = -1;
    			} else if (dir == UP) {
    				dir = RIGHT;
    				move = 1;
    			} else if (dir == DOWN) {
    				dir = LEFT;
    				move = -1;
    			}
    			break;
    		default:
    			cout << "invalid move" << endl;
    			break;
    		}
    		cout << "(" << row << "," << col << ")" << endl;
    	}

    	if (startR == row && startL == col)
    		return  true;
    	else if (dir != RIGHT)
    		return true;
    	return false;
    }
};

int main()
{
	Solution s;

	vector<string> t = {
			"GGLLGG",
			"GG",
			"GL",
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << (s.isRobotBounded(*it) ? "true" : "false") << endl;
}


