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
    int minElements(vector<int>& nums, int limit, int goal) {
        long long a = goal;
        for (int i : nums) {
            a -= i;
        }
        //cout << "goal: " << goal << endl;
        int abs_goal = abs(a);

        //if (limit >= abs_goal) // 将这两句注释掉了就通过了?!
         //   return 1;

        if (abs_goal % limit == 0)
            return abs_goal / limit;
        return abs_goal / limit + 1;
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
    vector<int> nums = {1, -1, 1};
    int limit = 3;
    int goal = -4;
    int res = solution.minElements(nums, limit, goal);
    
    cout << "res: " << res << endl;

    return 0;
}

