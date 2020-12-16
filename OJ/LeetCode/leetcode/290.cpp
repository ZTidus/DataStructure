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
 *290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                vec.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        vec.push_back(temp);
        
        // ok
        //cout << vec.size() << endl;
        
        if (pattern.size() != vec.size())
            return false;
            
        map<char, string> mp;
        bool flag1 = true;
        bool flag2 = true;
        int cnt = 0;
        for (char c : pattern) {
            if (!mp.count(c)) {
                mp[c] = vec[cnt++];
            } else {
                if (mp[c] != vec[cnt++]) 
                    flag1 = false;
            }
        }
       
        int cnt2 = 0;
        map<string, char> mp2;
        for (string str : vec) {
            if (!mp2.count(str))
                mp2[str] = pattern[cnt2];
            else {
                if (mp2[str] != pattern[cnt2])
                    flag2 = false;
            }
            cnt2++;
        }
        
        cout << flag1 << " :" << flag2 << endl;
        return flag1 && flag2;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 根据模式匹配字符串
//
// 需要注意的点: 
// 1. 不仅值是唯一,键也是唯一的,所以这里我使用了两个map
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string pattern = "abba"; 
    string s = "dog cat cat dog";
    Solution solution;
    bool res = solution.wordPattern(pattern, s);
    cout << res;

    return 0;
}

