#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Tree */
/* 题目信息 */
/*
 *814. Binary Tree Pruning
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

  1                   1
     \                  \
       0       →           0
      /  \                   \
    0     1                    1
 */

/* my solution */


/* better solution */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return containOne(root) ? root : nullptr;
    }
private:
    bool containOne(TreeNode* root)
    {
        if (!root) return false;
        bool L = containOne(root->left);
        bool R = containOne(root->right);
        if (!L) root->left = nullptr;
        if (!R) root->right = nullptr;
        
        return root->val == 1 || L || R;
    }
};

/* 一些总结 */
// 1. 题意: 
// 剪切掉树中不包括1的子树。
// 需要注意的点: 
// 1. 只关注本结点，然后递归其他
// 2. 
// 3. 

