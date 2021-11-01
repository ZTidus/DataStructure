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
/* Type: heap */
/* 题目信息 */
/*
 *378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
 */

/* my solution */
// solution-1, 88ms, defeat 60.61%
// 没有使用heap，新建一个数组存入matrix中所有的元素，然后排序，返回第k项
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                nums.push_back(matrix[i][j]);
        }
        
        sort(nums.begin(), nums.end());
        return nums[k-1];
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

