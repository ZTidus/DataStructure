// A_1003
// submission: AC
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV = 510;
const int INF = 100000000;

// n为顶点数,m为边数
// vertax_weight[]记录点权
int n, m, st, ed, G[MAXV][MAXV], vertax_weight[MAXV];
// distance_to_start[]记录到起点最短距离
// sum_vertax_weight[]记录最大点权之和
// shortest_paths_num[]记录最短路径条数
int distance_to_start[MAXV], sum_vertax_weight[MAXV], shortest_paths_num[MAXV];
bool visit[MAXV] = {false};

void Dijkstra(int s) {
    // 一系列准备工作
    fill(distance_to_start, distance_to_start+MAXV, INF);
    memset(shortest_paths_num, 0, sizeof(shortest_paths_num));
    memset(sum_vertax_weight, 0, sizeof(sum_vertax_weight));
    distance_to_start[s] = 0;
    sum_vertax_weight[s] = vertax_weight[s];
    shortest_paths_num[s] = 1;

    for(int i = 0; i < n; i++) {
        // 先找到离起点最近的顶点
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && distance_to_start[j] < MIN) {
                u = j;
                MIN = distance_to_start[j];
            }
        }
        if(u == -1) return;
        visit[u] = true;
        // 以u为中介点，寻找距离u最近的结点
        for(int v = 0; v < n; v++) {
            // v未被访问且u到v之间有边
            if(visit[v] == false && G[u][v] != INF) {
                if(distance_to_start[u] + G[u][v] < distance_to_start[v]) {
                    distance_to_start[v] = distance_to_start[u] + G[u][v];
                    sum_vertax_weight[v] = sum_vertax_weight[u] + vertax_weight[v];
                    shortest_paths_num[v] = shortest_paths_num[u];
                } else if(distance_to_start[u] + G[u][v] == distance_to_start[v]) {
                    // 以u为中介点的点权之和更大
                    if(sum_vertax_weight[u] + vertax_weight[v] > sum_vertax_weight[v]) {
                        sum_vertax_weight[v] = sum_vertax_weight[u] + vertax_weight[v];
                    }
                    shortest_paths_num[v] += shortest_paths_num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    // 读入点权
    for(int i = 0; i < n; i++) {
        scanf("%d", &vertax_weight[i]);
    }
    // 初始化图G
    fill(G[0], G[0]+MAXV*MAXV, INF);
    int u, v;
    // 读入边及边权
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", shortest_paths_num[ed], sum_vertax_weight[ed]);

    return 0;
}
