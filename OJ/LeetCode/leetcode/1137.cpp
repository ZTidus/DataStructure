#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1137. N-th Tribonacci Number
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 */

/* my solution */
class Solution {
public:
    int tribonacci(int n) {
        // recursive boundary
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        // recursion
        
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
// result
// Time Limit Exceeded

/* better solution */
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3;i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. dp is what? I saw it in the discuss area.
// 2. Need to record each state's value in vector.
// 3. Not recursion.

