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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res;
        map<int, int> mp;
        for (int i : coins)
            mp[i]++;
        
        int remaining;
        if (coins.back() <= amount) {
            remaining = amount % coins.back();
            res += amount / coins.back();
        }
        if (mp.count(remaining))
            res += 1;
        
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = solution.coinChange(coins, amount);
    cout << res;

    return 0;
}

