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
 *
 */

/* my solution */


/* better solution */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return nullptr;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        TreeNode* root = helper(preorder, 0, preorder.size() - 1,
                                inorder, 0, inorder.size() - 1);
        return root;


    }
private:    
    unordered_map<int, int> mp; // 这个不要写成函数的参数了，不然每次递归的函数栈都要拷贝这个表。
                                // 写成函数参数会i超时。
    TreeNode* helper(vector<int> preorder, int preorderStart, int preorderEnd,
                     vector<int> inorder, int inorderStart, int inorderEnd)
    {
        if (preorderStart > preorderEnd)
            return nullptr;
        int rootVal = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootVal);
        if (preorderStart == preorderEnd)
            return root;
        else
        {
            // 得到根结点咋中序遍历序列下的下标
            int rootIndex = mp[rootVal];
            int leftNodes = rootIndex - inorderStart; // 左子树结点个数
            int rightNodes = inorderEnd - rootIndex;  // 右子树结点个数

            TreeNode* leftSubtree = helper(preorder, preorderStart + 1, preorderStart + leftNodes, inorder, inorderStart, rootIndex - 1);
            TreeNode* rightSubtree = helper(preorder, preorderEnd - rightNodes + 1, preorderEnd, inorder, rootIndex + 1, inorderEnd);
            root->left = leftSubtree;
            root->right = rightSubtree;
            return root;
        }
    }
};

/* 一些总结 */
// 1. 题意: 根据前序遍历和中序遍历得到二叉树
// 2. 解决：
//       1. 画图后得到对行左子树和右子树的范围
//       2. 给范围边界点取好名称
//       3. 使用递归方式得到最终的左子树
//       [4]. 可以使用map来查找根结点在inorder序列中的下标,但是注意map需要定义在函数之外成为全局变量。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

