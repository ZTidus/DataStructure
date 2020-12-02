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
 *1165. 单行键盘
我们定制了一款特殊的力扣键盘，所有的键都排列在一行上。

我们可以按从左到右的顺序，用一个长度为 26 的字符串 keyboard （索引从 0 开始，到 25 结束）来表示该键盘的键位布局。

现在需要测试这个键盘是否能够有效工作，那么我们就需要个机械手来测试这个键盘。

最初的时候，机械手位于左边起第一个键（也就是索引为 0 的键）的上方。当机械手移动到某一字符所在的键位时，就会在终端上输出该字符。

机械手从索引 i 移动到索引 j 所需要的时间是 |i - j|。

当前测试需要你使用机械手输出指定的单词 word，请你编写一个函数来计算机械手输出该单词所需的时间。

 

示例 1：

输入：keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
输出：4
解释：
机械手从 0 号键移动到 2 号键来输出 'c'，又移动到 1 号键来输出 'b'，接着移动到 0 号键来输出 'a'。
总用时 = 2 + 1 + 1 = 4. 
示例 2：

输入：keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
输出：73
 

提示：

keyboard.length == 26
keyboard 按某种特定顺序排列，并包含每个小写英文字母一次。
1 <= word.length <= 10^4
word[i] 是一个小写英文字母
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0;
        map<char, int> mp;
        int cnt = 0;
        for (char c : keyboard) {
            mp[c] = cnt++;
        }
        
        // 因为使用foreach语法不好处理第一个字符，所以还是使用了索引方法。
        res += (mp[word[0]] - 0);
        
        for (int i = 1; i < word.size(); i++) {
            int prev = mp[word[i-1]];
            int cur = mp[word[i]];
            res += abs(cur - prev);
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
// 需要考虑一些逻辑条件
// 需要注意的点: 
// 1. 当foreach不适用时考虑一下索引吧
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

