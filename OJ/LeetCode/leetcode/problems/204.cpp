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
 *204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 10^6
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
// class Solution {
// public:
//     int countPrimes(int n) {
//         int res = 0;
//         for (int k = 0; k < n; k++)
//             if (isPrime(k))
//             {
//                 res++;
//             }
//         return res;
//         
//     }
// private:
//     bool isPrime(int i)
//     {
//         if (i < 2) return false;
//         for (int j = 2; j <= sqrt(i); j++)
//         {
//             if (i % j == 0 && i != j)
//                 return false;
//         }
//         return true;
//     }
// };

/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        vector<bool> primes(n, true);
        primes[0] = false, primes[1] = false;
        for (int i = 0; i < sqrt(n); i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j+=i)
                {
                    primes[j] = false;
                }
            }
        }
        
        return count(primes.begin(), primes.end(), true);
        
    }
};

/* 一些总结 */
// 1. 题意: 计算小于n的区间中有多少prime number
//
// 需要注意的点: 
// 1. Sieve of Eratosthenes: algorithm steps for primes
// 2. 暴力操作会超时
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

