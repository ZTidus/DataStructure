#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: string  */
/* 题目信息 */
/*
 *38. Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
 */

/* my solution */


/* better solution */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // base case
        string prevRes = countAndSay(n - 1);
        int count = 1; // count
        string res;
        for (int i = 0; i < prevRes.size(); i++)
        {
            if (prevRes[i] == prevRes[i + 1]) // find out the same number's freq
            {
                count++;
                continue;
            }
            else
            {
                if (prevRes[i] != prevRes[i + 1])
                {
                    res += to_string(count) + prevRes[i];
                    count = 1; // reset
                }
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 报数
//
// 需要注意的点: 
// 1. 后一个是对前一个的报数
// 2. 不理解在下边手动模拟一遍就可以看懂了
// 3. 
// 模拟
// 1 → "1"
// 2 → "1" 个"1" → "11"
// 3 → "2" 个"1" → "21"
// 4 → "1" 个"2" "1"个"1" → "1211"

