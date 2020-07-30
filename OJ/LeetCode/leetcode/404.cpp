#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 404. Sum of Left Leaves
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *            3
 *           / \
 *          9  20
 *             /  \
 *            15   7
 *
 *                 There are two left leaves in the binary tree, with values 9
 *                 and 15 respectively. Return 24.
 */

/* my solution */
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
    int sum = 0;
    void preorder(TreeNode* root)
    {
        if (root)
        {
            if (root->left)
                if (!root->left->left && !root->left->right)
                    sum += root->left->val;
            preorder(root->left);
            preorder(root->right);
        }
        else
            return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        
        return sum;
    }
};

/* better solution */

/* 一些总结 */
// 1. 本题不难，按照题目字面逻辑即可。

