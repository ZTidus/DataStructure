// A_1052_Linked_List_Sorting@ongoing
// -------- mine --------
// submission 1: AC
// 1. 为什么要区分有效结点和无效结点？
// 2. count是必须要有的 
// 3. wrong2: 
// -------- mine --------
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {  // (1)定义静态链表
    int address, data, next;
    bool flag;
}node[100010];

// bool cmp(Node a, Node b) {
    // return a.key < b.key;  // 按key从小到大排序
// }
bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false) {
        return a.flag > b.flag;  // 只要有一个是无效结点，就将之放在后面去(?)
    } else {
        return a.data < b.data;
    }
}
int main(){
    int n, begin;
    scanf("%d%d", &n, &begin);
    int address, data, next;
    for(int i = 0; i < n; i++) {  // (2)初始化
        scanf("%d%d%d", &address, &data, &next);
        node[address] = {address, data, next, false};
    }

    // 记录有效结点数目
    int count = 0;
    for(int i = begin; i != -1; i = node[i].next){
        node[i].flag = true;
        count++;
    }
    if(count == 0)
        printf("0 -1");
    else {
        sort(node, node+100000, cmp);
        printf("%d %05d\n", count, node[0].address);
        for(int i = 0; i < count; i++) {
            // printf("%05d %d %05d\n", node[i].address, node[i].data, \
                node[i].next);
            printf("%05d %d ", node[i].address, node[i].data);
            if(i != count-1)  // 这个判断很巧妙
                printf("%05d\n", node[i+1].address);  // !!!
            else
                printf("-1\n");
        }
        return 0;
    }
}