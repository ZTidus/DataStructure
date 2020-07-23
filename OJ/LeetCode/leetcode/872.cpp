#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 872. Leaf-Similar Trees
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

                 3
               /   \
            5        1
         /   \       /   \
       6      2     9     8
            /   \  
          7      4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200
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
    void dfs(TreeNode* root, vector<int>& v)
    {
        if (!root) return;
        if (!root->left && !root->right)
            v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        
        return leaf1 == leaf2;
    }
};
/* 一些总结 */
// 1. 现在觉得if(!root)这样的写法更简洁
// 2. dfs
