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
 *剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制： 1 <= 数组长度 <= 50000
 */

/* my solution */
// solution-1, 44ms, defeat 75.70%
// 使用map找每个数字的频次，然后再遍历，找到频次符号条件的数字返回。
// O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        for (auto e : mp)
        {
            if (e.second > nums.size() / 2)
                return e.first;
        }
        return -1;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

