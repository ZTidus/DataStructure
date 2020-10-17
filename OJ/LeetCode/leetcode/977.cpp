#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 977. Squares of a Sorted Array
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
 */

/* my solution */
// 132ms - O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // 1. 先整体平方
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
        // 2. 排序
        sort(A.begin(), A.end());
        return A;
    }
};

/* better solution */
// 48ms - O(n)
// 双指针
// 一个指针在数组最坐，一个在最右，当左指针所指元素值的平方大于右指针所指元素值的平方，将左指针元素值平方放入新开的大小为n的数组的最后一个位置，反之亦然。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;)
        {
            if (A[i] * A[i] > A[j] * A[j])
            {
                res[pos] = A[i] * A[i];
                i++;
            }
            else
            {
                res[pos] = A[j] * A[j];
                j--;
            }
            pos--;
        }
        return res;

    }
};
// 讨论区有更好的解，但是我没有看懂
/* 一些总结 */

