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
 *1324. Print Words Vertically

Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"
Example 2:

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"
Example 3:

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    vector<string> printVertically(string s) {
        int words_nums = 0;
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
                continue;
            }
            word += s[i];
        }

        words.push_back(word);
        
        int max_val = 0;
        for (string str : words) {
            max_val = max_val < str.size() ? str.size() : max_val;
        }
        
        vector<string> res(max_val);
        int cnt = 0;
        while (cnt < max_val) {
            for (int i = 0; i < words.size(); i++) {
                if (cnt < words[i].size())
                    res[cnt] += words[i][cnt];
                else
                    res[cnt] += ' ';
            }
            cnt++;
            
        }
        for (string& str : res) {
            erase_space(str);
        }

        return res;
        
    }
private:
    void erase_space(string& temp) {
        int pos = temp.size() - 1;
        for (int i = pos; i >= 0; i--) {
            if (temp[i] != ' ') {
                break;
            }
            pos--;
        }
        temp.erase(pos + 1, temp.size());
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 这道题自己做时极度麻烦,很绕.
// 2. 每一个单词都要检查末尾空格.
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string s = "HOW ARE YOU";
    vector<string> res = solution.printVertically(s);
    cout << res.size();
    

    return 0;
}

