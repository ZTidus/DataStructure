#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *525. Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.


 */

/* my solution */
// solution-x, ms, defeat %
// time limited
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int res = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] == 0)
                    zeros++;
                else 
                    ones++;
                if (zeros == ones && zeros == (i-start + 1) / 2) {
                    res = max(res, (i - start + 1));
                }
            }
            zeros = 0;
            ones = 0;
            
        }
        return res;
    }
};

// 上个代码优化下
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        for (int start = 0; start < nums.size(); start++) {
            int zeros = 0, ones = 0;
            for (int end = start; end < nums.size(); end++) {
                if (nums[end] == 0)
                    zeros++;
                else 
                    ones++;
                if (zeros == ones) {
                    res = max(res, (end - start + 1));
                }
            }
            
        }
        return res;
    }
};

/* better solution */
// solution-1, 292ms, defeat 46.18%
// 没有看懂下面这种解法
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ump;
        int max_len = 0, cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1) ? 1 : -1;
            if (cnt == 0)
                max_len = max(max_len, i+1);
            if (ump.count(cnt))
                max_len = max(max_len, i-ump[cnt]);
            else
                ump[cnt] = i;
        }
        return max_len;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组,求子数组,子数组满足1和0的个数相同.
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

