#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: tree */
/* 题目信息 */
/*
 *99. Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
 */

/* my solution */


/* better solution */
// solution 1: 中序遍历BST，重新排序得到的数组，将之赋值为原来的树。
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        vector<TreeNode*> nodeList;
        inorder(root, nums, nodeList);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            nodeList[i]->val = nums[i];
        }
        
    }
private:
    void inorder(TreeNode* root, vector<int>& nums, vector<TreeNode*>& nodeList)
    {
        if (!root) return;
        inorder(root->left, nums, nodeList);
        nums.push_back(root->val);
        nodeList.push_back(root);
        inorder(root->right, nums, nodeList);
    }
};


// solution 2
class Solution {
public:
    void recoverTree(TreeNode* root) {
        pre_ = nullptr;
        first_ = nullptr;
        second_ = nullptr;
        inorder(root);
        if (first_ && second_)
            swap(first_->val, second_->val);
        
    }
private:
    TreeNode* pre_;
    TreeNode* first_;
    TreeNode* second_;
    
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        if (!pre_) pre_ = root;
        else
        {
            if (pre_->val > root->val)
            {
                if (!first_)
                    first_ = pre_;
                second_ = root;
            }
            pre_ = root;
        }
        inorder(root->right);
    }
};
/* 一些总结 */
// 1. 题意: 给定一颗BST，但是这颗树中有些值不符合BST定义，将之调整成为正确的BST.
//
// 需要注意的点: 
// 1. 第二种方法还没看懂
// 2. 
// 3. 

