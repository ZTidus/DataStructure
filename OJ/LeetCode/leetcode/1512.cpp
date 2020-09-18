#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1512. Number of Good Pairs
Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 */

/* my solution */
// 1. 枚举，看有多少对数字相同，然后返回。
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    cnt++;
        }
        
        return cnt;
    }
};

// 2. 计算出每个数字的数组，则每个数字可以组成(n * (n - 1)) / 2对
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> freq;
        int cnt = 0;
        // find out every number's frequency
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        for (auto e: freq)
        {
            if (e.second != 1)  // exclude the frequency == 1's number
                cnt += (e.second * (e.second - 1)) / 2;
        }
        
        return cnt;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
// 2. 解决: 计算每个数字的频数，然后使用n(n-1) / 2
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

