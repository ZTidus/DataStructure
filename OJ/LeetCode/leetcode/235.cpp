#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 *                       6
 *                     /   \
 *                   2      8
 *                 /  \    /  \
 *               0     4  7    9
 *                  /  \
 *                3    5
 *
 *  Example 1:
 *
 *  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 *  Output: 6
 *  Explanation: The LCA of nodes 2 and 8 is 6.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if (pVal > parentVal && qVal > parentVal)
            return lowestCommonAncestor(root->right, p, q);
        else if (pVal < parentVal && qVal < parentVal)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

/* 一些总结 */
// [题意]找到两个结点的挨着最近的父亲。画图，三种不同的情况，递归写出来的代码很好理解。

