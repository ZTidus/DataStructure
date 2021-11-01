#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: two pointers */
/* 题目信息 */
/*
 *输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 86.38%
// 1. 双指针初始都在字符串最右边
// 2. 从右向左扫描，每次扫描完一个单词就加入到结果中
// 3. 麻烦的是最后的空格的处理，需要自己进行处理一下。
class Solution {
public:
    string reverseWords(string s) {
        int r = s.size() - 1;
        int l = s.size() - 1;
        string res = "";
        while (l >= 0)
        {
            while (l >= 0 && s[l] != ' ') l--;
            res += s.substr(l + 1, r - l);
            cout << s.substr(l+1, r-l) << endl;
            cout << "l: " << l << endl;
            res += " ";
            // 跳过空格
            while (l >= 0 && s[l] == ' ') l--;
            r = l; // r指向下个单词的词尾
        }
        // remove the first space
        if (res.size() > 0 && res[0] == ' ')
            res.erase(res.begin());
        // remove the last space
        if (res.size() > 0 && res[res.size() - 1] == ' ')
            res.erase(res.begin() + res.size() - 1);
        
        return res;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

