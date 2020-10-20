#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: bit */
/* 题目信息 */
/*
 *剑指 Offer 16. 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

 

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
 

说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
// 位运算
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1.0;
        if (x == 0 && n < 0) return 0.0;
        double res = 1.0;
        long exp = n;
        if (n < 0)
        {
            x = 1 / x;
            exp = -exp;
        }
        
        while (exp)
        {
            // &操作判断奇偶
            if (exp & 1) res *= x;
            x *= x;
            exp >>= 1;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 位运算很不熟
// 2. 一些边界情况需要考虑
// 3. 

