// B_1019_数字黑洞
// sub1: 部分正确
// 1. 高位补0
// printf("%04d", n);
// sub2: AC
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {  // 递减排序
    return a > b;
}

// 将n的每一位存入数组num中
void to_array(int n, int num[]) {
    for(int i = 0; i < 4; i++) {
        num[i] = n % 10;
        n /= 10;
    }
}

// 将num数组转换为数字
int to_number(int num[]) {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        sum = sum * 10 + num[i];
    }
    return sum;
}

int main() {
    int n, max, min;
    scanf("%d", &n);
    int num[5];
    while(1) {
        to_array(n, num);  // 存入数组
        sort(num, num+4);  // 递增排序
        min = to_number(num);  // 得到最小值
        sort(num, num+4, cmp); // 递减排序
        max = to_number(num);  // 得到最大值
        n = max - min;  // 得到下一个数
        printf("%04d - %04d = %04d\n", max, min, n);
        if(n == 0 || n == 6174) break;
    }
}
