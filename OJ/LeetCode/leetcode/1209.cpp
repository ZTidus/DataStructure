#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1209. Remove All Adjacent Duplicates in String II
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
 */

/* my solution */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) return "";
        stack<char> stk;
        unordered_map<char, int> ump;
        
        for (auto e : s)
        {
            if (stk.empty())
                stk.push(e);
            else if (stk.top() == e && k-1 == ump[e])
                stk.pop();
            else if (stk.top() == e)
                ump[e]++;
            else
                stk.push(e);
        }
        
        string res = "";
        for (auto e : ump)
        {
            for (int i = 0; i < e.second; i++)
                res += to_string(e.first);
        }
        
        return res;
    }
};
// 上边这种做法为什么是错的?
/* better solution */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> vec;
        
        for (char& c: s)
        {
            if (vec.empty())
                vec.push_back(make_pair(c, 1));
            else if (c == vec.back().first && vec.back().second == k-1) // 注意这里是k-1, not k!!!
                vec.pop_back();
            else if (c == vec.back().first)
                vec.back().second++;
            else 
                vec.push_back(make_pair(c, 1));
        }
        
        string res;
        for (auto &p: vec)
        {
            for (int i = 0; i < p.second; i++)
                res += p.first;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. make_pair()
// 2. 这一道题是关于栈的题目，但是使用了vector，将vector改成了stack，出了错，stack里不能使用pair吗?
// 这道题再一次做时出了很多问题: 
// 1. 为什么使用vector而不是stack
// 2. k 与 k-1
// 3. 复合元素类型的构造

