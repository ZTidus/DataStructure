#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: array */
/* 题目信息 */
/*
 *剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000
 */

/* my solution */
// solution-1: 124ms, defeat 5.48%
// 1. 使用hash表记录每个数字频次
// 2. 找到品次为1的数字
// 3. 返回它们。
// O(n)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        vector<int> res;
        for (auto e : mp)
        {
            if (e.second == 1)
                res.push_back(e.first);
        }
        return res;
    }
};

/* better solution */
// solution-2: 异或


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

