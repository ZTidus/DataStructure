#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 653. Two Sum IV - Input is a BST
 *Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    // 1. cur的功能呢个是?
    // 2. n是target减去当前根节点的值之后的值
    bool traverse(TreeNode* root, TreeNode* cur, int n)
    {
        if (root->val == n && root != cur)
            return true;
        if (root->left)
            if (traverse(root->left, cur, n) == true)
                return true;
        if (root->right)
            if (traverse(root->right, cur, n) == true)
                return true;
        
        return false;
    }
    
    bool search(TreeNode* root, int k, TreeNode* cur)
    {
        int temp = k - root->val;
        if (traverse(cur, root, temp) == true)
            return true;
        if (root->left)
            if (search(root->left, k, cur) == true)
                return true;
        if (root->right)
            if (search(root->right, k, cur) == true)
                return true;
        
        return false;
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        // 3. 为什么需要root的左右孩子都存在不?
        if (!root || (!root->left && !root->right)) return false;
        else
            return search(root, k, root);
    }
};

/* 一些总结 */
// 题解我没有看懂
