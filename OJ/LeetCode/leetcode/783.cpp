/*
 * 783. Minimum Distance Between BST Nodes
 * Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 *
 */

// my solution
// none

// better
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
    int min_diff = INT_MAX;
    void helper(TreeNode* root)
    {
        if (root)
        {
            if (root->left) helper(root->left);
            if (prev != nullptr)
            {
                min_diff = min(min_diff, abs(root->val - prev->val));
            }
            prev = root;
            if (root->right) helper(root->right);
        }
        else
            return;
    }
    
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        
        return min_diff;
    }
};

// 1. 不要凭以往类似题，总是去想以前的题是怎么做的，需要想这道题的逻辑
