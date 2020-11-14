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
/* Type: backtracking */
/* 题目信息 */
/*
 *46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 4ms, defeat %
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        helper(nums, 0, nums.size() - 1);
        return _res;
    }
private:
    vector<vector<int> > _res;
    void helper(vector<int> num_arr, int l, int r)
    {
        if (l == r)
            _res.push_back(num_arr);
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(num_arr[l], num_arr[i]);
                helper(num_arr, l + 1, r);
                swap(num_arr[l], num_arr[i]); // backtracking
            }
        }
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，求数组元素的全排列
//
// 需要注意的点: 
// 1. 使用backtracking
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    vector<vector<int> > res;
    vector<int> nums = {1, 2, 3};
    res = solution.permute(nums);

    return 0;
}

