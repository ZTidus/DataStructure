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
 *448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

/* my solution */
// solution-1, 312ms, defeat 5.63%
// 使用set存入nums元素
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        set<int> s;
        for (int i : nums)
            s.insert(i);
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.count(i + 1))
                res.push_back(i + 1);
        }
        
        return res;
    }
};

/* better solution */
// solution-2, 96ms, defeat 73.61%
// 因为有重复的
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> results;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        
        // A positive element means that the element (index + 1) does not appear in the array, so save it
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                results.push_back(i + 1);
        
        return results;
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中缺失的元素
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

