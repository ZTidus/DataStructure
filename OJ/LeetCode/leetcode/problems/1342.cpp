#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: bit */
/* 题目信息 */
/*
 *1342. Number of Steps to Reduce a Number to Zero
Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12
 

Constraints:

0 <= num <= 10^6
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0)
        {
            // num is even
            if (num % 2 == 0)
                num /= 2;
            else
                // odd
                num--;
            step++;
        }
        return step;
        
    }
};

/* better solution */
// solution-2, 0ms, defeat 100%
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0)
        {
            // odd
            if (num & 1)
                num--;
            else
                // even
                num >>= 1;
            step++;
        }
        return step;
        
    }
};

/* 一些总结 */
// 1. 题意: 数步数，如果一个数为偶数，则除以2,若为奇数，则减一，知道最后为0,返回进行了几次。
//
// 需要注意的点: 
// 1. 判断奇偶，num & 1, 与操作，为1则为奇数，为0为偶数。
// 2. 除以2使用>>右移代替
// 3. 

