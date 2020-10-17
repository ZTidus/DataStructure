#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* offer */
/* Type: math */
/* 题目信息 */
/*
 *剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
 

提示： 0 <= n <= 100
 */

/* my solution */


/* better solution */
class Solution {
public:
    int constant = 1000000007;
    int fib(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        int temp = 0;

        for (int i = 2; i <= n; i++)
        {
            temp = first + second;
            first = second % constant;
            second = temp % constant;
        }
        
        return temp % constant;
    }
};

/* 一些总结 */
// 1. 题意: fib求解。
//
// 需要注意的点: 
// 1. 注意题目中最后注明的有一个取余的操作。
// 2. 不仅可以使用数组，而且可以使用first, second变量记录求取元素的前两个值，这两个值不断迭代。
// 3. 

