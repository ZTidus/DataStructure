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
 *438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 20ms, defeat 69.85%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int l = p.size(); // window size
        vector<int> res;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0); // 使用vector当hashtable
        
        for (char c : p) vp[c - 'a']++;
        for (int i = 0; i < n; i++)
        {
            // 索引大于window size
            if (i >= l)
                vs[s[i - l] - 'a']--; // 移除窗口最左边元素
            // 更新窗口, 加入当前元素
            vs[s[i] - 'a']++;
            
            // 如果vs == vp, 推入当前滑动窗口最左元素下标
            if (vs == vp) res.push_back(i + 1 - l);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 给定字符串s,和字符串p，在s中寻找与p相同的子串，顺序不管。
// 使用滑动窗口和hashtable, 每次找寻到相同的vector,就推入滑动窗口最左元素下标
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

