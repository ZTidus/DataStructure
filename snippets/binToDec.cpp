// binToDec
#include <stdio.h>
#include <math.h>

int binToDec(int n)
{
    int decNum = 0, remainder;
    int power = 1;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decNum += remainder * power;
        power = power * 2;
    }

    return decNum;
}

int main(int argc, char *argv[])
{
    int n;
    printf("input a binary number: \n");
    scanf("%d", &n);
    printf("%d -bin to dec - %d\n", n, binToDec(n));
    return 0;
}
