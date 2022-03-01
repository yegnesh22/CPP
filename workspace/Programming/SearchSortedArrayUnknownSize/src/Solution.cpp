/*
 * Solution.cpp
 *
 *  Created on: Feb 28, 2022
 *      Author: ysiyer
 */

/*
 * Search in a Sorted Array of Unknown Size
 * This is an interactive problem.
 * You have a sorted array of unique elements and an unknown size.
 * You do not have an access to the array but you can use the ArrayReader
 * interface to access it. You can call ArrayReader.get(i) that:
 * returns the value at the ith index (0-indexed) of the secret array
 * (i.e., secret[i]), or returns 231 - 1 if the i is out of the boundary
 * of the array. You are also given an integer target.
 * Return the index k of the hidden array where secret[k] == target or
 * return -1 otherwise.
 * You must write an algorithm with O(log n) runtime complexity.
 */

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target);
};

int Solution::search(const ArrayReader& reader, int target)
{
    bool limits = false;
    int right = 0;
    int left = 0;
    int value;
    int i = 1;
    int m;

    value = reader.get(0);
    if (value == target)
        return 0;
    if (value > target)
        return -1;

    while (!limits) {
        value = reader.get(i);
        //cout << "i:" << i << " v:" << value << endl;
        if (value == target)
            return i;
        else if (value > target) {
            limits = true;
            right = i;
        } else {
            left = i;
            i <<= 1;
        }
    }

    //cout << "l:" << left << " r:" << right << endl;

    while (left <= right) {
        m = (right - left) / 2 + left;
        value = reader.get(m);
        //cout << "l:" << left << " r:" << right << " m:" << m << " v:" << value << endl;
        if (value == target)
            return m;
        else if (value == INT_MAX)
            right--;
        else if (value < target)
            left = m + 1;
        else if (value > target)
            right = m - 1;
    }

    return -1;
}
