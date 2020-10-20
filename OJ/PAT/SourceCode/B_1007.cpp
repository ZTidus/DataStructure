#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Pat */
/* Type: math */
/* 题目信息 */
/*
 *1007 素数对猜想 (20分)
 */

/* my solution */
// solution-x, ms, defeat %
//

/* better solution */
// solution-x, ms, defeat %

bool isPrime(int a)
{
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    int n;
    int res = 0;
    scanf("%d", &n);
    for (int i = 5; i <= n; i++)
        if (isPrime(i - 2) && isPrime(i))
        {
            res++;
            //cout << i << endl;
        }
    //cout << "=============" << endl;
    cout << res;
    return 0;
}

/* 一些总结 */
// 1. 题意: 找到相邻素书差为2的素书对。
// 写一个判断素数的函数，然后判断相邻差为2的数字是否都为素数.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

