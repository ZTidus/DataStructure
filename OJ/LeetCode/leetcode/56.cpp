#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
 */

/* my solution */

/* better solution */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        // 1. sort
        sort(intervals.begin(), intervals.end(), cmp);
        // 2. check if has interlap
        vector<vector<int>> res;
        for (auto interval : intervals)
        {
            // 1. res is empty
            // res has no interlap with cur vector
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1] , interval[1]);
        }
        
        return res;
    }
private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
};

/* 一些总结 */
// 1. 题意: 给定一组二维数组，将这些有交叉的区间进行合并。
// 2. 解决: 对整个二维数组根据第一个元素值大小进行排序，之后进行合并
// 需要注意的点: 
// 1. 注意sort的高级用法， 那个cmp的写法
// 2. 
// 3. 

