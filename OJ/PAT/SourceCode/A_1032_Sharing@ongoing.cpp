// A_1032_Sharing@ongoing
// -------- mine --------
// submission 1: 部分正确
// 1. 未想到用数组下标作为结点地址
// 2. wrong1: 未写出printf("%05d", ...);
// 3. wrong2: printf("%05d", i); 输出的应为结点地址，不是结点数据。
// submission 2: AC
// -------- mine --------

#include <cstdio>
struct Node {
    // int address; --(1)
    char data;
    int next;
    bool flag;
}node[100010];

int main(){
    int node1_first, node2_first, N;
    scanf("%d%d%d", &node1_first, &node2_first, &N);
    char data;
    int address, next;
    for(int i = 0; i < N; i++){
        scanf("%d %c %d", &address, &data, &next);
        node[address] = {data, next, false};  // initial
    }
    // 对第一条链进行遍历并标记
    for(int i = node1_first; i != -1; i = node[i].next){
        node[i].flag = true;
    }
    // 开始对第二条链进行逐一检查，检查到-1即可
    for(int i = node2_first; i != -1; i = node[i].next){
        if(node[i].flag == true) {
            // printf("%05d", node[i].data); -- (2)
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
