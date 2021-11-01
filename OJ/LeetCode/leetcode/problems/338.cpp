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
/* Type: bit */
/* 题目信息 */
/*
 *338. Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */

/* my solution */
// solution-1, 44ms, defeat 5.32%
// so slow
class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            res.push_back(compute_one_nums(i));
        } 
        return res;
    }
private:
    int compute_one_nums(int num) {
        string num_to_bin = dec_to_bin(num);
        int one_nums = 0;
        for (char c : num_to_bin) {
            if (c == '1')
                one_nums++;
        }
        return one_nums;
    }
    
    string dec_to_bin(int num) {
        string res = "";
        while (num) {
            int remainder = num % 2;
            res += (remainder + '0');
            num /= 2;
        }
        // 省略了一个reverse字符串过程,但是这个二进制串的顺序和结果并不相关,省去也没事.
        return res;
    }
};

/* better solution */
// solution-2, 8ms, defeat 68.55%
// 位操作
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};

// i&(i-1) res[14] = res[12] + 1, 总是隔着一个数字
// 0, 1, 10, 11, 110, 111, 1110, 1111
// 0, +1, skip, +1, ...

/* 一些总结 */
// 1. 题意: 给定一整数n,计算从0到n(包括n)之内的二进制数的1的个数.
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

