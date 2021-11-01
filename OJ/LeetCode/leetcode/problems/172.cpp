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
/* Type: math */
/* 题目信息 */
/*
 *172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

1 <= n <= 104
 */

/* my solution */
// solution-1, ms, defeat %
// runtime error
// class Solution {
// public:
//     int trailingZeroes(int n) {
//         int res = 1;
//         while (n > 0)
//         {
//             res = (res * n--);
//         }
//         
//         string str = to_string(res);
//         int zeros = 0;
//         for (int i = str.size() - 1; i >= 0; i--)
//         {
//             if (str[i] == '0')
//                 zeros++;
//             else
//                 break;
//         }
//         
//         return zeros;
//         
//     }
// };

/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 5)
        {
            n /= 5;
            res += n;
        }
        
        return res;
        
    }
};

/* 一些总结 */
// 1. 题意: 算出一个数的阶乘后，算出这个数字尾部有多少0
//
// 需要注意的点: 
// 1. 2*5 = 10 → 5的个数比2多的多 → 得出有多少5这个因子
// 2. 例如10有2个5：5, 10
// 3. 15有3个5：5, 10, 15

/*
 * main test
 */

int main(void)
{
    Solution solution;
    int input = 4;
    int res = solution.trailingZeroes(input);
    cout << res;

    return 0;
}

