#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
 * 将数字转换为大写中文数字
 */


void numToBig(int val)
{
    //char big[10][2] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    //string big[10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    char big[10][4] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    int bit[64] = {0};
    int cnt = 0;
    while (val)
    {
        bit[cnt] = val % 10;
        val /= 10;
        cnt++;
    }

    for (int j = cnt - 1; j >= 0; j--)
    {
        int num = bit[j];
        printf("%s", big[num]);
    }
}

int main(int argc, char *argv[])
{
    int val;
    while (scanf("%d", &val) != EOF)
    {
        numToBig(val);
    }
    return 0;
}
