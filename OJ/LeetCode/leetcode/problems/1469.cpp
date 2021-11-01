#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1469. 寻找所有的独生节点
二叉树中，如果一个节点是其父节点的唯一子节点，则称这样的节点为 “独生节点” 。二叉树的根节点不会是独生节点，因为它没有父节点。

给定一棵二叉树的根节点 root ，返回树中 所有的独生节点的值所构成的数组 。数组的顺序 不限 。

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        dfs(root, res);
        return res;
    }
private:    
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;
        
        if (root->left && root->right) {
            dfs(root->left, res);
            dfs(root->right, res);
        } else if (root->left || root->right) {
            TreeNode* remaining = root->left ? root->left : root->right;
            res.push_back(remaining->val);
            dfs(remaining, res);
        } else
            return;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 重点在于有无父结点
// 2. 太长时间没有做树方面的题目了，有些不熟悉。
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

