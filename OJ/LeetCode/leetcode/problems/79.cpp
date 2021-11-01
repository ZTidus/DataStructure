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
 *79. Word Search
 */

/* my solution */
// solution-x, ms, defeat %
        map<char, int> mp;
        int m = board.size();
        int n = board[0].size();
        // borad char's freq
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[board[i][j]]++;
            }
        }
        // word char's freq
        for (int i = 0; i < word.size(); i++) {
            if (mp[word[i]]) {
                
            }
        }
        map<char, int> mp;
        int m = board.size();
        int n = board[0].size();
        // borad char's freq
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[board[i][j]]++;
            }
        }
        // word char's freq
        for (int i = 0; i < word.size(); i++) {
            if (!mp[word[i]]) {
                return false;
            }
            mp[word[i]]--;
        }
        return true;
    }
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一个mxn的字符矩阵，在矩阵中寻找一个单词，单词字符必须是挨着的。
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

