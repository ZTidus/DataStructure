#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *171. Excel Sheet Column Number
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int n = s.size();
        int cnt = n - 1;
        for (char c : s)
        {
            
            res += (c - 'A' + 1) * pow(26, cnt);
            cnt--;
        }
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 进制转换问题
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 


