#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 530. Minimum Absolute Difference in BST
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    TreeNode* prev = nullptr;
    int minVal = INT_MAX;
    void helper(TreeNode* root)
    {
        if (root)
        {
            helper(root->left);
            if (prev != nullptr)
                minVal = min(minVal, abs(prev->val - root->val));
            prev = root;
            helper(root->right);
        }
        else
            return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        // 1. root is NULL
        if (!root) return 0;
        helper(root);
        return minVal;
    }
};

/* 一些总结 */
// 1. 对于prev这个在其中的变换自己需要好好想一下，比较混乱。
