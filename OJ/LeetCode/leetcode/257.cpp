#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Input:
 *
 *    1
 *     /   \
 *     2     3
 *      \
 *        5
 *
 *        Output: ["1->2->5", "1->3"]
 *
 *        Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

/* my solution */
// ✓
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        
        return res;
    }
private:
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        if (!root) return;
        string s_val = to_string(root->val);
        if (!root->left && !root->right)
        {
            path += s_val;
            res.push_back(path);
        }
        else
            path += (s_val + "->");
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }
};

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
    void preorder(TreeNode* root, vector<string>& res, string t)
    {
        if (!root) return;
        // 1. root
        if (!t.empty())
            t += ("->" + to_string(root->val));
        else
            t = to_string(root->val);
        // 2. left
        if (root->left)
            preorder(root->left, res, t);
        // 3. right
        if (root->right)
            preorder(root->right, res, t);
        // leaf
        if (!root->left && !root->right)
            res.push_back(t);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root)
            preorder(root, res, "");
        
        return res;
    }
};

/* 一些总结 */
// 1. 第一种方法更好，容易理解。

