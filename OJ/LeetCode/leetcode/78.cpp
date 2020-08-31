#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: backtracking combination */
/* 题目信息 */
/*
 *78. Subsets Medium
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

/* my solution */


/* better solution */
// 1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        
        return res;
    }
private:
    void backtrack(vector<vector<int>>& list, vector<int>& tempList, vector<int>& nums, int start)
    {
        list.push_back(tempList);
        for (int i = start; i < nums.size(); i++)
        {
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.pop_back();
        }
    }
};

// 2
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        for (int i = 0; i <= nums.size(); i++)
            dfs(nums, i, 0, cur, res);
        
        return res;
    }
private:
    void dfs(const vector<int>& nums, int n, int s,
             vector<int>& cur, vector<vector<int>>& res)
    {
        if (n == cur.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur, res);
            cur.pop_back();
        }
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. combination基本写法
// 2. 
// 3. 

