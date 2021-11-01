#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *109. Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/* my solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> sorted;
        sorted = toSorted(head);
        
        return toBST(sorted, 0, sorted.size() - 1);
    }
private:
    vector<int> toSorted(ListNode* head)
    {
        vector<int> sorted;
        while (head)
        {
            sorted.push_back(head->val);
            head = head->next;
        }
        return sorted;
    }
    TreeNode* toBST(vector<int> nums, int L, int R)
    {
        if (L > R) return nullptr;
        int m = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = toBST(nums, L, m - 1);
        root->right = toBST(nums, m + 1, R);
        
        return root;
    }
    
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. list →  vector →  BST
// 2. 
// 3. 

