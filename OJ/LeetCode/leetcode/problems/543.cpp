#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 543. Diameter of Binary Tree
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *       / \     
 *     4   5    
 *    Return 3, which is the length of
 *    the path [4,2,1,3] or [5,2,1,3].
 *
 *    Note: The length of path between
 *    two nodes is represented by the
 *    number of edges between them.
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    int ans;
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L+R+1);
        return max(L, R) + 1; // 这个1可以看作是root到root->left或到root->right之间的边
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        
        return ans - 1;
    }
};
// 2 better
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res_ = 0;
        dfs(root);
        return res_; // 注意这里返回的变量，我总是将return dfs(root);这样写了
    }
private:
    int res_;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        res_ = max(res_, L + R);
        
        return 1 + max(L, R);
    }
};
/* 一些总结 */
// [题意]找到二叉树中距离最远的两个结点的距离; 这个加一是什么逻辑?

