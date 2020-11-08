#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
 */

/* my solution */
// solution-1, 60ms, defeat 75.13%
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // record each number's freq
        unordered_map<int, int> ump;
        for (int i : nums)
        {
            if (++ump[i] >= 2)
                return true;
        }
        return false;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 如果给定数组中有重复数字，返回true
// 使用map记录频次
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

