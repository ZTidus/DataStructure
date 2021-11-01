#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  tree*/
/* 题目信息 */
/*
 *1325. Delete Leaves With a Given Value

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you can't).

 */

/* my solution */


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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if (!root->left && !root->right && root->val == target)
        {
            root = nullptr;
        }
            
        return root;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 为什么是postorder，写成preorder就错了
// https://blog.csdn.net/qq_43827595/article/details/104262588
// 2. 我们需要删除所有值为 target 的叶子节点，那么我们的操作顺序应当从二叉树的叶子节点开始，逐步向上直到二叉树的根为止
// 3. 常见的二叉树遍历中，后序遍历是先遍历完所有子结点之后再遍历根结点，符合题意
