#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: tree */
/* 题目信息 */
/*
 *590. N-ary Tree Postorder Traversal
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Follow up:

Recursive solution is trivial, could you do it iteratively?

 */

/* my solution */
class Solution {
public:
    void post_travese(Node* root, vector<int>& res)
    {
        if (root == NULL) return;
        for (int i = 0; i < root->children.size(); i++)
        {
            post_travese(root->children[i], res);
        }
        res.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        post_travese(root, res);

        return res;
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

