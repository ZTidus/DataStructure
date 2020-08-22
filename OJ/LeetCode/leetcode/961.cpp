#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *961. N-Repeated Element in Size 2N Array
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
 */

/* my solution */
// 176ms
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N = A.size() / 2;
        map<int, int> mp;
        // find out each number's occurrence number
        for (int i = 0; i < 2 * N; i++)
        {
            mp[A[i]]++;
        }
        
        for (auto e: mp)
        {
            if (e.second == N)
                return e.first;
        }
        
        return 0;
    }
};
// 对整个数组进行遍历，将每个数字出现的次数载入到map中，再对比其中出现次数为N的，返回这个数字。
/* better solution */
// 76ms
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N = A.size() / 2;
        map<int, int> mp;
        int res;
        // find out each number's occurrence number
        for (int i = 0; i < 2 * N; i++)
        {
            mp[A[i]]++;
            if (mp[A[i]] > 1)
            {
                res = A[i];
                break;
            }
        }
        
        return res;
    }
};
// 因为题目中说一共2N个数字，共N+1个不同的数字，其中一个数字出现了N次，所以可以确定另外N个数字每个只出现了1次，就可以在遍历中缩小步骤。
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

