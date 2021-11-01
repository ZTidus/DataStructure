#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *202. Happy Number
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */

/* my solution */
// solution-x, ms, defeat %
/*
class Solution {
public:
    bool isHappy(int n) {
        int res = sum_digit_square(n);
        int cnt = 0;
        while (res != 1)
        {
            cnt++;
            cout << "running..." << cnt << endl;
            res = sum_digit_square(res);
            if (res == 1)
                return true;
                
        }
        
        return true;
    }
private:
    int sum_digit_square(int num)
    {
        int sum = 0;
        while (num)
        {
            int remainder = num % 10;
            num /= 10;
            sum += remainder * remainder;
        }
        return sum;
    }
};

*/

// 上边这种做法是错误的, 因为如果陷入死循环后，就只能一直死循环下去，但是
// 不知道进入死循环的条件是什么？
// 下面找到一个例子 from leetcodeAnimation
// 我们先举一个例子

// 输入： 59
// 1. 5^2 + 9^2 = 106
// 2. 1^2 + 0^2 + 6^2 = 37
// 3. 3^2 + 7^2 = 58
// 4. 5^2 + 8^2 = 89
// 5. 8^2 + 9^2 = 145
// 6. 1^2 + 4^2 + 5^2 = 42
// 7. 4^2 + 2^2 = 20
// 8. 2^2 + 0^2 = 4
// 9. 4^2 = 16
// 10. 1^2 + 6^2 = 37
// 
// 这个例子，我们可以看到输入59，第10步的结果和第2步一样，一直进行计算的话，会死循环，所以这个数肯定不会是快乐树。

/* better solution */
// solution-2, 0ms, defeat 100%
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int res = sum_digit_square(n);
        s.insert(res);
        while (res != 1)
        {
            res = sum_digit_square(res);
            if (s.count(res)) return false;
            s.insert(res);
        }
        
        return true;;
    }
private:
    int sum_digit_square(int num)
    {
        int sum = 0;
        while (num)
        {
            int remainder = num % 10;
            num /= 10;
            sum += remainder * remainder;
        }
        return sum;
    }
};

/* 一些总结 */
// 1. 题意: 寻找快乐数。
//
// 需要注意的点: 
// 1. 关键点在于如何判断死循环。使用一个set，在求解过程中如果发现求出了同样的数字，则是进入死循环的标志
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    int input = 2;
    bool res = solution.isHappy(input);
    cout << res;

    return 0;
}

