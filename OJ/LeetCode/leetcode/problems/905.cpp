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
/* Type: two pointers */
/* 题目信息 */
/*
 *905. Sort Array By Parity
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */

/* my solution */
// solution-1, 52ms, defeat 5.89%
// so slow.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for (int e : A) {
            if (e % 2 == 1)
                res.push_back(e);
            else
                res.insert(res.begin(), 1, e);
        }
        return res;
    }
};

/* better solution */
// solution-2, 20ms, defeat 34.95%
// in-place; two pointers.
class Solution2 {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        
        while (left < right) {
            if (A[left] % 2 != 0) {
                if (A[right] % 2 == 0) // 加上这个判断条件后, 16ms, 69.73%, 避免不必要的交换
                    swap(A[left], A[right]);
                right--;
            } else {
                left++;
            }
        }
        
        return A;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组,将数组中的偶数放在数组左端,将奇数放在数组右端.
//
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

