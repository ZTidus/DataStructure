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
/* Type: hash table */
/* 题目信息 */
/*
 *347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
 */

/* my solution */
// solution-1, 36ms, defeat 39.93%
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        // record each number's freq
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        
        vector<pair<int, int> > vec;
        for (auto e : mp)
        {
            vec.push_back({e.first, e.second});
        }
        
        sort(vec.begin(), vec.end(), compare);
        
        for (int i = 0; i < k; i++)
            res.push_back(vec[i].first);
        
        return res;
        
    }
private:
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一数字，找到前k个频次最高的数字。
// 先使用map得到每个数字的频次，然后根据频次排序，最后输出前k个即可。
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

