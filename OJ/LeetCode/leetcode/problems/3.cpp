#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: sliding window */
/* 题目信息 */
/*
 *3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 40ms, defeat 51.61%
// sliding window + map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int start = 0;
        
        map<char, int> mp; // 记录字符出现位置
        
        for (int i = 0; i < n; i++)
        {
            char c = s[i]; // 当前字符
            if (mp.count(c)) // 若当前字符出现过
            {
                start = max(start, mp[c] + 1); // 则start置为重复字符地址+1, 即滑动窗口左边索引右移一位
            }
            res = max(res, i - start + 1);
            mp[c] = i;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 寻找字符串中的最长无重复子串
//
// 需要注意的点: 
// 1. 手动模拟自然可以知道line 65是什么意思
// 2. 
// 3. 

