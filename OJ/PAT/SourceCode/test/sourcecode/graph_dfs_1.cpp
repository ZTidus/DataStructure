// graph dfs
// From 《啊哈！算法》
#include <cstdio>
// vis数组记录那些顶点已访问过
int vis[101], sum, n, e[101][101];

// DFS
void dfs(int cur) {
    printf("%d ", cur);
    sum++;  // 每访问一个顶点，sum++
    if(sum == n) return;  // 所有顶点全部访问完毕
    for(int i = 1; i<= n; i++) {
        // 判断当前顶点cur到顶点i是否有边
        // 判断顶点i是否已被访问
        if(e[cur][i] == 1 && vis[i] == 0) {
            vis[i] = 1;  // 标记顶点i已被访问
            dfs(i);  // 从顶点i出发继续遍历
        }
    }
    return;
}

int main() {
    int m, a, b;
    scanf("%d %d", &n, &m);
    // 初始化二维矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) e[i][j] = 0;
            else e[i][j] = 99999999;
        }
    }

    // 读入顶点的边
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    // 从1号出发
    vis[1] = 1;
    dfs(1);
    
    getchar();
    getchar();
    return 0;
}
