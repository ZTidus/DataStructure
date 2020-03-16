// BFS更适用于所有边的权值相同的情况
/* 3章 最少转机-图的广度优先遍历 */
#include <cstdio>
struct node {
    int city;  // 城市编号
    int num_transfer;  // 转机次数
};
const int INF = 1000000000;

int main() {
    struct node que[2501];
    int G[51][51] = {0}, vis[51] = {0};
    int head, tail;
    printf("输入：城市数量、航线数量、起点城市、目标城市");
    int n, m, start, end;
    scanf("%d%d%d%d", &n, &m, &start, &end);
    // 初始化二维矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    // 读入航班线路
    printf("输入航班线路：起点城市 终点城市");
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 无向图
        G[a][b] = 1;
        G[b][a] = 1;
    }

    // 队列初始化
    head = 1;
    tail = 1;

    que[tail].city = start;  // 起点城市入队
    que[tail].num_transfer = 0;
    tail++;
    vis[start] = 1;  // 标记起点城市已被访问
    int flag = 0;

    while(head < tail) {
        int cur = que[head].city;  // 当前访问的城市
        for(int j = 1; j <= n; j++) {
            if(G[cur][j] != INF && vis[j] == 0) {
                que[tail].city = j;
                que[tail].num_transfer = que[head].num_transfer + 1;
                tail++;
                vis[j] = 1;
            }
            // 抵达目标城市
            if(que[tail].city == end) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
        head++;  // 注意当一个点扩展完毕后，head++才能继续扩展？？？
        // 这个应该是列表第一个元素出队列的操作
    }

    // 输出队列中最后一个（目标城市）的转机次数
    printf("转机次数为：%d", que[tail-1].num_transfer);

    getchar(); getchar();
    return 0;
}
