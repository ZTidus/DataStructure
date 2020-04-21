// A_1013
// error1: 输入时变量循序写错
// learn1: 邻接表的输入方法 G[a].push_back[b]
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1010;
vector<int> Adj[N];  // 邻接表
bool vis[N];// = {false};  // 标记顶点是否被访问

int current;    // 当前删除的顶点
void dfs(int v) {
    if(v == current) return;
    vis[v] = true;  // 当前结点v已被访问
    for(int i = 0; i < Adj[v].size(); i++) {  // 遍历顶点v的所有邻接点
        if(vis[Adj[v][i]] == false) {
            dfs(Adj[v][i]);
        }
    }
}
int main() {
    int n, m, k;  // cities, highways, cities to be checked
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        // 无向图
        Adj[a].push_back(b);  // a -> b
        Adj[b].push_back(a);  // b -> a
    }
    for(int query = 0; query < k; query++) {
        scanf("%d", &current);
        memset(vis, false, sizeof(vis));
        int block = 0;  // 连通块个数
        for(int i = 1; i <= n; i++) {
            if(i != current && vis[i] == false) {
                dfs(i);
                block++;
            }
        }
        printf("%d\n", block-1);
    }
    return 0;
}
