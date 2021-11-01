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
#include <unordered_map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
Example 4:

Input: chars = ["a","a","a","b","b","a","a"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","3","b","2","a","2"].
Explanation: The groups are "aaa", "bb", and "aa". This compresses to "a3b2a2". Note that each group is independent even if two groups have the same character.
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lower-case English letter, upper-case English letter, digit, or symbol.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int compress(vector<char>& chars) {
        unordered_map<string, int> mp;
        for (char c : chars)
            mp[to_string(c)]++;
        
        vector<string> res;
        for (auto entry : mp) {
            res.push_back(entry.first);
            string num = to_string(entry.second);
            int num_len = num.size();
            if (num_len == 1 && (num[0] - '0') == 1)
                continue;
            else if (num_len > 2) {
                for (char c : num)
                    res.push_back(to_string(c));
            }
        }
        return res.size();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 这个题目有问题,传输的参数是vector<char> ,但是样例中是vector<string>类型的.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    vector<char>  chars = { "a","a","b","b","c","c","c" };
    Solution solution;
    int res = solution.compress(chars);
    cout << res;

    return 0;
}

