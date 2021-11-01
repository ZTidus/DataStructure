#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 606. Construct String from Binary Tree
 * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
    string tree2str(TreeNode* root) {
        // 1. root == null
        if (!root) return "";
        string s = to_string(root->val);
        // 2. root->left == null && root->right == null
        if (!root->left && !root->right)
            return s + "";
        // 3. root->right == null
        if (!root->right)
            return s + "(" + tree2str(root->left) + ")";
        // 4. default is that the root->left must have ()
        return s + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};

/* 一些总结 */
// 分情况讨论
// 1. root == null
// 2.   root
//     /   \
//   null   null
// 3.   root
//    /    \
//   lchild null
// 4.   root
//    /    \
//  null   rchild
// 5.   root
//    /    \
// lchild  rchild
