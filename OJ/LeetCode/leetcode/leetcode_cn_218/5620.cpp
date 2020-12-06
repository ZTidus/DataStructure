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
class Solution {
public:
    int concatenatedBinary(int n) {
        if (n == 1) 
        for (int i = 1; i < )

    }
private:
    string trans(int val, int base)
    {
        int x[64], i = 0;
        while (val)
        {
            x[i] = val % base;
            val /= base;
            i++;
        }

        string str = "";
        // 从后往前输出
        for (int k = i - 1; k >= 0; k--)
            str += x[k];
        return str;
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
    int n = 3;
    int res = solution.concatenatedBinary(n);
    cout << res;

    return 0;
}

