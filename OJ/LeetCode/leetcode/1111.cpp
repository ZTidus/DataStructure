#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1111. Maximum Nesting Depth of Two Valid Parentheses Strings

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        int depth = 0;
        for (int i = 0; i < n; i++)
        {
            if (seq[i] == '(')
            {
                depth++;
                res[i] = depth % 2;
            }
            else
            {
                res[i] = depth % 2;
                depth--;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 没有看懂题目
// 2. 
// 3. 

