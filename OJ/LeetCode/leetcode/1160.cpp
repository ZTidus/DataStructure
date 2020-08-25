#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *1160. Find Words That Can Be Formed by Characters
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
 */

/* my solution */


/* better solution */
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        string res = "";
        unordered_map<char, int> mp;
        for (char c: chars)
        {
            mp[c]++;
        }
        
        for (auto str: words)
        {
            bool flag = true;
            unordered_map<char, int> mp2;
            for (auto c: str)
                mp2[c]++;
            for (auto c: str)
            {
                if (mp2[c] > mp[c])
                    flag = false;
            }
            
            if (flag) res += str;
        }
        
        return res.size();
    }
};

/* 一些总结 */
// 1. 题意: 
// 看string类型的chars中字符能否组成words中每一个单词，如果可以组成，将这个单词的长度添加入结果之中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

