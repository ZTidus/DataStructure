#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *326. Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you do it without using any loop / recursion?
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 90.89%
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        
        while (n % 3 == 0)
            n /= 3;
        
        return n == 1;
        
    }
};

/* 一些总结 */
// 1. 题意: 检查一个数字是否为3的幂次
//
// n = 3^x
// n = 3 * 3 * 3 * 3 * 3 * ... * 3;
// 不断循环除以3,查看最终数字是否为1,循环条件为n%3 != 0
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

