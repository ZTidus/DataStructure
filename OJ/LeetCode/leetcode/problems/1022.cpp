#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1022. Sum of Root To Leaf Binary Numbers
 * Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.



Example 1:

            1
          /    \
       0         1
    /   \       /   \
  0     1     0     1

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22


Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
 */

/* my solution */
// none

/* better solution */
// 1
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
    void helper(TreeNode* root, int sum)
    {
        if (root) // root exists
        {
            // root->left and root->right all not exist
            if (!root->left && !root->right)
            {
                res += sum;
                return;
            }
            if (root->left)
                helper(root->left, 2 * sum + root->left->val);
            if (root->right)
                helper(root->right, 2 * sum + root->right->val);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if (!root)
            return 0;
        helper(root, root->val);
        
        return res;
    }
};

// 2 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
        
    }
private:
    int dfs(TreeNode* root, int sum)
    {
        if (!root) return 0;
        sum = 2 * sum + root->val;
        if (!root->left && !root->right)
            return sum;
        
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
/* 一些总结 */
// 1. helper()里边的书写逻辑需要学习
// 2. 进制换算过程需要多练。
// 第二种方法要更容易理解一些，不必再另外令变量，临时变量只在函数区域使用最后返回最终的结果，更加简洁。
