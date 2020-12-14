#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1008. Construct Binary Search Tree from Preorder Traversal
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
               8
             /   \
           5        10
         /  \         \
        1    7          12
 */

/* my solution */
// ✗ 这种方法为什么不对?
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sort(preorder.begin(), preorder.end());
        print(preorder);
        return constructBST(preorder, 0, preorder.size());
    }
private:
    void print(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
            printf("%d ", nums[i]);
        printf("\n");
    }
    
    TreeNode* constructBST(vector<int>sorted, int L, int R)
    {
        if (L >= R) return nullptr;
        int mid = L + (R - L) / 2;
        TreeNode* root = new TreeNode(sorted[mid]);
        root->left = constructBST(sorted, L, mid);
        root->right = constructBST(sorted, mid + 1, R);
        
        return root;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

