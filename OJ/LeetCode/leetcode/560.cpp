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
#include <unordered_map>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, time limited!
// brute force
// 遍历得到每一种结果,但是这种start, end的写法当时并不会写.
// O(n^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                int sum = 0;
                for (int i = start; i < end; i++) 
                    sum += nums[i];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// solution-2 累计和 prefix sum
// 后一个减去前一个就是中间元素的和.
// O(n^2)
// time limited, java版本的可以通过,但是cpp版本不行.
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
        
    }
};

// solution-3: hash table prefix sum
// ✓
// 唯一通过的方法
class Solution3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, 1}};
        int count = 0, sum = 0;
        
        for (int& i : nums) {
            sum += i;
            count += mp[sum - k]; // 这一句让我很困惑.
                                  // 查看mp中是否有sum-k的存在, 这个是为什么?
                                  // 有些绕
            //cout << mp[sum-k] << endl;
            mp[sum]++;
        }
        return count;
        
    }
};
/* 一些总结 */
// 1. 题意: 给定一数组,给定一k值,查看数组中有多少连续子数组的和等于k.
//
// 需要注意的点: 
// 1. prefix sum
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution3 solution3;
    vector<int> input = {1, 1, 1};
    int k = 2;
    int res = solution3.subarraySum(input, k);
    cout << res;

    return 0;
}

