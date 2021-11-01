#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: binary search */
/* 题目信息 */
/*
 *剑指 Offer 53 - II. 0～n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 */

/* my solution */
// solution-1: 36ms defeat 91.37%
// 1. 如果数组中缺失数据，使用循环找出返回。
// 2. 如果数组完整不缺，则返回数组长度。
// O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int cnt = -1;
        for (int i = 0; i < len; i++)
        {
            cnt++;
            if (nums[i] != i)
                return i;
        }
        if (cnt == len - 1)
            return len;
        return -1;
    }
};

/* better solution */
// solution-2: 48ms defeat 24.27%
// 1. 使用binary search
// 2. 如果当前下标和当前值相同，检查数组右半边
// 3. 如果不同，向前查找
// 4. 如果前一个下标和对应值相同，则返回
// 5. 如果不同，则检查数组左半边
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        int low = 0, high = len - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] != mid)
            {
                if (mid == 0 || nums[mid - 1] == mid - 1)
                    return mid;
                else
                    high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (low == len)
            return len;
        return -1;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 可能是因为数据量小的原因，所以binary search耗费时间大于遍历耗费时间。
// 2. 
// 3. 

