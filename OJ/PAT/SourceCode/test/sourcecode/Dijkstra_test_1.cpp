#include <cstdio>
#include <algorithm>
using namespace std;
// Dijkstra
// adj matrix
const int MAXV = 1000;  // 最大顶点数
const int INF = 1000000000;

int n, m, s, G[MAXV][MAXV];
int d[MAXV];  // 存放起点到达各点的最短路径长度
bool vis[MAXV];  // vis[i] == true:表示已被访问

void Dijkstra(int s) {  // s: 起点
    fill(d, d+MAXV, INF);
    d[s] = 0;  // s到它自身距离为0
    /* (1)找到u */
    for(int i = 0; i < n; i++) {
        // u记录与起点s距离最短的顶点,且并未被访问过
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;  // (2)标记u已被访问
        /*(3)优化 */
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
                d[v] = d[u] + G[u][v];  // 优化d[v]
        }
    }
}

int main() {
    int u, v, w;
    scanf("%d%d%d", &n, &m, &s);  // 顶点个数、边数、起点编号
    fill(G[0], G[0]+MAXV*MAXV, INF);  // 初始化
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);  // u, v及u->的权重
        G[u][v] = w;
    }
    Dijkstra(s);
    for(int i = 0; i < n; i++) {
        printf("%d ", d[i]);  // 输出起点s到各点的最短距离
    }
    return 0;
}
