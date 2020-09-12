#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointers */
/* 题目信息 */
/*
 *15. 3Sum
 */

/* my solution */


/* better solution */
// Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        // sort
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++)
        {
            // because nums is sorted, so if nums[0] > 0, the elements in the array are all positive, sum won't be 0.
            const int element = nums[i];
            if (element > 0) break;
            int L = i + 1, R = n - 1;
            while (L < R)
            {
                const int sum = element + nums[L] + nums[R];
                if (sum == 0)
                {
                    vector<int> temp{element, nums[L], nums[R]};
                    res.push_back(temp);
                    //res.push_back({});
                    while (L < R && nums[L] == nums[L+1])
                        L++;
                    while (L < R && nums[R] == nums[R-1])
                        R--;
                }
                else if (sum < 0)
                {
                    while (L < R && nums[L] == nums[L+1])
                        L++;
                }
                else
                {
                    while (L < R && nums[R] == nums[R-1])
                        R--;
                }
            }
            while (nums[i] == nums[i+1])
                i++;
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

