#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 111. Minimum Depth of Binary Tree
 *Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
 */

/* my solution */
// none

/* better solution */
// 1. 这个解法我还没有看懂
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left || !root->right)
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
// 可能下面一种好理解一些
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left)  // root左子树不存在而且root不是叶子结点，只能去求右子树中找
            return minDepth(root->right) + 1;
        if (!root->right) // root右子树不存在而且root不是叶子结点，只能去左子树寻找
            return minDepth(root->left) + 1;
        // 对于左右孩子都存在的结点
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
/* 一些总结 */

