#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type: dp */
/* 题目信息 */
/*
 *152. Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

/* my solution */
// solution-x, ms, defeat %
// brute force
// time limited
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = i ; j < nums.size(); j++) {
                product *= nums[j];
                res = max(res, product);
            }
        }
        
        return res;
    }
};

/* better solution */
// solution-x, 8ms, defeat 70.47%
// 这种解法还未看懂
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int curMax = nums[0];
        int curMin = nums[0];
        int maxProduct = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int p1 = curMax * nums[i];
            int p2 = curMin * nums[i];
            
            curMax = max(nums[i], max(p1, p2));
            curMin = min(nums[i], min(p1, p2));
            
            maxProduct = max(maxProduct, curMax);
        }
        return maxProduct;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，返回这个数组中连续数字乘积的最大值。
//
// 需要注意的点: 
// 1. kadane's algo
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    vector<int> input = {2,3,-2,4};
    int res = solution.maxProduct(input);
    cout << res;

    return 0;
}

