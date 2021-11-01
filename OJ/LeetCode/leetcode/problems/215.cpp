#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

/* my solution */
// solution-1, 12ms, defeat 97.02%
// 先排序，在倒序，然后输出num[k-1]
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

/* better solution */
// solution-2, 20ms, defeat %
// min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq; // min heap
        for (int i : nums)
        {
            if (pq.size() < k)
                pq.push(i);
            else 
            {
                if (i > pq.top())
                {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        
        return pq.top();
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. min heap,
// 当size为k时，再插入元素时，比较top元素和当前元素大小，如果当前元素较大，则pop掉top元素，当前元素进堆，这样min heap里的元素就是整个序列的前k大元素，而top元素又是这前k大元素中最小的，此时返回top元素即可。
// 2. 
// 3. 

