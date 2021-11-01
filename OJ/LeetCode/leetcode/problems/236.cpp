#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Tree */
/* 题目信息 */
/*
 *236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
                   3
                 /   \
                5    1
             /  \    /  \
           6    2   0   8
               / \
             7   4
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
 */

/* my solution */


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
        // 如果我们找到了p，直接进行返回，那如果下面就是q呢？ 其实这没有影响，但是还是要多考虑一下
        if (!root || root == p || root == q) 
            return root;
        root->left = lowestCommonAncestor(root->left, p, q); // 去左边找，期待返回找到的结点
        root->right = lowestCommonAncestor(root->right, p, q);// 去右边找，期待返回找到的结点
        if (!root->left) // left subtree isn't exist, return right
            return root->right;
        if (!root->right)  // right subtree isn't exist, return left
            return root->left;
        return root;  // 左右子树分别有一个，则返回root
    }
};

/* 一些总结 */
// 1. 题意: 二叉树的最近公共祖先(236)
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

