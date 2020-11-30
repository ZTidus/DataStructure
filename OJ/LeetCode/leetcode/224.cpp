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
 *224. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 94.73%
class Solution {
public:
    int calculate(string s) {
        stack<int> stk, op;
        int res = 0;
        int sign = 1;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                double num = c - '0';
                // 数字位数大于1,需要将字符串转换成为数字
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                res += num * sign;
            }
            else if (c == '+')
                sign = 1;
            else if (c == '-')
                sign = -1;
            else if (c == '(') {
                stk.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res = res * op.top(); op.pop();
                res += stk.top(); stk.pop();
            }
        }
        return (int)res;
        
    }
};

/* 一些总结 */
// 1. 题意: 对字符串表达式求值
//
// 需要注意的点: 
// 1. 括号那一步需要加强理解。
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input =  "(1+(4+5+2)-3)+(6+8)";
    int res = solution.calculate(input);
    cout << res << endl;

    return 0;
}

