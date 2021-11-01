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
 * 383. Ransom Note
 *Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (char c : magazine)
            mp[c]++;
        
        bool res = true;
        for (char c : ransomNote) {
            if (mp[c] > 0) {
                mp[c]--;
            } else {
                res = false;
            }
        }
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定str1和str2,检查str2所提供的字符是否可以组成str1
//
// 需要注意的点: 
// 1. 在这道题中我错用了map.count(c),
// 我认为如果一个map中,某个字符的频次为0后,这个count结果返回就是0,但是这个只是map检查它自己中是否有这个键,和这个键的频次是没有关系的.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string ransomNote = "aa"; 
    string magazine = "ab";
    Solution solution;
    bool res = solution.canConstruct(ransomNote, magazine);
    cout << res;

    return 0;
}

