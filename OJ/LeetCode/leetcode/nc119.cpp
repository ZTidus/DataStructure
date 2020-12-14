#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
示例1
输入 [4,5,1,6,2,7,3,8],4
返回值 [1,2,3,4]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1
// 直接排序选取前k
// 注意边界条件，一个边界条件可能用例就通不过超80%
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        sort(input.begin(), input.end());
        if (k > input.size()) // 注意这一句
            return {};
        for (int i = 0; i < k; i++)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};

// solution-2, 3ms
// 优先队列

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size())
            return res;
        priority_queue<int, vector<int> > pq;
        for (int val : input)
        {
            if (pq.size() < k)
            {
                pq.push(val);
            }
            else
            {
                if (val < pq.top())
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        
        while (!pq.empty())
        {
            res.push_back(pq.top());
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

