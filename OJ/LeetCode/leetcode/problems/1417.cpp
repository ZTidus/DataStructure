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
 *1417. Reformat The String

Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
 */

/* my solution */
// solution-1, 4ms, defeat 95.92%
class Solution {
public:
    string reformat(string s) {
        // boundary
        if (s.size() == 1)
            return s;
        

        bool is_all_alpha = true;
        bool is_all_digit = true;
        for (char c : s) {
            if (!isalpha(c)) {
                is_all_alpha = false;
                break;
            }
        }
        
        for (char c : s) {
            if (!isdigit(c)) {
                is_all_digit = false;
                break;
            }
        }
        
        if (is_all_alpha || is_all_digit)
            return "";
        


        // ---------------
        int alpha_nums = 0;
        int digit_nums = 0;
        vector<char> digits;
        vector<char> alphas;
        for (char c : s) {
            if (isalpha(c)) {
                alphas.push_back(c);
                alpha_nums++;
            }
            if (isdigit(c)) {
                digits.push_back(c);
                digit_nums++;
            }
        }
        
        string res = "";
        
        if (abs(alpha_nums - digit_nums) >= 2)
            return "";
        else {
            int round = min(alpha_nums, digit_nums);
            if (alpha_nums > digit_nums) {
                for (int i = 0; i < round; i++) {
                    res += alphas[i];
                    res += digits[i];
                }
                res += alphas.back();
            }
            else if (alpha_nums < digit_nums) {
                for (int i = 0; i < round; i++) {
                    res += digits[i];
                    res += alphas[i];
                }
                res += digits.back();
            }
            else{
                for (int i = 0; i < round; i++) {
                    res += digits[i];
                    res += alphas[i];
                }
                
            }
        }
        
        return res;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 隔着输出数字和字母.
//
// 需要注意的点: 
// 1. 条件控制写的确实很麻烦...
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string s = "a0b1c2";
    Solution solution;
    string res = solution.reformat(s);
    cout << res;

    return 0;
}

