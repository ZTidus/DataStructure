#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Array */
/* 题目信息 */
/*
 *66. Plus One
 *Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> res;
        if (len == 0)
            return res;
        
        int sum = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            sum += digits[i];
            digits[i] = sum % 10;
            sum /= 10;
            if (sum == 0) break;
        }
        
        if (sum > 0) res.push_back(sum);  // first
        for (int i = 0; i < len; i++)
        {
            res.push_back(digits[i]);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

