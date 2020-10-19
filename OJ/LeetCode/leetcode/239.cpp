#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: sliding window */
/* 题目信息 */
/*
 *239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 348ms, defeat 47.19%
// monotonic queue(单调队列)
// 1. 队列里存放的是索引吗? 确实是，存放的是数组下标。为什么要这样，为什么不直接存值?
// 2. 总是维护最大值在deque的最左端
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        vector<int> res;
        deque<int> q; // only indexes are stored
        for (int i = 0; i < nums.size(); i++)
        {
            // 当当前元素下标与deque头部下标之差>=k时，清除头部
            // 因为是滑动窗口！能够遮盖的元素是一定的。
            while (!q.empty() && (i - q.front()) >= k)
                q.pop_front();
            // 若当前q不空且当前元素大于q尾部元素，循环清除尾部元素
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            // 当滑动窗口刚满时，将首部元素推入结果中
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

