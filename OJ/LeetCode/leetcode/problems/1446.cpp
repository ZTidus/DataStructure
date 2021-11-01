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
/* Type: string */
/* 题目信息 */
/*
 *1446. Consecutive Characters
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
 */

/* my solution */
// solution-1, 4ms, defeat 76.29%
class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char base = s[i];
            int temp = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == base)
                    temp++;
                else
                    break;
            }
            res = max(res, temp);
           
        }
        return res;
        
    }
};

// 上边的代码的一种改进写法,更简洁!
class Solution {
public:
    int maxPower(string s) {
        int count = 0;
        int max_count = 0;
        char previous = ' ';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == previous) {
                count++;
            } else {
                count = 1;
                previous = c;
            }
            max_count = max(max_count, count);
        }
        return max_count;
        
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,找到这个字符串中最长的字符相同的子串
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

    return 0;
}

