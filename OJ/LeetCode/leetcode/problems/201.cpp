#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: bitwise */
/* 题目信息 */
/*
 *201. Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
 */

/* my solution */
// solution-x, ms, defeat %
// brute force
// time limited
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = m; i <= n; i++)
            m &= i;
        return m;
    }
};

/* better solution */
// solution-x, 0ms, defeat 100%
// bitwise
// 找到m和n的公共部分
// 例如26-30
// 26: 11010
// 27: 11011
// 28: 11100
// 29: 11101
// 30: 11110
// 找到相同的部分即11
// 然后在左移
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n)
        {
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        return n << count;
    }
};

/* 一些总结 */
// 1. 题意: 求m和n之间（包括m和n）所有数的与操作并返回。
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

