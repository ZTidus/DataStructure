#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1002. Find Common Characters
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
 */

/* my solution */
// none
/* better solution */
//
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, 0);
        vector<int> tmp(26, 0);
        // standard
        for (auto c: A[0])
            count[c - 'a']++;
        // compare
        for (int i = 1; i < A.size(); i++) {
            
            for (auto c: A[i])
            {
                tmp[c - 'a']++;
            }
            
            for (int j = 0; j < 26; j++)
            {
                count[j] = min(count[j], tmp[j]);
                tmp[j] = 0;
            }
                
        }
        
        // output
        vector<string> res;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                int cnt = count[i];
                while (cnt--)
                {
                    char x = i + 'a';
                    //string s = x;
                    string s;
                    s = x;
                    res.push_back(s);
                }
            }
        }
        
        return res;
    }
};
//  
// 先将A中第一个string做一个基准，然后对剩余的string进行遍历，每次遍历完一个string后，就与基准作一个对比，得到其中最少频数并更新基准，这样遍历完之后的string后，基准中那些频数大于1的字符就是这些string中共同的字符，之后输出。
/* 一些总结 */

