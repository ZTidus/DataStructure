#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
// none
/* better solution */
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        //int len = A.size();
        // 1. 为每一行中的每一个字母建立频次矩阵
        //int frequency[A.size()][26] = {0};
        int frequency[A.size()][26] = {0};
        
        vector<int> common; // res
        
        // 2. 计算每一个字符串中各字母的频次
        for (int i = 0; i < len; i++) 
        {
            for (auto ch : A[i]) 
            {
                frequency[i][ch-'a']++; 
            }
        }
        
        // 3. 遍历频次矩阵中的
        for (char ch = 0; ch < 26; ch++) 
        {
            int minFrequency = 100;
            for (int i = 0; i < len; i++) 
            {
                if (minFrequency > frequency[i][ch])
                    frequency[i][ch] = minFrequency;
            }
            
            //
            for (int i = 0; i < minFrequency; i++)
            {
                commin.push_back(string(1, ch+'a'));
            }
        }
        
        return common;
    }
};
/* 一些总结 */

