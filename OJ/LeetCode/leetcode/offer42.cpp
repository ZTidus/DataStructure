#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
 */

/* my solution */
// solution-1, ms, defeat %
// brute force 
// time limited
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

/* better solution */
// solution-2, 64ms, defeat 13.81%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前和小于等于0, 则放弃当前和，重新将当前元素值赋值给当前和。
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

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

