#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 572. Subtree of Another Tree
 *Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool areEqual(TreeNode* s, TreeNode* t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return (s->val == t->val) && areEqual(s->left, t->left) && areEqual(s->right, t->right);
    }
    
    //bool traverse(TreeNode* s, TreeNode* t)
    //{
    //    if (!s && !t)
    //        return true;
    //    if (!s || !t)
    //        return false;
    //    return (!s && areEqual(s, t)) || traverse(s->left, t) || traverse(s->right, t); 
    //}
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return areEqual(s, t) || (s->left && isSubtree(s->left, t) || (s->right) && isSubtree(s->right, t));
    }
};

/* 一些总结 */
// [题意]判断一棵树是不是另一棵树的子树。另外写两个函数，第一个函数从相等的那个结点开始对比，第二个函数看s是否包含t

