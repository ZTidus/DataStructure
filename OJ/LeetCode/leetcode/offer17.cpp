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
 *剑指 Offer 17. 打印从1到最大的n位数
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：
用返回一个整数列表来代替打印
n 为正整数
 */

/* my solution */
// solution-1, 8ms, defeat 93.50%
// 没有考虑大数问题!
class Solution {
public:
    vector<int> printNumbers(int n) {
        int num = pow(10, n);
        vector<int> res;
        for (int i = 1; i < num; i++)
            res.push_back(i);
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

