// A_1097_Deduplication_on_a_Linked_List
// -------- mine --------
// submission 1: 段错误
// 1. 变量的命名一定要有意义
// 2. wrong_1: 写掉了一个取地址符
// submission 2: 多种错误
// 3. wrong_2: 将node[address] 写成了node[i]
// submission 3: 答案错误
// 4. wrong_3
// submission 4: 答案错误
// 5. wrong_4: 怎么会输出还有&呢?
// submission 5: AC
// -------- mine --------
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct Node {
    int address, data, next;
    int order = 2 * maxn;
}node[maxn];
bool exist[maxn];
// 对结点进行排序。排序原则:
// 对结点的order进行排序，有效结点从0开始直到maxn
// 删除结点从maxn开始，直到2maxn
// 无效结点都是2max
// 从小到大排序依次是：valid, removed, invalid
int cmp(Node a, Node b) {
    return a.order < b.order;
}
int main(){
    int begin, n; // 开始结点地址，结点个数
    int countValid = 0, countRemoved = 0;
    scanf("%d%d", &begin, &n);
    int address;
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);  // ->wrong_1
        // ->wrong_2
        node[address].address = address;
    }

    for(int i = begin; i != -1; i = node[i].next) {
        if(exist[abs(node[i].data)] == false){
            exist[abs(node[i].data)] = true;
            node[i].order = countValid;
            countValid++;
        } else {
            // node[i].order = countValid + maxn;  // ->wrong_3
            node[i].order = countRemoved + maxn;
            countRemoved++;
        }
    }
    sort(node, node+maxn, cmp);
    int count = countValid + countRemoved;
    for(int i = 0; i < count; i++) {
        if(i != countValid-1 && i != count-1) {
            printf("%05d %d %05d\n", node[i].address, node[i].data, \
                node[i+1].address);
        } else {
            // ->wrong_4
            // printf("%05d %d -1\n", &node[i].address, node[i].data);
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}