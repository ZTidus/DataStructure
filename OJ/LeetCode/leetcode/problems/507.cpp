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
/* Type: math */
/* 题目信息 */
/*
 *507. Perfect Number

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 6
Output: true
Example 3:

Input: num = 496
Output: true
Example 4:

Input: num = 8128
Output: true
Example 5:

Input: num = 2
Output: false
 

Constraints:

1 <= num <= 108
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
//
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
                res += i;
        }
        
        return num == res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 看一个数是不是完美数字: 数字等于所有正数因子之和
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

