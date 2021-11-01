#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 */

/* my solution */
// none
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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        unordered_set<int> st;
        inorder(root, st);
        cout << "st.size()=" << st.size() << endl;
        int cnt = 2;
        for (auto e : st)
        {
            cout << cnt << endl;
            if (!--cnt)
            {
                //cout << cnt << endl;
                return e;
            }
        }
        return -1;
    }
private:
    void inorder(TreeNode* root, unordered_set<int>& st)
    {
        if (!root) return;
        inorder(root->left, st);
        st.insert(root->val);
        inorder(root->right, st);
    }
};
// 上边这个出了什么问题???没检查出来
// 上边这个错误的原因是使用了unordered_set，这个容器中的数据是无序的。
/* better solution */
class Solution {
public:
    void preorder(TreeNode* root, set<int>& s)
    {
        if (!root) return;
        s.insert(root->val);
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        preorder(root, s);
        
        int cnt = 2;
        for (auto& e : s)
        {
            if (!--cnt)
                return e;
        }
        
        return -1;
    }
};

/* 一些总结 */
// 1. set 使用
// 2. auto 使用

