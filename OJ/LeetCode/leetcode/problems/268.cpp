#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *268. Missing Number

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 */

/* my solution */
// solution-1, 56ms, defeat 20.02%
// sort
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt++ != nums[i])
                return nums[i] - 1;
        }
        return nums.size();
    }
};

// solution-2
// set
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s;
        for (int i : nums)
        {
            s.insert(i);
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.count(i))
                return i;
        }
        return nums.size();
        
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找出给定数组中缺失的那个数字
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

