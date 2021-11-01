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
 *1684. Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> mp;
        // record allowed's characters' freq
        for (char c : allowed) {
            mp[c]++;
        }
        
        int res = 0;
        for (string str : words) {
            set<char> s;
            bool flag = true;
            for (char c : str) {
                s.insert(c);
            }
            
            for (char c : s) {
                if (!mp.count(c)) {
                    flag = false;
                    break;
                }
                    
            }
            if (flag)
                res++;
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一标准字符串,字符唯一,再给定一个字符串数组,字符不唯一,找到这个字符串数组中的字符串中有字符和标准字符串中的字符一样的字符串个数.
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

