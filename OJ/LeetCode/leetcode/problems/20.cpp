#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
//            if (stk.empty()) stk.push(s[i]);
            if (!stk.empty() && ((stk.top() == '(' && s[i] == ')') || \
                (stk.top() == '{' && s[i] == '}') || \
                (stk.top() == '[' && s[i] == ']')))
            {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }

        if (stk.empty())
            return true;
        return false;

    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 判断(){}[]是否匹配
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
    string input = "()";
    bool res = solution.isValid(input);
    cout << res;

    return 0;
}

