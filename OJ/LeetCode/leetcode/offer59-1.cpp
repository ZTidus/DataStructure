#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: 滑动窗口 */
/* 题目信息 */
/*
 *剑指 Offer 59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 */

/* my solution */
// solution-1, 252ms, defeat 12.25%
// brute force
// 1. 使用循环遍历
// O(nk)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i <= len - k; i++)
        {
            int maxVal = INT_MIN;
            for (int j = i; j < i + k; j++)
            {
                if (nums[j] > maxVal)
                    maxVal = nums[j];
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

/* better solution */
// solution-2, 32ms, defeat 97.11%
// monotonic queue(单调队列), 
// deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return res;
        // monotonic queue
        deque<int> q; // only indexes are stored
        for (int i = 0; i < n; i++)
        {
            // 1. 超过范围
            while (!q.empty() && (i - q.front()) >= k)
                q.pop_front();
            // 2. 当前元素值大于队列最后一个值
            while (!q.empty() && nums[i] > nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
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

