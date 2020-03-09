// A_1066
// submission1: partial correct.
// error1: 在newNode()中未初始化Node->height = 1;
// submission2: partial correct.
// error2: 在left rotation&right rotation中，更新root与temp的高度不能颠倒？
// submission3: AC
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int v, height;
    node *lchild, *rchild;
} *root;

// 生成新结点
node* newNode(int v) {
    node* Node = new node;  // 申请node型变量地址空间
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

// 获取以root为根结点当前子树的高度
int getHeight(node* root) {
    if(root == NULL) return 0;
    else return root->height;
}

// 更新结点root的height
void updateHeight(node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// 计算结点root平衡因子
int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

// Left rotation
void L(node* &root) {  // 注意加引用
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
//    updateHeight(temp);
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// Right rotation
void R(node* &root) {  // 注意加引用
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
//    updateHeight(temp);
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// Insert
void insert(node* &root, int v) {
    if(root == NULL) {
        root = newNode(v);
        return;
    }
    if(v < root->v) {
        insert(root->lchild, v);
        updateHeight(root);  
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(root->lchild) == 1) {  // LL
                R(root);;
            } else if(getBalanceFactor(root->lchild) == -1) {  // LR
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->rchild) == -1) {  // RR
                L(root);
            } else if(getBalanceFactor(root->rchild) == 1) {  // RL
                R(root->rchild);
                L(root);
            }
        }
    }
}

// AVL create
//node* create(int data[], int n) {
//    node* root = NULL;
//    for(int i = 0; i < n; i++) {
//        insert(root, data[i]);
//    }
//    return root;
//}

// Main
int main() {
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->v);
    return 0;
}
