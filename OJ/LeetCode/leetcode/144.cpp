#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) return res;
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* cur = st.top(); st.pop();
            res.push_back(cur->val);
            if (cur->right) st.push(root->right);
            if (cur->left) st.push(root->left);
        }
        
        return res;
    }
};
// wrong1: nullptr
// 解决: 在35行前添加 if (!cur) continue;
// wrong2: 注意36行中是st.push(cur->right);下一行也是如此。

// ✓ iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* cur = st.top(); st.pop();
            if (!cur) continue;
            res.push_back(cur->val);
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        
        return res;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 前根遍历迭代写法: 
//   1. 将根结点入栈
//   2. 出栈一个元素，将右结点和左结点依次入栈
//   3. 重复2步骤，即使用一个while循环即可。
