#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int res = 0;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val)
            arrowLeft += (L + 1);
        if (root->right && root->right->val == root->val)
            arrowRight += (R + 1);
        
        res = max(res, arrowLeft + arrowRight);
        
        return max(arrowLeft, arrowRight);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//[题意]找到二叉树中结点值全相同的最长路。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

