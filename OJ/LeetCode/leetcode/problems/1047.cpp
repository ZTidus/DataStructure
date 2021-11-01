#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1047. Remove All Adjacent Duplicates In String
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
 */

/* my solution */
class Solution {
public:
    string removeDuplicates(string S) {
        if (!S.empty()) return "";
        stack<string> s;  // !!!这里应该是char型
        s.push(S[0]);
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == s.top())
            {
                s.pop();
            }
            else
                s.push(S[i]);
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            printf("%c", s.top());
            s.pop();
        }
        
        return s;
    }
};

/* better solution */
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        stack<char> st;
        for (auto cur: S)
        {
            //if (st.empty())
            //    st.push(cur);
            //else if (st.top() == cur)
            if (!st.empty() && st.top() == cur)
                st.pop();
            else st.push(cur);
        }
        
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
            
        return res;
    }
};

/* 一些总结 */
// 1. S为string类型，可以for(auto e: S)
// 2. reverse(S.begin(), S.end())

