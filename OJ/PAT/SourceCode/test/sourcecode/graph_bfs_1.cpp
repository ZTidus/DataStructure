// from 啊哈！算法
// graph bfs
// error: 未得到预期结果

#include <cstdio>
const int INF = 1000000000;

int main() {
    int n, m, cur, vis[101] = {0}, G[101][101];
    int que[10001], head, tail;
    scanf("%d%d", &n, &m);
    // 初始化二维矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    // 读入顶点之间的边
    for(int i = 1; i <= n; i++) {
        int a, b; // 表示顶点
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    // 队列初始化
    head = 1;
    tail = 1;

    que[tail] = 1;
    tail++;
    vis[1] = 1;

    while(head < tail) {
        cur = que[head];  // 当前访问的顶点编号
        for(int i = 1; i <= n; i++) {
            // 如果cur到i右边，且i未被访问
            if(G[cur][i] == 1 && vis[i] == 0) {
                que[tail] = i;  // i入队
                tail++;
                vis[i] = 1;    // 标记i已被访问
            }
            // tail>n表示所有结点已被访问
            if(tail > n) break;
        }
        head++;
    }

    for(int i = 1; i < tail; i++) {
        printf("%d ", que[i]);
        getchar(); getchar();
        return 0;
    }
}
