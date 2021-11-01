#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 617. Merge Two Binary Trees
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7


Note: The merging process must start from the root nodes of both trees.
 */

/* my solution */
// none
//
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. 递归边界
        if (!t1) return t2;
        if (!t2) return t1;
        // 2. 递归式
        t1->val += t2->val;
        if (t2->left)
            t1->left = mergeTrees(t1->left, t2->left);
        if (t2->right)
            t1->right = mergeTrees(t1->right, t2->right);
            
        return t1; 
    }
};
/* 一些总结 */
// 1. 这个题也不知道该怎么写，就相加知道，当然递归边界这个不好想，也不是不好想。
