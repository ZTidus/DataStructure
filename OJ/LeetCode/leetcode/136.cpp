#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

/* my solution */
// space: O(N) not good
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int res;
        // find out each number's frequency
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump[nums[i]] == 1)
            {
                res = nums[i];
                break;
            }
        }
        
        return res;
    }
};

/* better solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i: nums)
            res = res ^ i;
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 由于加上了时间复杂度必须是 O(n) ，并且空间复杂度为 O(1)的条件，因此不能用排序方法，也不能使用 map 数据结构。
// 2. 
// 3. 

