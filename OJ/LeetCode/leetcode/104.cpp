#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
// ✓  easy to understand
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
    void dfs(TreeNode* root, int level)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            if (level > res)
                res = level;
            return;
        }
        
        if (root->left)
            dfs(root->left, level + 1);
        if (root->right)
            dfs(root->right, level + 1);
    }
    
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        
        return res;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max_depth = 1;
        if (root->left)
            max_depth = max(max_depth, 1 + maxDepth(root->left));
        if (root->right)
            max_depth = max(max_depth, 1 + maxDepth(root->right));
            
        return max_depth;
    }
};

// 2. 更简洁的写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        else
        {
            int L = maxDepth(root->left);
            int R = maxDepth(root->right);
            return 1 + max(L, R);
        }
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 下面一种方法写法更加简洁。
// 2. 求出左子树高度，求出右子树高度，求出左右中的最大者，加一返回。
// 3. 

