#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: stack */
/* 题目信息 */
/*
 *946. Validate Stack Sequences
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
 */

/* my solution */


/* better solution */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        stack<int> stk;
        
        int j = 0;
        for (int x : pushed)
        {
            stk.push(x);
            while (!stk.empty() && j < n && stk.top() == popped[j])
            {
                stk.pop();
                j++;
            }
        }
        
        if (!stk.empty())
            return false;
        
        return true;
    }
};

/* 一些总结 */
// 1. 题意: 给定一个输入序列，一个输出序列，验证这个输出序列是否是以输入序列入栈后的输出序列
// 解决：每次pushed进栈一个元素，检查当前栈的栈顶是否和输出序列当前所指元素相同，不同则继续进栈，相同则出栈，并且输出序列指针(其实是地址)后移一位。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

