#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *771. Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
 */

/* my solution */


/* better solution */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        int cnt = 0;
        for (char c: S)
        {
            m[c]++;
        }
        for (char c: J)
        {
            if (m.count(c))
                cnt += m[c];
        }
        
        return cnt;
    }
};

/* 一些总结 */
// 1. 题意: 
// 字符串J和S，看J中字符串中字符在S中出现了几次。
// 解: 使用map，
// 先遍历字符串S，将字符对应次数记录下来，再遍历字符串J，看有哪些字符出现。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

