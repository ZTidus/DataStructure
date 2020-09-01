#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */

/* my solution */
// none

/* better solution */
// ✓ recursive
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
    void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths)
    {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            paths.push_back(path);
        findPaths(root->left, sum-root->val, path, paths);
        findPaths(root->right, sum-root->val, path, paths);
        path.pop_back(); // important!!!
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> paths;
        findPaths(root, sum, path, paths);
        
        return paths;
    }
};
// better ✓ ✓  backtracking
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tempList;
        vector<vector<int>> res;
        backtrack(root, sum, res, tempList);
        
        return res;
    }
private:
    void backtrack(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& tempList)
    {
        if (!root) return;
        tempList.push_back(root->val);
        if (root->val == sum && !root->left && !root->right)
            res.push_back(tempList);
        else
        {
            backtrack(root->left, sum - root->val, res, tempList);
            backtrack(root->right, sum - root->val, res, tempList);
        }
        tempList.pop_back();
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. pop_back()的都是不符合条件的值。
// 2. 根结点必定加入，之后就是先遍历左子树，再遍历右子树。
// 3. 

