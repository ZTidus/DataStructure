#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 43. 1～n 整数中 1 出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
// brute force 
// time limited
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << getOnes(n) << endl;
            res += getOnes(i);
            //cout << res << endl;
        }
        return res;
    }
private:    
    int getOnes(int num)
    {
        int oneNumber = 0;
        while (num)
        {
            if (num % 10 == 1)
                oneNumber++;
            num /= 10;
        }
        return oneNumber;
    }
        
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

