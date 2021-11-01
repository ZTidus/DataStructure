#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 112. Path Sum
 *Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

/* my solution */
// none

/* better solution */
// recursive ✓
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        int remaining_sum = sum - root->val;
        if (remaining_sum == 0 && !root->left && !root->right)
            return true;
        
        return hasPathSum(root->left, remaining_sum) || hasPathSum(root->right, remaining_sum);
    }
};
// 2 更易理解
class Solution {
public:
    bool res = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        helper(root, sum);
        
        return res;
    }
private:
    void helper(TreeNode* root, int sum)
    {
        if (!root) return;
        if (!root->left && !root->right && root->val == sum)
        {
            res = true;
            return;
        }
        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
    }
};
/* 一些总结 */
// 1. 题意: 
//[题意]找到从二叉树根结点到叶结点这条路径的值是否等于给定值，如果存在返回true.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

