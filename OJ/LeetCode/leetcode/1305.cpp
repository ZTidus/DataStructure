#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */


/* better solution */
// solution1
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
    void inorder(TreeNode* root, vector<int>& num)
    {
        if (!root) return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right, num);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1, num2, res;    
        inorder(root1, num1);
        inorder(root2, num2);
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        res.resize(i + j + 2);
        int k = res.size()-1;
        printf("i=%d j=%d k=%d\n", i, j, k);
        
        while (i >= 0 && j >= 0)
        {
            if (num1[i] > num2[j])
            {
                res[k] = num1[i];
                i--;
                k--;
            }
            else
            {
                res[k] = num2[j];
                j--;
                k--;
            }
        }
        
        while (i >= 0)
            res[k--] = num1[i--];
        while (j >= 0)
            res[k--] = num2[j--];
        
        return res;
    }
};
// runtime: 284ms

// solution2
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& num)
    {
        if (!root) return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right, num);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;    
        inorder(root1, res);
        inorder(root2, res);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};
// runtime: 284ms

/* 一些总结 */
// 1. vector是可以使用sort()函数的，形式为sort(vector.begin(), vector.end());
// 2. 第一种方式借鉴与88题

