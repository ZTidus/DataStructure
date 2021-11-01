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
/* Type: stack */
/* 题目信息 */
/*
 *150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 */

/* my solution */
// solution-1, 16ms, defeat 81.55%
// ✓
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string c : tokens)
        {
            //char c = c0[0];
            if (atoi(c.c_str()) || c == "0")
                stk.push(atoi(c.c_str()));
                //stk.push(atoi(c.c_str()) - '0');
                //stk.push(c - '0');
            else
            {
                int a1 = stk.top(); stk.pop();
                int a2 = stk.top(); stk.pop();
                if (c == "+")
                    stk.push(a1 + a2);
                else if (c == "-")
                    stk.push(a2 - a1);
                else if (c == "*")
                    stk.push(a1 * a2);
                else
                    stk.push(a2 / a1);
            }
        }
        
        return stk.top();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 逆波兰求解表达式
//
// 需要注意的点: 
// 1.
// 因为vector中存储的是string,一开始想要使用isdigit()进行判断，但是这个函数的参数需要是字符，所有使用了atoi()进行转换
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    //vector<string> input = { "2", "1", "+", "3", "*" };
    //vector<string> input = {"4","13","5","/","+"};
    vector<string> input = {"0", "3", "/"};
    int res = solution.evalRPN(input);
    cout << res;

    return 0;
}

