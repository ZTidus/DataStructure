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
/* Type: string */
/* 题目信息 */
/*
 *58. Length of Last Word
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        
        int i = len - 1;
        // 消除末尾多余空格
        while (s[i--] == ' ')
            s.erase(s.size() - 1, s.size());
        
        if (s.size() == 0)
            return 0;   
        if (s.size() == 1 && s[s.size() - 1] == ' ')
            return 0;
        
        
        
        bool flag = false; // space mark
        
        // 注意使用新的字符串长度
        for (int k = s.size() - 1; k >= 0; k--) {
            if (s[k] == ' ') {
                flag = true;
                return s.size() - 1 - k;
            }
        }
        if (!flag)
            return s.size();
        return 0;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串，求出字符串中最后一个单词的长度
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
    string input = "      ";
    string input2 = " a ";
    int res = solution.lengthOfLastWord(input2);
    cout << res;
        

    return 0;
}

