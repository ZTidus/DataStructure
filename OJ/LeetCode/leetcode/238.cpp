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
/* Type: array */
/* 题目信息 */
/*
 *238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> res;
//         
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int temp_product = 1;
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (i != j)
//                     temp_product *= nums[j];
//             }
//             res.push_back(temp_product);
//         }
//         
//         return res;
//     }
// };
// 
/* better solution */
// solution-1, 40ms, defeat 52.43%
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        // 第一次循环，每个位置存放i之前所有元素的乘积
        for (int i = 0, temp = 1; i < nums.size(); i++)
        {
            res[i] = temp;
            temp *= nums[i];
        }
        
        // 第二次循环，从后往前，每个位置和i之后的元素再次相乘
        for (int i = nums.size() - 1, temp = 1; i >= 0; i--)
        {
            res[i] *= temp;
            temp *= nums[i];
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
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

