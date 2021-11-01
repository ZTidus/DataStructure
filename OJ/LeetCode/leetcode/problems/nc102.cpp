#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。 
示例1
输入
[3,5,1,6,2,0,8,#,#,7,4],5,1
返回值
3
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 1214ms
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return helper(root, o1, o2)->val;
    }
private:
    TreeNode* helper(TreeNode* root, int o1, int o2)
    {
         if (!root || root->val == o1 || root->val == o2)
            return root;
        // find in left subtree
        root->left = helper(root->left, o1, o2);
        root->right = helper(root->right, o1, o2);
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;
        return root;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意题目中是二叉树，不是BST
// 2. 这道题和leetcode上的那道题不一样，返回的是结点的值。
// 3. 

