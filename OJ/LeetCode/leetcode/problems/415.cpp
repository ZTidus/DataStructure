#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: String */
/* 题目信息 */
/*
 *415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/* my solution */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0)
        {
            if (i >= 0)
            {
                carry = (num1[i] - '0') + carry;
                i--;
            }
            if (j >= 0)
            {
                carry = (num2[j] - '0') + carry;
                j--;
            }
            
            res = to_string(carry % 10) + res;
            carry /= 10;
        }
        
        return res;
    }
};

/* better solution */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int x1 = (i >= 0 ? num1[i] - '0' : 0);
            int x2 = (j >= 0 ? num2[j] - '0' : 0);
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res += to_string(value);
            i--;
            j--;
        }
        
        if (carry != 0)
            res += to_string(carry);
        reverse(res.begin(), res.end());
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. int to string，注意加上to_string()，它不会自动转换。
// 2. 下边这种方法更易于理解。
// 3. 

