#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *1046. Last Stone Weight
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
Note:
1 <= stones.length <= 30
1 <= stones[i] <= 1000
 */

/* my solution */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int len = stones.size();
        if (len == 1) return stones[0];
        if (len == 2) return stones[1] - stones[0];
        while (len > 2)
        {
            int first = stones.back(); stones.pop_back(); len--;
            int second = stones.back(); stones.pop_back(); len--;
            stones.push_back(first - second); len++;
            sort(stones.begin(), stones.end());
        }
        if (len == 1) return stones[0];
        if (len == 2) return stones[1] - stones[0];
        return 0;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意:
// 给定一个数组，每次选取其中最大值和次大值相减，如果两个数字一样，则在数组中消除这两个数字，如果不一样，则得到结果（为正）后添加进入数组中，进行一下选择最大和次大，最后如果数组中剩下一个数字，返回这个数字，如果没有数字剩下，则返回0.
// 2. 解决：
//   1. 排序
//   2. 循环找取最大和次大
//   3. 判断最后的数组。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

