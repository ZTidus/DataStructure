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
 *1408. String Matching in an Array
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
 */

/* my solution */
// solution-1, 4ms, defeat 95.77%
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        set<string> st;
        
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (words[i] != words[j])
                {
                    if (words[i].find(words[j]) != string::npos)
                    {
                        st.insert(words[j]);
                    }
                }
            }
        }
        
        for (string s : st)
        {
            res.push_back(s);
        }
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一个字符串数组，找出其中字符串为其他字符串子串的字符串。
//
// 需要注意的点: 
// 1. str.find(str2): 若str2为str的子串，返回str2在str中的下标.
// 2. 注意：有可能之串会重复，需要消除掉重复的字符串。
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

