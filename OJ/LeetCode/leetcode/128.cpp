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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 16ms, defeat 87.08%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int max_val = 1; // 最大连续序列长度
        int cur_val = 1; // 当前连续序列长度
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                    cur_val++;
                else
                {
                    max_val = max(max_val, cur_val);
                    cur_val = 1; // reset
                }
            }
        }
        
        return max(max_val, cur_val);
        
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中的最长连续子序列
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

