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
 *剑指 Offer 55 - I. 二叉树的深度
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
例如：

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 

提示：

节点总数 <= 10000
 */

/* my solution */
// solution-1: 8ms defeat 96.42%
// 1. 递归找到左子树高度
// 2. 递归找到右子树高度
// 3. 返回左、右子树中最高的并加上一。
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int l_dep = maxDepth(root->left);
        int r_dep = maxDepth(root->right);
        return max(l_dep, r_dep) + 1;

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

