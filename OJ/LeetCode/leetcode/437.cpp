#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Tree */
/* 题目信息 */
/*
 437. Path Sum III Medium
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11*
 */

/* my solution */


/* better solution */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int self = dfs(root, sum);
        int L = pathSum(root->left, sum);
        int R = pathSum(root->right, sum);
        
        return L + R + self;
    }
private:
    int dfs(TreeNode* root, int sum)
    {
        if (!root) return 0;
        int L = dfs(root->left, sum - root->val);
        int R = dfs(root->right, sum - root->val);
        
        return L + R + (root->val == sum ? 1 : 0);
    }
    
    
};

/* 一些总结 */
// 1. 题意: 
// 求解从任一结点出发到子孙结点的路径和为指定值。
// 需要注意的点: 
// 1. 不是从根结点开始，也不是从叶子结点结束
// 2. 
// 3. 

