#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: two pointers */
/* 题目信息 */
/*剑指 Offer 57 - II. 和为s的连续正数序列
 *输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
// 超时
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {{}};
        int l = 1, r = 2;
        int mid = (1 + target) / 2;
        int curSum = l + r;
        vector<int> temp;
        vector<vector<int>> res;
        while (l < r)
        {
            if (curSum == target)
            {
                for (int i = l; i <= r; i++)
                    temp.emplace_back(i);
                res.emplace_back(temp);
                
                while (curSum > target && l < mid)
                {
                    curSum -= l;
                    l++;
                    if (curSum == target)
                    {
                        for (int i = l; i <= r; i++)
                            temp.emplace_back(i);
                        res.emplace_back(temp);
                    }
                }
                r++;
                curSum += r;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 2连续序列. 题意: 求一个数的连续求和序列
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

