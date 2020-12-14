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
 *861. Score After Flipping Matrix
 */

/* my solution */
// solution-x, ms, defeat %
// 我自己考虑的太简单了.
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            string temp = "";
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] == 0)
                    temp += "1";
                else 
                    temp += "0";
            }
            res += bin_to_dec(temp);
        }
        return res;
    }
private:
    int bin_to_dec(string str) {
        int nums = 0;
        int len = str.size();
        for (int i = 0; i < len; i++) {
            int x = (int)(str[i] - '0');
            nums += x * pow(2, len - 1 - i);
        }
        return nums;
    }
    
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一二维数组,任意移动:1→0, 0→1, 这样,之后返回最大的值
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
    vector<vector<int>> input = { { 0,0,1,1 },{ 1,0,1,0 },{ 1,1,0,0 } };
    int res = solution.matrixScore(input);
    cout << res;

    return 0;
}

