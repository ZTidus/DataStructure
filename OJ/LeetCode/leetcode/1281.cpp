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
 *1281. Subtract the Product and Sum of Digits of an Integer
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 

Constraints:

1 <= n <= 10^5
 */

/* my solution */
// solution-1, 0ms, defeat 100%
// 将数字转化为string,这样好算出每一个数字.
class Solution {
public:
    int subtractProductAndSum(int n) {
        string str = to_string(n);
        int len = str.size();
        vector<int> nums;
        for (int i = 0; i < len; i++) {
            nums.push_back(str[i] - '0');
        }
        
        int product = product_of_each_digit(nums);
        int sum = sum_of_each_digit(nums);
        
        return product - sum;
    }
private:
    int product_of_each_digit(vector<int> vec) {
        int product = 1;
        for (int i : vec) {
            product *= i;
        }
        return product;
    }
    
    int sum_of_each_digit(vector<int> vec) {
        int sum = 0;
        for (int i : vec)
            sum += i;
        return sum;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一整数,算出这个的整数的各位数字,计算出数字的积和数字的和,返回两者的差.
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

