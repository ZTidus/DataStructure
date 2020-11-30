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
 *1528. Shuffle String
Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
Example 3:

Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"
Example 4:

Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"
Example 5:

Input: s = "art", indices = [1,0,2]
Output: "rat"
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).
 */

/* my solution */
// solution-1, 8ms, defeat 93.22%
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = indices.size();
        vector<char> store_chars(len);
        //string res(len);
        
        for (int i = 0; i < len; i++) {
            int index = indices[i];
            store_chars[index] = s[i];
        }
        
        string res;
        for (char c : store_chars)
            res += c;
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串和一个索引数组，返回字符串根据索引的正确字符串。
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

    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    string res = solution.restoreString(s, indices);
    cout << res;
    

    return 0;
}

