#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
假设给出的数组中只存在唯一解
例如：
给出的数组为 {20, 70, 110, 150},目标值为90
输出 index1=1, index2=2


示例1
输入
[3,2,4],6
返回值
[2,3]
 */

/* my solution */
// solution-1, 4ms
// hash

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int, int> mp;  // value: index
        for (int i = 0; i < numbers.size(); i++)
            mp[numbers[i]] = i + 1;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
        {
            int remaining = target - numbers[i];
            //res.erase(res.begin(), res.end());
            res.clear();
            res.push_back(i+1);
            if (mp.count(remaining) && (i+1) != mp[remaining])
            {
                res.push_back(mp[remaining]);
                break;
            }

        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意索引是从1开始的
// 2. 
// 3. 

