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


bool isPrime(int i)
{
    if (i < 2) return false;
    // 注意要<=
    for (int j = 2; j <= sqrt(i); j++)
    {
        if (i % j == 0 && i != j)
            return false;
    }
    return true;
}
