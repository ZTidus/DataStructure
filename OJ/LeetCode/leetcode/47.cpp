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
/* Type:backtracking  */
/* 题目信息 */
/*
 *47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ?[1] 为什么要排序
        helper(nums, 0, nums.size() - 1);
        return _res;
        
    }
private:
    vector<vector<int> > _res;
    void helper(vector<int> nums_ano, int l, int r)
    {
        if (l == r)
            _res.push_back(nums_ano);
        else
        {
            for (int i = l; i <= r; i++)
            {
                if (i != l && nums_ano[i] == nums_ano[l]) // 跳过重复数字
                    continue;
                swap(nums_ano[l], nums_ano[i]);
                helper(nums_ano, l + 1, r);
                //swap(nums_ano[l], nums_ano[i]); // ?[2] 这一步为什么会舍去,
                //为什么不可以swap twice
            }
        }
            
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
    vector<int> nums = {1, 1, 2, 2};
    vector<vector<int> > output;
    
    output = solution.permuteUnique(nums);
    

    return 0;
}

