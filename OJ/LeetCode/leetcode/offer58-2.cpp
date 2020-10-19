#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: string */
/* 题目信息 */
/*
 *剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000

 */

/* my solution */
// solution-1, 4ms, defeat 92.74%
// 1. substr()
// 2. erase()
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp = s.substr(0, n);
        s += temp;
        s.erase(s.begin(), s.begin() + n);
        return s;

    }
};

// solution-2
// 1. 使用循环进行。
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = "";
        for (int i = n; i < s.size(); i++) res += s[i];
        for (int i = 0; i < n; i++) res += s[i];
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

