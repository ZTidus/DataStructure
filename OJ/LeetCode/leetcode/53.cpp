#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type:  array*/
/* 题目信息 */
/*
 *53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
 */

/* my solution */


/* better solution */
// brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
        
    }
};
// 二层循环，每次固定一个位置，从当前位置开始循环，每次将当前数组添加1一个元素，查看当前数组所有元素的和，遇到比当前最大值更大的，更新当前最大值。


// better ✓✓
// 优化前缀和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        int minSum = 0;
        for (int num : nums)
        {
            sum += num;
            maxSum = max(maxSum, sum - minSum); // sum - minSum 怎么来的???
            minSum = min(minSum, sum);
        }
        
        return maxSum;
    }
};

// solution-2
// 下面这种解法比上一种解法更加容易理解。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前和小于等于0, 则放弃当前和，重新将当前元素值赋值给当前和。
            // 及时止损。
            if (curSum <= 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            // 更新当前最大和。
            maxSum = max(maxSum, curSum);
        }
        return maxSum;

    }
};
// 1. 求出所有元素的前缀和

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 
