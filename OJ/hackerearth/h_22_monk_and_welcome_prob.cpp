// 第一次时将n, a[n], b[n]放在同一行声明，出现段错误，
// 后来先声明了n，再声明数组后就正常了。
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]+b[i]);
    }
    return 0;
}
