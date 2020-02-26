// A_1086
// 在本地运行无结果，但是提交后AC

#include <cstdio>
#include <stack>
#include <string.h>
using namespace std;

const int maxn = 50;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;  // 结点个数

/* 根据pre&in返回二叉树根节点 */
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return NULL;
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);

    return root;
}

int num = 0;  // 已输出结点个数
/* 后序遍历 */
void postorder(node* root) {
    if(root == NULL) 
        return;  // 空树（递归边界）
    // （递归式）
    // left-right-root
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data);
    num++;
    if(num < n) printf(" ");
}

int main() {
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for(int i = 0; i < 2 * n; i++) {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0) {
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        } else {
            scanf("%d", &x);
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    node* root = create(0, n-1, 0, n-1);  // 建树
    postorder(root);  // 后序遍历
    
    return 0;
}

