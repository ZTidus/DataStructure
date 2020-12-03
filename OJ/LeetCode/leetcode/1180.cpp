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
/* Type: string */

/* 题目信息 */
/*
 *1180. 统计只含单一字母的子串
 *给你一个字符串 S，返回只含 单一字母 的子串个数。

示例 1：

输入： "aaaba"
输出： 8
解释： 
只含单一字母的子串分别是 "aaa"， "aa"， "a"， "b"。
"aaa" 出现 1 次。
"aa" 出现 2 次。
"a" 出现 4 次。
"b" 出现 1 次。
所以答案是 1 + 2 + 4 + 1 = 8。
示例 2:

输入： "aaaaaaaaaa"
输出： 55
 

提示：

1 <= S.length <= 1000
S[i] 仅由小写英文字母组成。

 */

/* my solution */
// solution-x, ms, defeat %

/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int countLetters(string S) {
        int res = 0;
        int cnt = 1;
        int len = S.size();
        for (int i = 1; i < len; i++) {
            if (S[i] == S[i - 1])
                cnt++;
            else {
                res += (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
        }
        res += (cnt * (cnt + 1)) / 2; // 这一句的作用是什么?
                                    // 因为最后一个字母还没有算进去，所以就需要算一个最后的。
        
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

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input = "aaaba";
    int res = solution.countLetters(input);
    cout << res;

    return 0;
}

