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
 *1119. 删去字符串中的元音
给你一个字符串 S，请你删去其中的所有元音字母（ 'a'，'e'，'i'，'o'，'u'），并返回这个新字符串。

 

示例 1：

输入："leetcodeisacommunityforcoders"
输出："ltcdscmmntyfrcdrs"
示例 2：

输入："aeiou"
输出：""
 

提示：

S 仅由小写英文字母组成。
1 <= S.length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-vowels-from-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string removeVowels(string S) {
        string res = "";
        for (char c : S) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                continue;
            } else {
                res += c;
            }
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 删除字符
// 很简单的一道题目。
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

    return 0;
}

