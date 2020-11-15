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
/* Type:  */
/* 题目信息 */
/*
 *287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 */

/* my solution */
// solution-1, 32ms, defeat 11.16%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums)
        {
            if (++mp[i] > 1)
                return i;
        }
        
        return -1;
    }
};

/* better solution */
// solution-2, 20ms, defeat 42.77%
// sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                res = nums[i];
                break;
            }
        }
        
        return res;
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 还可以使用binary search和two pointers做，还没有尝试
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

