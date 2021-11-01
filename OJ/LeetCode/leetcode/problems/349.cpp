#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s_std;
        for (int i = 0; i < nums1.size(); i++)
            s_std.insert(nums1[i]);
        set<int> s_compare;
        for (int i = 0; i < nums2.size(); i++)
            s_compare.insert(nums2[i]);
        
        for (auto e : s_compare)
            if (s_std.find(e) != s_std.end())
                res.push_back(e);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 找到两个数组中相同的元素，以数组形式返回。
// 2. 解决: 使用set对两个数组分别去重，然后遍历其中一个set，看另一个set中是否存在，存在则加入结果中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

