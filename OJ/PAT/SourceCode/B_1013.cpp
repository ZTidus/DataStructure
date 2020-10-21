#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int m, n;
    scanf("%d%d", &m, &n);
    int cnt = 0;
    int num = 2;
    vector<int> primes;
    while (cnt < n)
    {
        if (isPrime(num))
        {
            cnt++;
            if (cnt >= m)
                primes.push_back(num);

        }
        num++;
    }

    // output
    cnt = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        cnt++;
        // 没行第一个数字不需要输出空格
        if (cnt % 10 != 1) printf(" ");
        printf("%d", primes[i]);
        if (cnt % 10 == 0) printf("\n");
    }
    return 0;
}

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 判断素数的函数要小心写。
// 2. 
// 3. 

