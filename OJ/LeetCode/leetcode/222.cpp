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
/* Type: tree */
/* 题目信息 */
/*
 *222. Count Complete Tree Nodes
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
 */

/* my solution */
// solution-1, 44ms, defeat 49.47%
// 前根遍历后的到数组，返回数组大小
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        vector<int> nums;
        to_vector(root, nums);
        return nums.size();

    }
private:    
    void to_vector(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        nums.push_back(root->val);
        if (root->left)
            to_vector(root->left, nums);
        if (root->right)
            to_vector(root->right, nums);
    }
};

/* better solution */
// solution-2, 40ms, defeat 75.70%
// 还不懂下面这种方法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = 0, sum = 0;
        TreeNode *t = root, *t0 = nullptr;
        while (t)
        {
            t = t->left;
            height++;
        }
        
        t = root;
        int level = height - 2;
        while (level > -1)
        {
            t0 = t->left;
            for (int i = 0; i < level; i++)
                t0 = t0->right;
            if (t0)
            {
                sum += 1 << level;
                t = t->right;
            }
            else 
            {
                t = t->left;
            }
            level--;
        }
        
        if (t) sum++;
        return sum + ((1 << (height - 1)) - 1);
    }
};

/* 一些总结 */
// 1. 题意: 返回完全二叉树的结点个数
//
// 需要注意的点: 
// 1.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

