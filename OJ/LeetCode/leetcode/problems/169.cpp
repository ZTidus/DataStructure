#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
 */

/* my solution */
// solution-1, 44ms, defeat 62.39%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // record each element's freq
        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        
        int n = nums.size();
        for (auto e : mp)
        {
            if (e.second > n / 2)
                return e.first;
        }
        
        return -1;
    }
};


// more precies
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // record each element's freq
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i : nums)
        {
            if (++mp[i] > n / 2)
                return i;
        }
        
        return -1;
    }
};
/* better solution */
// solution-2, 72ms, defeat %
// 因为给定数组中肯定有某个数字的频次大于n/2，所以在给数组排序后，数组中间的数字肯定就是我们想要的数字。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中频次大于n/2的数字
// 使用map算出每个数字的频次
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

