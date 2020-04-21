// Can you guess?
// way: sum up all the divisors.
// 此题中的数的因子不包括其本身
#include <cstdio>
int main() {
    int n;
    //printf("Input a number: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int num, sum = 0;
        scanf("%d", &num);
        for(int j = 1; j < num; j++) {
            int divisor = num % j;
            if(divisor == 0) sum += j;
        }
        printf("%d\n", sum);
    }
    return 0;
}
