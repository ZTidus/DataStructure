#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:

1 <= n <= 45
 */

/* my solution */


/* better solution */
// 1. brute force
// ✗ Time Limit Exceeded
class Solution {
public:
    int climb_stair(int step, int top)
    {
        if (step > top)
            return 0;
        if (step == top)
            return 1;
        return climb_stair(step+1, top) + climb_stair(step+2, top);
    }
    
    int climbStairs(int n) {
        return climb_stair(0, n);
    }
};

// 2. Recursion with Memoization
// ✓
class Solution {
public:
    int climb_stair(int i, int n, vector<int>& memo)
    {
        if (i > n) return 0;
        if (i == n) return 1;
        if (memo[i] > 0) return memo[i];
        memo[i] = climb_stair(i+1, n, memo) + climb_stair(i+2, n, memo);
        
        return memo[i];
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1);
        return climb_stair(0, n, memo);
    }
};
/* 一些总结 */
// 1. 题意: 
//[题意]爬楼梯，每次可以爬一阶或是二阶，问有多少中方法可以爬到顶部。
// 需要注意的点: 
// 1. 数组记录每个state的值
// 2. 
// 3. 

