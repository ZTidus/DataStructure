#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
//#include "dbg.h"
using namespace std;


// @val: 十进制整数
// @base: 目标转换的进制 2~16
void trans(int val, int base)
{
    int x[64], i = 0;
    while (val)
    {
        x[i] = val % base;
        val /= base;
        i++;
    }

    // 从后往前输出
    for (int k = i - 1; k >= 0; k--)
    {
        if (x[k] < 10)
            printf("%d", x[k]);
        else if (x[k] <= 16)
            printf("%c", 'A' + x[k] - 10);
    }
}

int main(int argc, char *argv[])
{
    int num, base;
    while (scanf("%d%d", &num, &base) != EOF)
    {
        if (base <= 0 || base > 16)
        {
            printf("value error\n");
            return 0;
        }

        //dbg(num, base);
        trans(num, base);
    }
    return 0;
}
