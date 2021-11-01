#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: greedy */
/* 题目信息 */
/*
 *55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
 */

/* my solution */


/* better solution */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        // index[]: 存入当前位置可以跳到的最远位置
        for (int i = 0; i < nums.size(); i++)
            index.push_back(i + nums[i]);

        int curPosition = 0;
        int max_index = index[0]; // 当前位置可以跳到的最远位置
        while (curPosition < nums.size() && curPosition <= max_index)
        {
            max_index = max(max_index, index[curPosition]);
            curPosition++;
        }
        
        if (curPosition == nums.size())
            return true;
        
        return false;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 贪心算法：只考虑局部最优
// 2. 使用index[]存入当前位置可以跳到的最远位置，然后遍历index，更新max_index
// 3. 

