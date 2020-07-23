#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *226. Invert Binary Tree
 Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        // 注意这一句，我之前写成swap(root->left->val, root->right->val);
        // 但是这种左右的孩子就没有交换过来，注意注意。
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

/* 一些总结 */
// 注意这一句，我之前写成swap(root->left->val, root->right->val);
// 但是这种左右的孩子就没有交换过来，注意注意。
