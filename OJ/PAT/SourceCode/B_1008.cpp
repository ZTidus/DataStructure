#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* pat b */
/* Type:  */
/* 题目信息 */
/*
 *1008 数组元素循环右移问题 (20分)
 */

/* my solution */

int main(int argc, char *argv[])
{
    // input
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> nums(n);
    //int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    // compute
    m %= n; // 如果m大大于n,那么循环右移m位相当于循环右移m%n位,因为那些n倍数位的移动是多余的,所以在使用用m之前,先将m = m%n
    if (m != 0)
    {
        reverse(begin(nums), begin(nums) + n); // 1. reverse the whole nums
        reverse(begin(nums), begin(nums) + m); // 2. reverse the [0, m)
        reverse(begin(nums) + m, end(nums));   // 3. reverse the [m, end];
    }

    // output
    for (int i = 0; i < n - 1; i++)
        cout << nums[i] << " "; 
    cout << nums[n - 1];

    return 0;
}

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 为什么必须用vector，不能用普通数组?
// 2. 
// 3. 

