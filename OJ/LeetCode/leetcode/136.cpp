#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

/* my solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int res;
        // find out each number's frequency
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump[nums[i]] == 1)
            {
                res = nums[i];
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

