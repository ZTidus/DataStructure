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
 *125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 65.92%
// 将除字母和数字外的字符过滤，存入一个新的字符串中，将这个字符串颠倒后，如果和原来的字符串相同，则为true
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s)
        {
            if (isalnum(c))
            {
                if (isupper(c))
                    c = tolower(c);
                str += c;
            }
        }
        
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        
        return str == rev_str;
        
    }
};

/* 一些总结 */
// 1. 题意: 判断一个字符串是否为回文串，但是这个字符串中包含空格
//
// 需要注意的点: 
// 1. `isalpha()`: 判断字符是否为字母
// 2. `isalnum()`: 判断字符是否为数字或字母
// 3. `islower()`: 判断字符是否为小写字母
// 4. `isupper()`: 判断字符是否为大写字母

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

