#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  hash table*/
/* 题目信息 */
/*
 *
 */

/* my solution */
// 下边这总暴力的方法会超时
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                printf("inner\n");
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    //break;
                    return res;
                }
            }
        }
        
        return res;
    }
};

/* better solution */
// reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            ump[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (ump.count(complement) && ump[complement] != i) // important
            {
                res.push_back(i);
                res.push_back(ump[complement]);
                return res;
            }
        }
        
        return res;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 以空间换时间
// 2. 使查找时间O(n)降到O(1)
// 3. 

