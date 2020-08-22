#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1207. Unique Number of Occurrences
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
 */

/* my solution */


/* better solution */
// map, set ✓
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        set<int> s;
        // find out each number's occurrence number
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            s.insert(it->second);
        }
        
        return mp.size() == s.size();
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

