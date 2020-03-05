// A_1004
/* -------- 
 * error: 忘记加分号
 * error: 循环变量写错
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100;
vector<int> Node[maxn];  // 存放树
int leaf[maxn] = {0};
int max_depth = 1;

void DFS(int index, int depth) {
    max_depth = max(depth, max_depth);
    if(Node[index].size() == 0) {  // 如果是叶子结点
        leaf[depth]++;
        return;
    }
    for(int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], depth+1);  // 遍历Node[index]所有子结点
    }
}

int main() {
    int n, m; // n:结点个数; m: 非叶子结点个数
    int parent, k, child;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d", leaf[1]);
    for(int i = 2; i <= max_depth; i++)
        printf(" %d", leaf[i]);
    return 0;
}
