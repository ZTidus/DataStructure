#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0
Accepted
519,212
Submissions
1,491,833
 */

/* my solution */


/* better solution */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> newNums(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            newNums[(i + k) % nums.size()] = nums[i];
        }
        
        // copy to the original vector
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = newNums[i];
        }
    }
};

/* 一些总结 */
// 1. 题意: 
// 旋转k次数组，每次动一个元素。
// 需要注意的点: 
// 1. 使用新的元素存储旋转后的元素，再将元素复制回原数组。
// 2. 
// 3. 

