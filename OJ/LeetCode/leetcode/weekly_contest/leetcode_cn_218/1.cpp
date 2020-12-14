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
// solution-1, 0ms, defeat %
// ✓
class Solution {
public:
    string interpret(string command) {
        map<string, string> mp;
        mp["G"] = "G";
        mp["()"] = "o";
        mp["(al)"] = "al";

        string res = "";
        string temp = "";
        for (int i = 0; i < command.size(); i++) {
            temp += command[i];
            if (mp[temp].size() != 0) {
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
    string input = "G()(al)";
    string res = solution.interpret(input);
    cout << res;

    return 0;
}

