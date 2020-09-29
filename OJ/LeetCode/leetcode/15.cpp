#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointers */
/* 题目信息 */
/*
 *15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0)
            return res;
        
        for (int k = 0; k < nums.size(); k++)
        {
            //
            if (k > 0 && nums[k] == nums[k- 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[j])  // 避免重复情况
                        i++;
                    while (j > i && nums[j] == nums[j-1]) // 避免重复情况
                        j--;
                    i++, j--;
                }
                else if (nums[i] + nums[j] < target)
                    i++;
                else
                    j--;
            }
            
        }
        
        return res;
    }
};
/* 一些总结 */
// 1. 题意: 求在数组中三个数之和为给定值的组合。
//
// 需要注意的点: 
// 1. 求三数之和转变为求两数之和。
// 2. 先选择一个数，在去求另外两个数。
// 3. 

