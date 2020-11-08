#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 */

/* my solution */
// solution-1, 64ms, defeat 24.69%
// 给两个字符串排序，然后比较即可, 当然也可以使用hash table记录每个字符的频次
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 查看给定的两个字符串是不是构成回文
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

