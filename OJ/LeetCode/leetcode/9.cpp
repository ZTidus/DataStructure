#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
 */

/* my solution */
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. x < 0 won't be a palindrome
        // and if the last digit of x is 0, x won't be a palindrome.
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int compare = x;
        int revertedNum = 0;
        while (x)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        printf("%d\n", revertedNum);
        return compare == revertedNum;
        //if (x == revertedNum)
        //    return true;
        //else 
        //    return false;
    }
};
// 这种方法会导致最后一个测试用例超时。

/* better solution */ 
// √
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. x < 0 won't be a palindrome
        // and if the last digit of x is 0, x won't be a palindrome either.
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        
        int revertedNum = 0;
        while (x > revertedNum)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        
        return x == revertedNum || x == revertedNum / 10;
    }
};

/* 一些总结 */
// 1. 需要考虑到输入的值特别大的情况，那个时候运行的时间会超过限制。

