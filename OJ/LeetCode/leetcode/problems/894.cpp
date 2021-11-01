#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *894. All Possible Full Binary Trees
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        // 偶数个结点，没有解
        if (N % 2 == 0) return {};
        if (N == 1) return {new TreeNode(0)};
        vector<TreeNode*> res;
        // 递归左子树结点个数
        // 跳过偶数，因为偶数不会有解
        for (int i = 1; i < N; i += 2)
        {
            for (auto l : allPossibleFBT(i))
            {
                for (auto r : allPossibleFBT(N - i - 1)) // 递归右子树，当前右子树结点个数为总结点-左子树结点-根结点1个
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 由于是full binary tree, 则树的结点数是奇数
// 2. 
// 3. 

