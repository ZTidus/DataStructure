// binary_tree search
void search(node *root, int x, int newdata) {
    if(root == NULL)
        return;  // 空树，死胡同（递归边界）
    if(root->data == x)
        root->data = newdata;
    search(root->lchild, x, newdata);  
    search(root->rchild, x, newdata);
}
// binary_tree insert
void insert(node *&root, int x) {
    if(root == NULL) {  // 空树，说明查找失败，也即插入位置（递归边界）
        root = newNode(x);
        return;
    }
    if() 
        insert(root->lchild, x);
    else
        insert(root->rchild, x);
}
// binary_tree create
node *Create(int data[], int n) {
    node *root = NULL;  // 新建空根节点root
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}
// preorder
void preorder(node *root) {
    if(root == NULL) {
        return;  // 空树（递归边界）
    }
    // (递归式)
    // 访问根节点
    pirntf("%d\n", root->data); // 这里的输出只是一个示例，你也可以进行其他操作
    // 访问左子树
    preorder(root->lchild);
    // 访问右子树
    preorder(root->rchild);
}
// inorder
void inorder(node *root) {
    if(root == NULL) {
        return;  // 空树（递归边界）
    }
    // (递归式)
    // 访问左子树
    inorder(root->lchild);
    // 访问根结点
    printf("%d\n", root->data);
    // 访问右结点
    inorder(root->rchild);
}
// postorder
void postorder(node *root) {
    if(root == NULL) {
        return;  // 空树（递归边界）
    }
    // (递归式)
    // 访问左子树
    postorder(root->lchild);
    // 访问右结点
    postorder(root->rchild);
    // 访问根结点
    printf("%d\n", root->data);
}
// Layerorder
void LayerOrder(node *root) {
    queue<node*> q;  // 队列中存储的是地址
    q.push(root); // (1)将跟结点地址入队
    while(!q.empty()) {
        node* now = q.front();  // (2)取出队首元素
        q.pop();
        printf("%d", now->data);  // (2)访问队首元素
        if(now->lchild != NULL) q.push(now->lchild); // (3)左孩子进队
        if(now->rchild != NULL) q.push(now->rchild); // (4)右孩子进队
    } // (5)直到队列为空
}

// 题目中要求计算结点所在层次
struct node{
    int data;
    int layer;
    node* lchild;
    node* rchild;
}
void LayerOrder(node* root) {
    queue<node*> q;
    root->layer = 1;  // 根结点层次为1
    q.push(root);  // (1)将根结点地址入队
    while(!q.empty()) {
        node* now = q.front();  // (2)取出队首元素
        q.pop();
        printf("%d", now.data);  // (2)访问队首元素
        if(now->lchild != NULL) {  // 左孩子不空
            now->lchild->layer = now->layer + 1;
            q.push(now->lchild); // (3)左孩子进队
        }
        if(now->rchild != NULL) {
            now->rchild->layer = now->layer + 1;
            q.push(now->rchild);  // (4)右孩子进队
        }
    }
}

// 先序序列区间[preL, preR], 中序序列区间[inL, inR]，返回根结点地址
node* create(int preL, int preR, int inL, int inR) {
    if(preL > preR)
        return NULL;  // 先序序列长度<=0时，返回
    node* root = new node;  // 新建根结点，存放二叉树的根结点
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;  // 左子树的结点个数
    // 返回左子树的根结点地址，赋值给root的左指针
    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    // 返回右子树的根结点地址，赋值给root的右指针
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);

    return root;
}
