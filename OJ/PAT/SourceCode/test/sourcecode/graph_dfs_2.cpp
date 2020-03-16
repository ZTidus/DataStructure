// error1: 最终输出结果dis总是min的初始值10^9
// 错误原因：没有对vis数组进行初始化
#include <cstdio>
const int maxn = 101;
int min = 1000000000, vis[maxn] = {0}, G[maxn][maxn];
int INF = 1000000000;
int n;
void dfs(int cur, int dis) {
    // 如果当前走过的路程大于之前找到的最短路，不必继续，返回
    if(dis > min) return;
    // 判断是否到达目标城市
    if(cur == n) {
        if(dis < min) min = dis;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(G[cur][i] != INF && vis[i] == 0) {
            vis[i] = 1;  // 标记城市i已被访问
            dfs(i, dis+G[cur][i]);  // 从城市i再出发，继续寻找目标城市
            vis[i] = 0;  // 之前一步探索完毕之后，取消对城市i的标记????
        }
    }
    return;
}

int main() {
    printf("输入城市数和道路数：\n");
    int m;
    scanf("%d%d", &n, &m);
    // 初始化二维矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }
    // 读入城市之间道路数
    printf("请输入：城市1 城市2 城市之间距离\n");
    for(int i = 1; i <= m; i++) {
        int city1, city2, city_dis;
        scanf("%d%d%d", &city1, &city2, &city_dis);
        G[city1][city2] = city_dis;
    }
    // 从1号城市出发
    vis[1] = 1;
    dfs(1, 0);
    printf("%d", min);

    getchar(); getchar();
    return 0;
}
