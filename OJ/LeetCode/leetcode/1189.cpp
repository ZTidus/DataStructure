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
/* Type: hash table */
/* 题目信息 */
/*
 *1189. Maximum Number of Balloons
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.
 */

/* my solution */
// solution-1, 12ms, defeat 13.89%
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp; // map换成unordered_map, 时间变为8ms, 36.61%
        for (char c : text)
            mp[c]++;
        
        string base = "balloon";
        vector<int> nums;
        for (char c : base) {
            if (c == 'l' || c == 'o') {
                nums.push_back(mp[c] / 2);
                continue;
            }
            nums.push_back(mp[c]);
        }
        
        int min_val = nums[0];
        for (int i : nums)
            min_val = min(min_val, i);
        
        return min_val;
    }
};

/* better solution */
// solution-2, 4ms, defeat 81.51%
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b, a, l, o, n;
        b = 0;
        a = 0;
        l = 0;
        o = 0;
        n = 0;
        for (char c : text) {
            b += (c == 'b') ? 1 : 0;
            a += (c == 'a') ? 1 : 0;
            l += (c == 'l') ? 1 : 0;
            o += (c == 'o') ? 1 : 0;
            n += (c == 'n') ? 1 : 0;
        }
        
        return min({b, a, l / 2, o / 2, n});
        
    }
};

/* 一些总结 */
// 1. 题意: 给定一字符串,看这个字符串中的字符可以组成多少个balloon.
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

