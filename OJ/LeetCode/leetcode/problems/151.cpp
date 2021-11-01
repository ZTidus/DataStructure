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
 *
 */

/* my solution */
// solution-1, 8ms, defeat 50%
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        // remove begining and end space
        while (s[0] == ' ')
            s.erase(s.begin());
        while (s.back() == ' ')
            s.erase(s.size() - 1);
        
        vector<string> vec;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                vec.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        vec.push_back(temp);
        
        reverse(vec.begin(), vec.end());
        string res = "";
        for (string str : vec) {
            if (str == "") // important
                continue;  // remove middle space
            res += str;
            res += ' ';
        }
        res.erase(res.size() - 1);
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,翻转字符串中的单词.
//
// 需要注意的点: 
// 1. 字符串前后的空格要删去,但是词与词中间的多个空格不能删去.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input = "a good   example";
    string res = solution.reverseWords(input);
    cout << res;

    return 0;
}

