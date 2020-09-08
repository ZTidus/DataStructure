#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: tree */
/* 题目信息 */
/*
 *129. Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 */

/* my solution */
// 类似leetcode - 257的做法
// 这种更好理解
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        res_ = 0;
        string tmp = "";
        helper(root, tmp);
        
        return res_;
    }
private:
    int res_;
    void helper(TreeNode* root, string tmp)
    {
        if (!root) return;
        string s = to_string(root->val);
        if (!root->left && !root->right)
        {
            tmp += s;
            res_ += stoi(tmp);
        }
        else
        {
            tmp += s;
        }
        
        helper(root->left, tmp);
        helper(root->right, tmp);
    }
};

/* another solution */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
        
    }
private:
    int helper(TreeNode* root, int val)
    {
        if (!root) return 0;
        int res = root->val + val * 10;
        if (!root->left && !root->right)
            return res;
        int L = helper(root->left, res);
        int R = helper(root->right, res);
        
        return L + R;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 这道题有点绕，注意根结点的值
// 2. 拿到这道题时就感觉有点奇怪，但是说不上来，就是那个根结点
// 3. 一开始想拿一个string给存进去，然后再转换成int类型数据，后来发现往坐是13,但是往右边就是132了，并不是12

