#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: greedy */
/* 题目信息 */
/*
 *
 */

/* my solution */


/* better solution */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxReachPos = nums[0];
        int curMaxReachPos = nums[0]; 
        int minStep = 1; // 最少跳跃次数
        for (int i = 1; i <= min(n - 1, maxReachPos); i++)
        {
            curMaxReachPos = max(curMaxReachPos, i + nums[i]);
            if (i == n - 1)
                return minStep; // why?
            if (i == maxReachPos)
            {
                maxReachPos = curMaxReachPos;
                minStep++;
            }
        }
        
        return 0;
    }
};

// better 
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0; // 如果数组元素个数小于2, 不用跳
        int curMaxPos = nums[0];
        int preMaxMaxPos = nums[0];
        int minStep = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > curMaxPos)
            {
                minStep++;
                curMaxPos = preMaxMaxPos;
            }
            
            preMaxMaxPos = max(preMaxMaxPos, nums[i] + i);
        }
        
        return minStep;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

