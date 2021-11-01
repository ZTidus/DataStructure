#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: binary search */
/* 题目信息 */
/*
 *35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
 */

/* my solution */


/* better solution */
// binary search ✓
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1])
            return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意第一个if条件语句，如果目标是大于所有的元素的话，就返回数组长度
// 2. 
// 3. 

