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
// solution-x, ms, defeat %

class Solution {
public:
    string interpret(string command) {
        map<string, string> mp;
        mp["G"] = "G";
        mp["()"] = "o";
        mp["(al)"] = "al";
        
        string temp = "";
        string res = "";
        for (char c : command) {
            if (!mp.count(temp))
                temp += c;

            if (mp.count(temp)) { // 一开始我的这个代码段写成了上一个
                                  // if 的else块,但是结果是错误的.
                res += mp[temp];
                temp = "";
            }
        }
        
        return res;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 一个映射的设置.
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
    string command = "G()(al)";
    Solution solution;
    string res = solution.interpret(command);
    cout << res;



    return 0;
}

