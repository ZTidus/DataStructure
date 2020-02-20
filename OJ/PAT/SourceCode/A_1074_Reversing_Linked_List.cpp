// A_1074_Reversing_Linked_List
// 第（5）步是最难的
// 关于每一块的边界条件处理，和繁琐
// 显示运行超时...
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
// (1)定义静态链表
struct Node{
    int address, data, next;
    int order;  // 结点在链表上的序号
}node[maxn];
bool cmp(Node a, Node b){
    return a.order < b.order;  // 按order从小到大排序
}
int main(){
    // (2)初始化
    for(int i = 0; i < maxn; i++){
        node[i].order = maxn;  // 表示初始时全部为无效结点
    }
    int begin, n, K, address;
    scanf("%d%d%d", &begin, &n, &K);  // 起始地址，结点数目，步长
    for(int i = 0; i < n; i++){
        scanf("%d", &address);
        scanf("%d%d", &node[i].data, &node[i].next);
        node[i].address = address;
    }
    int p = begin, count = 0;  // count计数有效结点个数
    while(p != -1){            // 遍历单链表记录所有有效结点
        node[p].order = count++;;
        p = node[p].next;
    }
    // (4)对结点进行排序
    sort(node, node+maxn, cmp);
    n = count;

    // (5)按题目要求进行输出
    for(int i = 0; i < n/K; i++){  // 枚举 n / K 块
        for(int j = (i+1) * K -1; j > i * K; j--)  // 每一块从后往前输出
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
        // 每一块最后一个结点
        printf("%05d %d ", node[i*K].address, node[i*K].data);
        if(i < n/K -1){  // 如果不是最后一块，则指向下一块的最后一个结点[0, n-1)
            printf("%05d\n", node[(i+2)*K-1].address);
        } else {
            // 如果是最后一块
            if(n % K == 0)  // 恰好是最后一个结点
                printf("-1\n");
            else{
                // 最后一块是不完整的(<K)
                printf("%05d\n", node[(i+1)*K].address);
                for(i = n / K * K; i < n; i++){
                    printf("%05d %d", node[i].address, node[i].data);
                    if(i < n-1){
                        printf("%05d\n", node[i+1].address);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
