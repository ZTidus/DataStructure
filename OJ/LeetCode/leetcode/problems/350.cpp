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
 *350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mp1; // record each number's freq
        map<int, int> mp2;
        for (auto i : nums1)
            mp1[i]++;
        for (auto i : nums2)
            mp2[i]++;
        
        for (auto e : mp1)
        {
            if (mp2.find(e.first) != mp2.end())
            {
                int cnt = min(e.second, mp2[e.first]);
                for (int i = 0; i < cnt; i++)
                    res.push_back(e.first);
            }
            
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 找出两个数组中相同的数，即使数重复也要返回
// 2. 对两个数组中每个数字分别记频次，然后遍历其中一个map，对另一个map作比较，有则计算此数最低频次，根据这个最低频次添加进入结果中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

