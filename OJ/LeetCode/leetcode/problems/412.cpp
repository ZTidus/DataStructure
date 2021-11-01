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
/* Type: string  */
/* 题目信息 */
/*
 *412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 != 0)
                res.push_back("Fizz");
            else if (i % 3 != 0 && i % 5 == 0)
                res.push_back("Buzz");
            else if (i % 3 == 0 && i % 5 == 0)
                res.push_back("FizzBuzz");
            else
            {
                //char x = i + '0';
                //string str = "";
                //str += x;
                res.push_back(to_string(i));
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. to_string的用法要掌握
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

