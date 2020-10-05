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
 *34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
 */

/* my solution */
// not O(logn)
// but AC
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first_position = -1, last_position = -1;
        // from left to right
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                first_position = i;
                break;
            }
        }
        // from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                last_position = i;
                break;
            }
        }
        
        return {first_position, last_position};
    }
};

/* better solution */
// binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int leftIdx = binarySearch(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target)
            return res;
        res[0] = leftIdx;
        res[1] = binarySearch(nums, target, false) - 1;
        
        return res;
    }
private:
    int binarySearch(vector<int> nums, int target, bool left)
    {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target || (left && target == nums[mid]))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

/* 一些总结 */
// 1. 题意: 给出一个值，求出它在给定数组中第一次和最后一次出现的位置。
//
// 需要注意的点: 
// 1. 第二种方法暂时还写不出来，特别是这个left置为bool类型的写法。
// 2. 
// 3. 

// a comment: Usually when you are given a sorted data structure and are asked
// for a log(n) algo, 90% of the time its binary search. Just like when you are
// given a tree, 90% of the time you use recursion with dfs or bfs.
