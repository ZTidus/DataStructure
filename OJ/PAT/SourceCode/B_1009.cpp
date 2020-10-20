#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1009 说反话 (20分)
 */

/* my solution */
// solution-x, ms, defeat %

int main(int argc, char *argv[])
{
    char str[81];
    cin.getline(str, 81);
    //scanf("%s", str);
    //printf("%s", str);
    string s = str;
    string res = "";
    //cout << s;
    int n = s.size();
    int i = n - 1, j = n - 1;
    while (i >= 0)
    {
        while (i >= 0 && s[i] != ' ') i--; // 跳到空格处
        res += s.substr(i+1, j-i);
        res += " "; 
        while (i >= 0 && s[i] == ' ') i--; // 跳过空格
        j = i;
    }
    // 去掉空格
    if (res.size() > 0 && res[0] == ' ') res.erase(s.begin());
    if (res.size() > 0 && res[res.size() - 1] == ' ') res.erase(res.begin() + res.size() - 1);
    cout << res;

    return 0;
}

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 翻转字符串
//
// 需要注意的点: 
// 1. 注意空格的删除
// 2. 
// 3. 

