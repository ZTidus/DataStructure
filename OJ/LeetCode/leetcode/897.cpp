#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 897. Increasing Order Search Tree
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
 

Constraints:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        TreeNode* pre = head;
        stack<TreeNode*> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left   ;
            }
            
            root = todo.top();
            todo.pop();
            pre->right = root;
            pre = pre->right;
            root->left = NULL;
            root = root->right;
        }
        return head->right;
    }
};

// 2
// √
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
    TreeNode* cur;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        root->left = NULL;
        cur->right = root;
        cur = root;
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0); // 注意需要初始化，不然会报错。
        cur = res;
        inorder(root);
        
        return res->right;
    }
};
/* 一些总结 */
// 1. recursive看着更清晰一些。
// 2. 118行需要初始化
