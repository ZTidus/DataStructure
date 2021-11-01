#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: math */
/* 题目信息 */
/*
 *剑指 Offer 57. 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
 

限制：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
 */

/* my solution */
// solution-1: 1828ms, defeat 5%
// 1. 使用map记录某个值是否出现
// 2. 遍历数组，找到另一个值是否存在
// O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i : nums)
            mp[i] = 1;
        for (int i : nums)
        {
            int remaining = target - i;
            if (mp[remaining] == 1)
                return {remaining, i};
        }
        return {};
    }
};

/* better solution */
// solution-2: 420ms, defeat 95.84%
// two pointers
// 1. 初始指针在数组两端
// 2. 当指针所指的值的和大于target时，和需要小一些，使right--;
// 3. 当指针所指的值的和小于target时, 和需要大一些，使left++;
// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
                return {nums[left], nums[right]};
        }
        return {};
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

