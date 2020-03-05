// A_1090
// Tree
// submission: AC

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
vector<int> child[maxn];   // 存放树
double p, r;
int n, maxDepth = 0, num = 0;  // num为最大深度的叶结点个数

void DFS(int index, int depth) {
    if(child[index].size() == 0) {  // 到达叶结点
        if(depth > maxDepth) {
            maxDepth = depth;
            num = 1;
        } else if(depth == maxDepth) {
            num++;
        }
        return;
    }
    for(int i = 0; i < child[index].size(); i++) {
        DFS(child[index][i], depth+1); // 递归访问结点index的子结点
    }
}

int main() {
    int father, root;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &father);
        if(father != -1)
            child[father].push_back(i);  // i是father子结点
        else
            root = i;
    }
    DFS(root, 0);  // DFS入口
    printf("%.2f %d", p * pow(1 + r, maxDepth), num);
    return 0;
}
