#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& umap)
    {
        if (!root) return;
        umap[root->val]++;  // 记录每个值出现的频次
        dfs(root->left, umap);
        dfs(root->right, umap);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> umap;
        vector<int> res;
        
        dfs(root, umap);
        int maxVal = 0;
        for (auto i : umap)
        {
            if (i.second > maxVal)
            {
                res.clear(); // 最终只有一个结果
                maxVal = i.second;
            }
            if (i.second >= maxVal)
                res.push_back(i.first);
        }
        
        return res;
    }
};
// easy to understand
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> ump;
        inorder(root, ump);
        vector<int> res;
        
        int max_freq = 0;
        for (auto e : ump)
        {
            if (e.second > max_freq)
                max_freq = e.second;
        }
        printf("%d\n", max_freq);
        for (auto e : ump)
        {
            if (e.second == max_freq)
            {
                res.push_back(e.first); 
            }
        }
        
        return res;
    }
private:
    void inorder(TreeNode* root, unordered_map<int, int>& ump)
    {
        if (!root) return;
        inorder(root->left, ump);
        ump[root->val]++;
        inorder(root->right, ump);
    }
};
/* 一些总结 */
// [题意]找出二叉树中出现频次最高的数字。unordered_map<int, int> umap, umap.first, umap.second; 

