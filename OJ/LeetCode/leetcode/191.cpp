#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: bit manipulation  */
/* 题目信息 */
/*
 *191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above, the input represents the signed integer. -3.
Follow up: If this function is called many times, how would you optimize it?

 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            cnt++;
        }
        
        return cnt;
    }
};

/* 一些总结 */
// 1. 题意: 算出整数中1的个数
// 一个技巧: n & (n-1)可以消除n中的最后一个1
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

