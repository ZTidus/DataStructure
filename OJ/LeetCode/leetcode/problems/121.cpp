#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

/* my solution */
// solution-1, ms, defeat %
// time limited 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                res = max(res, (prices[j] - prices[i]));
            }
        }
        return res;
    }
};

/* better solution */
// solution-2, 12ms, defeat 62.42%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if (prices.empty()) return res;
        
        int min_val = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                // 找出最大利润
                profit = max(profit, prices[i] - min_val);
            else
                // 找出最小值
                min_val = min(min_val, prices[i]);
        }
        
        return profit;
    }
};

/* 一些总结 */
// 1. 题意: 买股票，低价购入，高价卖出，找出最大利润。
//
// 需要注意的点: 
// 1. 还有一种动态规划的做法，但是现在并不懂
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

