#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
    string s;
    int a, quotinet, remainder;
    cin >> s >> a;
    int len = s.length();
    quotinet = (s[0] - '0') / a;
    if (quotinet !=  0 && len > 1 || len == 1)
        cout << quotinet;

    remainder = (s[0] - '0') % a;
    for (int i = 1; i < len; i++)
    {
        quotinet = (remainder * 10 + s[i] - '0') / a;
        cout << quotinet;
        remainder = (remainder * 10 + s[i] - '0') % a;
    }
    cout << " " << remainder;

    return 0;
}
