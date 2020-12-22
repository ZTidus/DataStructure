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
/* Type: array */

/* 题目信息 */
/*
 *1572. Matrix Diagonal Sum
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5
 

Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
 */

/* my solution */
// solution-1, 20ms, defeat 99.25%
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int len = mat[0].size();
        for (int i = 0; i < len; i++) {
            res += mat[i][i];
            res += mat[i][len - i - 1];
        }
        if (len % 2 == 1)
            res -= mat[len/2][len/2];
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 计算矩阵对角线和斜对角线上元素的和.
//
// 需要注意的点: 
// 1. 很容易的一道题目.
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

