#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1380. Lucky Numbers in a Matrix
 * Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]


Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
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
                s.insert(mn);  // [4]
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
// [4]: unordered_set::insert(element)
