#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: Tree */
/* 题目信息 */
/*
 *剑指 Offer 54. 二叉搜索树的第k大节点
给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数
 */

/* my solution */
// solution-1: 32ms defeat 66.77%
// 二叉树中序遍历
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int index = nums.size() - k;
        return nums[index];
    }
private:    
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
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

