#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

/* my solution */


/* better solution */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        
        // find out the non-zero and the push it to res
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != 0)
                res.push_back(nums[i]);
        }
        printf("res's size = %d\n", res.size());
        // find out the zero's freq
        int zeros = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 0)
                zeros++;
        }
        printf("zeros = %d\n", zeros);
        // push 0 to res
        while (zeros--)
            res.push_back(0);
        // res to nums
        for (int i = 0; i < len; i++)
        {
            nums[i] = res[i];
        }
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 如果没有返回类型的话，代表要在原数组上修改，但是在过程中可以新开一个数组存储，最后在赋值回去。
// 2. 
// 3. 

