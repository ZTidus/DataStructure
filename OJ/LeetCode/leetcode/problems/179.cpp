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
/* Type: sort */
/* 题目信息 */
/*
 *179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
Example 3:

Input: nums = [1]
Output: "1"
Example 4:

Input: nums = [10]
Output: "10"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 4ms, defeat 98.59%
// 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < num.size(); i++)
            if (nums[i] == 0)
                x++;
        if (x == nums.size()) return "0";
        
        vector<string> s(nums.size(), ""); // 使用数组存储string这一步，是很关键的, 因为需要对字符串进行排序!
        for (int i = 0; i < nums.size(); i++)
            s[i] = to_string(nums[i]);
        
        sort(s.begin(), s.end(), cmp);
        
        string res = "";
        for (int i = 0; i < s.size(); i++)
            res += s[i];
        
        return res;
        
    }
private:
    bool cmp(string &s1, string &s2) {
        return (s1 + s2) > (s2 + s1);
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，返回由数组中的数字所组成的最大的字符串。
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

