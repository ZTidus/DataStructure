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
 *1556. Thousand Separator
Given an integer n, add a dot (".") as the thousands separator and return it in string format.

 

Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"
Example 3:

Input: n = 123456789
Output: "123.456.789"
Example 4:

Input: n = 0
Output: "0"
 

Constraints:

0 <= n < 2^31
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string thousandSeparator(int n) {
        string num = to_string(n);
        int len = num.size();
        if (len <= 3)
            return num;
        else {
            int cnt = 1;
            for (int i = len - 1; i >= 0; i--) {
                if (cnt % 3 == 0 && cnt != len)
                    num.insert(i, 1, '.');
                cnt++;
            }
        }
        return num;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 基本字符串操作.
//
// 需要注意的点: 
// 1. string.insert操作
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

