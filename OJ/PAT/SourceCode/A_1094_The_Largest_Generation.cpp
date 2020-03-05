// A_1094
// submission: AC
// 还是很懵，感觉会了，又好像不会。<20.3.5>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> Node[MAXN];
int hashTable[MAXN] = {0};  // 记录每层的结点个数
void DFS(int index, int level) {
    hashTable[level]++;
    for(int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], level+1);
    }
}
int main() {
    int n;  // Number of family members
    int m;  // Number of family members who have children
    int parent, k, child;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &parent, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &child);
            Node[parent].push_back(child);
        }
    }
    DFS(1, 1);  // 根结点为1号结点，层号为1
    int maxLevel = -1, maxValue = 0;
    for(int i = 1; i < MAXN; i++) {
        if(hashTable[i] > maxValue) {
            maxValue = hashTable[i];
            maxLevel = i;
        }
    }
    printf("%d %d\n", maxValue, maxLevel);
    return 0;
}
