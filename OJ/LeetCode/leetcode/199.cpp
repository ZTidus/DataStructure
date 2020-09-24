#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: queue */
/* 题目信息 */
/*
 *199. Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            for (int i = 0; i < cnt; i++)
            {
                TreeNode* cur = q.front(); q.pop();
                if (i == cnt - 1) res.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
// 就是树的层序遍历，然后推入结果的值控制一个就行。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

