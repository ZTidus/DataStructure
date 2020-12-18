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
 *557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

/* my solution */
// solution-1, 28ms, defeat 27.73%
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        if (s.size() == 0)
            return res; // 这句加入后时间变为20ms
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
                temp = "";
                continue;
            }
            temp += c;
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        
        //for (int i = res.size() - 1; i >= 0; i--) {
        //    if (res[i] == ' ')
        //        res.erase(i-1, i);
        //}
        return res;
    }
};

/* better solution */
// solution-2, 24ms, defeat 45.20%
// 下面这种写法更简洁
class Solution2 {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        
        int i = 0;
        int len = s.size();
        int j = 0;
        while (i < len) {
            j = i + 1;
            while (s[j] != ' ' && j < len) j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1; // 跳过空格!
        }
        return s;
        
    }
};

/* 一些总结 */
// 1. 题意: 
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
    string input = "Let's take LeetCode contest";
    string res = solution.reverseWords(input);
    cout << res;

    return 0;
}

