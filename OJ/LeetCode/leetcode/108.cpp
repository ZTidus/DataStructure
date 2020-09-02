#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 108. Convert Sorted Array to Binary Search Tree
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */

/* my solution */
// none

/* better solution */
// 1
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
    TreeNode* toBST(vector<int>& nums, int start, int end)
    {
        if (end <= start) return nullptr;
        int midIndex = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[midIndex]);
        root->left = toBST(nums, start, midIndex);
        root->right = toBST(nums, midIndex+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size());
    }
};

// 2
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int> nums, int L, int R)
    {
        if (L > R) return nullptr;
        // 建立当前子树根结点
        int mid = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 左子树下层递归
        root->left = helper(nums, L, mid - 1);
        // 右子树下层递归
        root->right = helper(nums, mid + 1, R);
        // 返回根结点
        return root;
    }
};

/* 一些总结 */
// 1. 使用递归，递归边界: end <= start
// 2. 递归式: 找出中间索引
// 3. return toBST(nums, 0, nums.size());
// 这里的nums.size()为什么不是num.size()-1???
// 注意第二种方法，是对上一个问题的回答。
