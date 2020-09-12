#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointer */
/* 题目信息 */
/*
 *11. Container With Most Water
 */

/* my solution */
// brute force  - 超时 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int hi = min(height[i], height[j]);
                int width = j - i;
                res = max(res, hi * width);
            }
        }
        
        return res;
    }
};

/* better solution */
// two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int last = height.size() - 1;
        int res = 0;
        
        while (first < last)
        {
            if (height[first] >= height[last]) // 使用两者中较矮的作为高
            {
                res = max(res, (last - first) * height[last]);
                last--;
            }
            else
            {
                res = max(res, (last - first) * height[first]);
                first++;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
// 解法：使用two pointers, 初始时一个指向开始，一个指向最后位置，如果初始位置高度大于第二个指针所指高度，则第一个指针向后移动一个位置，算出结果；如果后一个指针高度小于第一个指针高度，则后一个指针向前移动一个位置。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

