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
// solution-1, ms, defeat %
class Solution {
public:
    string reformatNumber(string number) {
        string temp1 = "";
        for (char c : number) {
            if (c == ' ' || c == '-')
                continue;
            temp1 += c;
        }
        cout << temp1 << endl;
        
        string res = "";
        int remainder = temp1.size() % 3;
        int groups = 0;
        if (remainder == 1) 
            groups = temp1.size() / 3 - 1;
        else
            groups = temp1.size() / 3;
        
        for (int group = 0; group < groups; group++) {
            int idx = 0;
            while (idx < 3) {
                res += temp1[3 * group + idx];
                idx++;
            }
            
            res += '-';
        }
        if (remainder == 1) {
            res += temp1.substr(temp1.size() - 4, 2);
            res += '-';
            res += temp1.substr(temp1.size() - 2, 2);
        }
        else
            res += temp1.substr(temp1.size() - remainder, temp1.size());
        
        // 抹除掉结尾多余的'-'
        if (res.back() == '-')
            res.erase(res.size()-1);

        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 字符串的一些简单操作.
//
// 需要注意的点: 
// 1. substr(position, n); // n: 代表n个字符
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input = "123 4-567";
    string res = solution.reformatNumber(input);
    cout << res;

    return 0;
}

