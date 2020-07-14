#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
//none
/* better solution */
class Solution {
    public:
        vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            vector<int> res;
            unordered_set<int> s; // [ 1 ]

            // find out the min of every row
            for (int i = 0; i < matrix.size(); i++) {
                int mn = INT_MAX;  // [ 2 ]
                for (int j = 0; j < matrix[0].size(); j++)
                    mn = min(mn, matrix[i][j]);
                s.insert(mn);
            }

            // find out the max of every column
            for (int j = 0; j < matrix[0].size(); j++) {
                int mx = INT_MIN;
                for (int i = 0; i < matrix.size(); i++)
                    mx = max(mx, matrix[i][j]);
                // if find out the mx is already in the unordered_set, the push
                // it into the res vector.
                if (s.find(mx) != s.end()) // [ 3 ]
                    res.push_back(mx);
            }
            return res;
        }
}

/* 一些总结 */

// [1]: c++ unordered_set定义
// [2]: C中常量INT_MAX和INT_MIN分别表示最大、最小整数，定义在头文件limits.h中. INT_MAX = 2^31-1，INT_MIN= -2^31
// [3]: unordered_set::find()函数是C++ STL中的内置函数，用于在容器中搜索元素。它返回元素的迭代器，如果找到其他元素，则返回指向unordered_set::end()的迭代器。
// 用法： unordered_set_name.find(key)
// if(s.find(xx) != s.end()) xxx
