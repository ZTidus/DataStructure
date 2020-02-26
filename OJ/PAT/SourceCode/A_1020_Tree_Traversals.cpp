// A_1020_Tree_Traversals
// -------- mine --------
// submission 1: AC
// -------- mine --------

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n; // Number of nodes
/* 返回构建出的根节点地址 */
node* create(int postL, int postR, int inL, int inR) {
    if(postL > postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;  // 左子树结点个数
    root->lchild = create(postL, postL+numLeft-1, inL, k-1);
    root->rchild = create(postL+numLeft, postR-1, k+1, inR);

    return root;
}

int num = 0;  // 已输出结点个数
// 层序遍历
void BFS(node* root) {
    queue<node*> q;  // 队列中存储地址
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if(num < n) printf(" ");
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    node* root = create(0, n-1, 0, n-1);  // 建树
    BFS(root);
    return 0;
}
