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
 *387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 */

/* my solution */
// solution-1, 156ms, defeat 18.43%
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找到给定字符串中第一个频次为1的字符索引。
// 先算出每个字符的频次，然后遍历字符串每个字符，查看该字符频次是否为1
// 需要注意的点: 
// 1. 只找第一个频次为1的字符
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

