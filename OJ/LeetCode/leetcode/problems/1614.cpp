#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1614. Maximum Nesting Depth of the Parentheses
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int maxDepth(string s) {
        int a = s.size();
        int res = 0, maxVal = 0;
        for (int i = 0; i < a; i++)
        {
            if (s[i] == '(')
                res++;
            else if (s[i] == ')')
                res--;
            
            maxVal = max(maxVal, res);
        }
        
        return maxVal;
        
    }
};

/* 一些总结 */
// 1. 题意: 给定一字符串，寻找字符串中括号的最深层数
// 维护一个最大值和层数，层数遇左括号加1,遇右括号减1,在遍历整个字符串中不断更新最大值，最终结果返回最大值。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

