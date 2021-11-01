#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* offer */
/* Type: tree */
/* 题目信息 */
/*
 *输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
 
提示： 数组长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
 */

/* my solution */


/* better solution */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() <= 1)
            return true;
        return helper(postorder, 0, postorder.size() - 1);

    }
private:
    bool helper(vector<int> postorder, int i, int j)
    {
        if (i >= j)
            return true;
        int m;
        // find out the right subtree's first node
        for (m = 0; m < j; m++)
        {
            if (postorder[m] > postorder[j])
                break;
        }
        for (int k = m + 1; k < j; k++) // right subtree's value are all greater than root's value
            if (postorder[k] < postorder[j])
                return false;
        
        return helper(postorder, i, m - 1) && helper(postorder, m, j - 1);


    }
    
};

/* 一些总结 */
// 1. 题意: 验证一个序列是不是BST的后序遍历序列。
// 2. 根据BST和后序遍历的性质可以得到左右子树的范围。进而递归得到子树的子树...
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

