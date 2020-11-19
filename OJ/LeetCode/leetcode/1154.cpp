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
 *1154. Day of the Year
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int dayOfYear(string date) {
        int yy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8, 2));
        
        int res = dd; // 初始化为当月的天数
        vector<int> month({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        
        if (isLeapYear(yy))
            month[1] = 29; // 润年2月是29天
        for (int i = 0; i < mm - 1; i++)
        {
            res += month[i];
        }
        
        return res;
    }
    
private:
    bool isLeapYear(int y)
    {
        // 润年
        // 1. 能被400整除
        // 2. 是4的倍数但不是100的倍数
        if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) 
            return true;
        return false;
    }
};

/* 一些总结 */
// 1. 题意: 
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

