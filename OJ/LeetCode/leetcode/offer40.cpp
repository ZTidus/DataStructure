#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: heap */
/* 题目信息 */
/*
 *剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 */

/* my solution */
// solution-1, 88ms, defeat 59.75%
// 整体排序后选取前k个值。
// O(nlogn)即排序的时间复杂度
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 1. sort
        sort(arr.begin(), arr.end());
        // 2. k
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};

/* better solution */
// solution-2, 120ms, defeat 31.11%
// max heap
// O(nlogk): n个输入数字，树高为logk, 插入数据到树中为logk
// 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        priority_queue<int> pq;
        // 先导入k个值
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        // 比较当前值和堆顶元素大小
        for (int i = k; i < arr.size(); i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++)
        {
            res[i] = pq.top();
            pq.pop();
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

