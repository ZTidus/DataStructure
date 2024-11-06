# Tree

## 定义
```java
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) {
        this.val = val;
    }
    TreeNode (int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
```

## 树的分类

1. 二叉查找树(BST)
结点的左子树只包含小于当前结点的数。
结点的右子树只包含大于当前结点的数。
所有左子树和右子树自身必须也是二叉搜索树。
2. 满二叉树
3. 平衡二叉树（AVL）

## 树的遍历

1. 前序遍历(preorder)
中左右
root -> left -> right
2. 中序遍历(inorder)
左中右
left -> root -> right
3. 后序遍历(postorder)
左右中
left -> right -> root

注意这里的"前"、"中"、"后"是对于树的根节点说的，它说的遍历根节点的顺序。

- 手动去还原树，多写写
4. 深度优先遍历(DFS)
- 前序
- 中序
- 后序
5. 广度优先遍历(BFS)
层次遍历

## 树的构建

- 关于树，第一想法是递归。


## 问题
1. 求二叉树的最大高度
2. 求二叉树的最小高度
3. 求平衡二叉树的最大高度
4. 看两颗树是否相同
5. 看两颗树是否互为对称
6. 三种遍历方式（递归、递推），对应的时空复杂度
7. 二叉树层序遍历
8. 二叉树zigzag输出
