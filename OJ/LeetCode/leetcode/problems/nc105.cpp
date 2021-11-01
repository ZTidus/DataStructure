#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* NowCoder */
/* Type:  binary search*/
/* 题目信息 */
/*
 *题目描述
 请实现有重复数字的有序数组的二分查找。
 输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
 示例1
 输入
 5,4,[1,2,4,4,5]
 输出
 3
 */

/* my solution */


/* better solution */
class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (v <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low == n)
            return n + 1;
        return low + 1; // 这里返回的为什么是low + 1, 为什么要加一。
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

