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
/* Type: array */
/* 题目信息 */
/*
 *1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        
        vector<pair<int, int>> vec;
        for (auto e : mp) {
            vec.push_back({e.first, e.second});
        }
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> res;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].second; j++) {
                res.push_back(vec[i].first);
            }
        }
        return res;
        
    }
private:
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 多值排序问题
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

