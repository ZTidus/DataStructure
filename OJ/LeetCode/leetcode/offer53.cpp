#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: binary search */
/* 题目信息 */
/*
 *剑指 Offer 53 - I. 在排序数组中查找数字 I
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000
 */

/* my solution */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = binarySearch(nums, target);
        cout << "idx: " << idx << endl;
        if (idx == -1)
            return 0;
        int res = 1;
        for (int i = idx + 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
                res++;
        }
        return res;

    }
private:
    int binarySearch(vector<int> nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                while (nums[res - 1] == target)
                    res--;
            }
            if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return res;
    }
    
};

// solution-2 32ms defeat 10.79%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        if (mp.count(target))
            return mp[target];

        return 0;

    }
};
/* better solution */
// solution-3 20ms defeat 64.76%
// 1. 找到target第一次出现的下标
// 2. 找到target最后一次出现的下标
// 3. 返回last - first + 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int first = getFirstT(nums, len, 0, len - 1, target);
        //cout << num << endl;
        int last = getLastT(nums, len, 0, len - 1, target);
        
        cout << "first: " << first << endl;
        cout << "last: " << last << endl;
        int res = 0;
        if (first > -1 && last > -1)
            res = last - first + 1;

        return res;
    }
private:    
    int getFirstT(vector<int> nums, int len, int low, int high, int target)
    {
        if (low > high)
            return -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            //int mid = (low + high) / 2;
            int mid_data = nums[mid];
            if (mid_data == target)
            {
                if (mid > 0 && nums[mid - 1] != target || mid == 0) // 注意这个条件
                    return mid;
                else
                    high = mid - 1;
            }
            else if (mid_data > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1; 
    }
    int getLastT(vector<int> nums, int len, int low, int high, int target)
    {
        if (low > high)
            return -1;
        //int mid_index = low + (high)
        while (low <= high)
        {
            int mid_index = low + (high - low) / 2;
            int mid_data = nums[mid_index];
            if (mid_data == target)
            {
                if (mid_index < len - 1 && nums[mid_index + 1] != target || mid_index == len - 1) // 注意这个条件
                    return mid_index;
                else
                    low = mid_index + 1;
            }
            else if (mid_data > target)
                high = mid_index - 1;
            else
                low = mid_index + 1;
        }
            

        
        return -1;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

