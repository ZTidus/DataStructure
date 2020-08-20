#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/* my solution */


/* better solution */
// iterative ✓
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = st.top(); st.pop();
                cur = cur->left;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 因为后序遍历的压栈顺序是左-右-根，由于先遍历完左子树，然后遍历完右子树，然后才能处理当前节点，为了和之前的代码的结构保持一致，我们可以反向处理，也就是按根-右-左的顺序压栈，结果反向输出即可
// 2. 不要对root这个变量名执迷不悟
// 3. 

