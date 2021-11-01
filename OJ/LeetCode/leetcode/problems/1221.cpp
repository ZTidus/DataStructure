#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1221. Split a String in Balanced Strings

Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
Example 4:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
 

Constraints:

1 <= s.length <= 1000
s[i] = 'L' or 'R'
 */

/* my solution */


/* better solution */
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int balance = 0;
        for (char c : s)
        {
            if (c == 'R') balance++;
            else balance--;
            
            if (balance == 0) res++;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 一组字符串中含有相同数量的'R'和'L', 看这个字符串可以分成几组，每个组中R和L数量相同。
//
// 需要注意的点: 
// 1. R和L的顺序不用管，只有R和L数量相等即可。
// 2. 
// 3. 

