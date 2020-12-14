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
 *
 */

/* my solution */
// solution-x, ms, defeat %
// ✓
class Solution {
public:
    int numberOfMatches(int n) {
        while (n >= 2) {
            num(n);
        }
        return cnt_;
    }
private:
    int cnt_ = 0;
    void num(int& n) {
        if (n % 2 == 0) {
            cnt_ += ( n / 2 );
            n /= 2;
        } else  {
            cnt_ += (n / 2);
            n = (n / 2) + 1;
        }
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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

