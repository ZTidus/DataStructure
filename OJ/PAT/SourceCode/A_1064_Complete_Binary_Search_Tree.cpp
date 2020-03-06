// A_1064
// jump <20.3.6>
// 最后直接将CBT数组顺序输出即为结果，这点不懂
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;
// number存放结点权值
int  n, number[maxn], CBT[maxn], index = 0;
void inOrder(int root) {
    if(root > n) return;  // 递归边界
    inOrder(root * 2);
    CBT[root] = number[index++];  // 填入数据
    inOrder(root * 2 + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }
    // BST inorder是递增的,故递增的序列一定是中序遍历
    sort(number, number+n);
    inOrder(1);
    for(int i = 1; i <= n; i++) {
        printf("%d", CBT[i]);
        if(i < n) printf(" ");
    }
    return 0;
}

