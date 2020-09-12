#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointers */
/* 题目信息 */
/*
 *42. Trapping Rain Water
 */

/* my solution */


/* better solution */
// two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n == 0) return 0;
        int l = 0;
        int r = n - 1;
        // max_l与max_r是两块板子在挡水
        int max_l = height[l];
        int max_r = height[r];
        int res = 0;
        
        while (l < r)
        {
            if (max_l < max_r)
            {
                res += max_l - height[l];
                max_l = max(max_l, height[++l]);
            }
            else
            {
                res += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

