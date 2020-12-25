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
/* Type:  */
/* 题目信息 */
/*
 *1374. Generate a String With Characters That Have Odd Counts

Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

 

Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"
 

Constraints:

1 <= n <= 500
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string generateTheString(int n) {
        if (n == 0) return "";
        if (n == 1) return "a";
        
        string res = "";
        if (n % 2 == 0) {
            int len1 = 1;
            int len2 = n - 1;
            res += 'a';
            while (res.size() < n)
                res += 'b';
        } else {
            res += 'a';
            res += 'b';
            int len1 = n - 2;
            while (res.size() < n)
                res += 'c';
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 一道简单的字符串问题.
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

