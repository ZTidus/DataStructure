#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1448. Count Good Nodes in Binary Tree
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:
                3
              /   \
            1       4
          /        /  \
        3         1    5
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
 */

/* my solution */


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
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        
        return cnt;
    }
private:
    void dfs(TreeNode* root, int greatest)
    {
        if (!root) return;
        if (root->val >= greatest) {
            cnt++;
            greatest = root->val;
        }
        dfs(root->left, greatest);
        dfs(root->right, greatest);
    }
};

/* 一些总结 */
// 1. 题意: 
//给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
// 需要注意的点: 
// 1. 需要注意在迭代过程中不断更新greastest.
// 2. 
// 3. 

