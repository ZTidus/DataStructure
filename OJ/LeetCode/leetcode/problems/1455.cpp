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
 *1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Given a sentence that consists of some words separated by a single space, and a searchWord.

You have to check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string S is any leading contiguous substring of S.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
Example 4:

Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4
Example 5:

Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string temp = "";
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        words.push_back(temp);
        // test ok
        //cout << words.size() << " " << words.back() << endl;
        
        int res = -1;
        int cnt = 1;
        
        for (string str : words) {
            if (str.find(searchWord) != str.npos) {
                // 检查searchWord是否为str的前缀
                int prefix = str.find(searchWord);
                if (prefix == 0) {
                    res = cnt;
                    break;
                }
            }
            cnt++;
        }
        
        return res;
    }
};

// 上边代码第86到93行代码更加精简的写法
//        for (string str : words) {
//            if (str.find(searchWord) == 0)
//                res = cnt;
//            cnt++;
//        }

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一字符串str1,还有另一个字符串str2,检查str2是否为str1中某个词的前缀.
//
// 需要注意的点: 
// 1. str.find(str2)的用法
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

