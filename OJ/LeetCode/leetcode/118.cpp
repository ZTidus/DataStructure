#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        
        for (int i = 1; i < numRows; i++)
        {
            vector<int> cur;
            vector<int> prevRow = res[i - 1];
            
            // 每行中第一个元素
            cur.push_back(1);
            
            // 算出中间所有元素
            for (int j = 1; j < i; j++)
            {
                cur.push_back(prevRow[j - 1] + prevRow[j]);
            }
            
            // 每行中最后一个元素
            cur.push_back(1);
            
            res.push_back(cur);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 杨辉三角
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
    vector<vector<int> > res;
    res = solution.generate(5);

    return 0;
}

