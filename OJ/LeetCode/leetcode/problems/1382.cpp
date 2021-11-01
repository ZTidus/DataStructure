#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1382. Balance a Binary Search Tree
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:
  1                                   2
    \                                /  \
      2                             1    3
        \                                  \
          3                                  4
            \
              4
 */

/* my solution */
// ✓  1396ms
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return helper(nums, 0, nums.size() - 1);
    }
private:
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    TreeNode* helper(vector<int>nums, int L, int R)
    {
        if (L > R) return nullptr;
        int m = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(nums, L, m - 1);
        root->right = helper(nums, m + 1, R);
        
        return root;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

