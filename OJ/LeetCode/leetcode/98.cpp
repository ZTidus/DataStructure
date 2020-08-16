#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */

/* my solution */
// ✗
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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
private:
    bool helper(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if (!root) return true;
        if (lower && root->val <= lower->val) return false;
        if (upper && root->val > upper->val) return false;
        
        if (!helper(root->left, lower, root)) return false;
        if (!helper(root->right, root, upper)) return false;
        
        return true;
    }
};
// 上边这段程序不知出了什么问题，通不过
// 在63行少了一个等号，添加了之后就可以了。

/* better solution */
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* nmin = nullptr, TreeNode* nmax = nullptr) {
        if(!root) 
            return true;
        if(nmin && root->val <= nmin->val)
            return false;
        if(nmax && root->val >= nmax->val)
            return false;
        return isValidBST(root->left, nmin, root) && isValidBST(root->right, root, nmax);
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

