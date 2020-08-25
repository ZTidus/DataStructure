#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *137. Single Number II
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
 */

/* my solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int res;
        // find out each number's frequency
        for (auto i: nums)
        {
            ump[i]++;
        }
        
        for (auto i: nums)
        {
            if (ump[i] != 3)
            {
                res = i;
                break;
            }
        }
        
        return res;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

