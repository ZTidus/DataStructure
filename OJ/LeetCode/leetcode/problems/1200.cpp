#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Array */
/* 题目信息 */
/*
 *1200. Minimum Absolute Difference
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
 */

/* my solution */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        // 1. find out the minium
        int min_diff = INT_MAX;
        // sort arr
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            min_diff = min(min_diff, arr[i] - arr[i-1]);
        }
        printf("%d\n", min_diff);
        
        // 2. compare and find out results
        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> temp;
            if (arr[i] - arr[i-1] == min_diff)
            {
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }
        
        return res;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//    1. 找到最小的比较值
//    2. sort arr，然后一一对比后一个值与前一个值的差值是否与最小比较值相同，然后推入.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

