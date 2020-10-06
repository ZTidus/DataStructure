#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *69. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
 */

/* my solution */


/* better solution */
// brute force
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        // 注意这个long long, 如果定义为int类型会导致溢出
        for (long long s = 1; s <= x; s++)
        {
            if (s * s > x)
                return s - 1;
        }
        
        return -1;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. huahua还有另外两种解，有兴趣可以了解一下
// 2. 
// 3. 

