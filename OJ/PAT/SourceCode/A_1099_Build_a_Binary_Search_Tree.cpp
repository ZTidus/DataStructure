// A_1099
// 1. 注意二叉树的静态写法
// 2. 注意Node[root].data = in[num++];这句填入数据的写法
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct node {  // 二叉树静态写法
    int data;
    int lchild, rchild;
} Node[maxn];
int n, in[maxn], num = 0;  // num: 已经输入/输出的结点个数

// 中序遍历
void inOrder(int root) {
    if(root == -1) 
        return;
    inOrder(Node[root].lchild);
    Node[root].data = in[num++];  // 根据指针域中地址填入数据域中数据
    inOrder(Node[root].rchild);
}

// 层序遍历
void BFS(int root) {
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d", Node[now].data);
        num++;
        if(num < n) printf(" ");
        if(Node[now].lchild != -1) q.push(Node[now].lchild);
        if(Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}

int main() {
    int lchild, rchild;  // 注意这种临时变量的代换
    scanf("%d", &n);  // 输入结点个数
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &lchild, &rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    sort(in, in+n);  // 排序作为中序排列
    inOrder(0);
    BFS(0);
    return 0;
}
