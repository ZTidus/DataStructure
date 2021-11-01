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
 *1624. Largest Substring Between Two Equal Characters
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
Example 4:

Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
 

Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.
 */

/* my solution */
// solution-1, 28ms, defeat 51.90%
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            char base = s[i];
            int count = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] != base)
                    count++;
                else if (s[j] == base) {
                    res = max(res, count);
                    count++; // 注意这里!例如字符串s中有多个字符t,当遍历完t后,还要将当前t计入count,以期待遇到下一次t时更新.
                }
            }
        }
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,找到相同字符之间的最长子串长度.
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

