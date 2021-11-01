- 1\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  hash table*/
/* 题目信息 */
/*
 *
 */

/* my solution */
// 下边这总暴力的方法会超时
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                printf("inner\n");
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    //break;
                    return res;
                }
            }
        }
        
        return res;
    }
};

/* better solution */
// reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            ump[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (ump.count(complement) && ump[complement] != i) // important
            {
                res.push_back(i);
                res.push_back(ump[complement]);
                return res;
            }
        }
        
        return res;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 以空间换时间
// 2. 使查找时间O(n)降到O(1)
// 3. 

```\n
- 100\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 100. Same Tree
 * Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. p and q are both null
        if (!p && !q)
            return true;
        // 2. one of p and q is null
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/* 一些总结 */
// 1. 递归，这个递归只用考虑根结点的，左右孩子结点套进去。
```\n
- 1002\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1002. Find Common Characters
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
 */

/* my solution */
// none
/* better solution */
//
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> count(26, 0);
        vector<int> tmp(26, 0);
        // standard
        for (auto c: A[0])
            count[c - 'a']++;
        // compare
        for (int i = 1; i < A.size(); i++) {
            
            for (auto c: A[i])
            {
                tmp[c - 'a']++;
            }
            
            for (int j = 0; j < 26; j++)
            {
                count[j] = min(count[j], tmp[j]);
                tmp[j] = 0; // 这个单词对比完后需要清零，进行下一个单词的对比！
            }
                
        }
        
        // output
        vector<string> res;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                int cnt = count[i];
                while (cnt--)
                {
                    char x = i + 'a';
                    //string s = x;
                    string s;
                    s = x;
                    res.push_back(s);
                }
            }
        }
        
        return res;
    }
};
//  
// 先将A中第一个string做一个基准，然后对剩余的string进行遍历，每次遍历完一个string后，就与基准作一个对比，得到其中最少频数并更新基准，这样遍历完之后的string后，基准中那些频数大于1的字符就是这些string中共同的字符，之后输出。
/* 一些总结 */

```\n
- 1008\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1008. Construct Binary Search Tree from Preorder Traversal
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
               8
             /   \
           5        10
         /  \         \
        1    7          12
 */

/* my solution */
// ✗ 这种方法为什么不对?
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        sort(preorder.begin(), preorder.end());
        print(preorder);
        return constructBST(preorder, 0, preorder.size());
    }
private:
    void print(vector<int> nums)
    {
        for (int i = 0; i < nums.size(); i++)
            printf("%d ", nums[i]);
        printf("\n");
    }
    
    TreeNode* constructBST(vector<int>sorted, int L, int R)
    {
        if (L >= R) return nullptr;
        int mid = L + (R - L) / 2;
        TreeNode* root = new TreeNode(sorted[mid]);
        root->left = constructBST(sorted, L, mid);
        root->right = constructBST(sorted, mid + 1, R);
        
        return root;
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

```\n
- 101\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *101. Symmetric Tree
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

         1
        / \
       2   2
      / \ / \
     3  4 4  3
            

  But the following [1,2,2,null,3,null,3] is not:

          1
         / \
        2   2
        \   \
        3    3
                           

    Follow up: Solve it both recursively and iteratively.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

/* 一些总结 */
// [题意]看二叉树是不是对称二叉树。想好条件的是与非

```\n
- 1019\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1019. Next Greater Node In Linked List
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.

Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.

 

Example 1:

Input: [2,1,5]
Output: [5,5,0]
Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]
Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]
 

Note:

1 <= node.val <= 10^9 for each node in the linked list.
The given list has length in the range [0, 10000].
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> input;
        stack<int> s;
        
        while (head)
        {
            input.push_back(head->val);
            head = head->next;  
        }
        
        int size = input.size();
        vector<int> res(size);
        
        for (int i = size-1; i >= 0; i--)
        {
            while (!s.empty() && input[i] >= s.top())
                s.pop();
            if (s.empty())
                res[i] = 0;
            else
                res[i] = s.top();
            
            s.push(input[i]);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 一开始我的想法是固定每一次的head，然后遍历head后的每一个值与head做对比，但是显然这样的效率很低。

```\n
- 102\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 */

/* my solution */


/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> v;
            for (int i = 0; i < cnt; i++)
            {
                TreeNode* cur = q.front(); q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            vv.push_back(v);
        }
        
        return vv;
    }
    
    
};

/* 一些总结 */
// 1. 题意: 二叉树的层序遍历
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1022\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1022. Sum of Root To Leaf Binary Numbers
 * Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.



Example 1:

            1
          /    \
       0         1
    /   \       /   \
  0     1     0     1

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22


Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.
 */

/* my solution */
// none

/* better solution */
// 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    void helper(TreeNode* root, int sum)
    {
        if (root) // root exists
        {
            // root->left and root->right all not exist
            if (!root->left && !root->right)
            {
                res += sum;
                return;
            }
            if (root->left)
                helper(root->left, 2 * sum + root->left->val);
            if (root->right)
                helper(root->right, 2 * sum + root->right->val);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if (!root)
            return 0;
        helper(root, root->val);
        
        return res;
    }
};

// 2 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
        
    }
private:
    int dfs(TreeNode* root, int sum)
    {
        if (!root) return 0;
        sum = 2 * sum + root->val;
        if (!root->left && !root->right)
            return sum;
        
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
/* 一些总结 */
// 1. helper()里边的书写逻辑需要学习
// 2. 进制换算过程需要多练。
// 第二种方法要更容易理解一些，不必再另外令变量，临时变量只在函数区域使用最后返回最终的结果，更加简洁。
```\n
- 103\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> inres;
            for (int n = cnt-1; n >= 0; n--)
            {
                TreeNode* cur = q.front(); q.pop();
                inres.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (flag)
                reverse(inres.begin(), inres.end());
            res.push_back(inres);
            flag = !flag;
        }
        
        return res;
    }
};

/* 一些总结 */
// z字形打印二叉树，层序遍历。

```\n
- 104\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
// ✓  easy to understand
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int level)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            if (level > res)
                res = level;
            return;
        }
        
        if (root->left)
            dfs(root->left, level + 1);
        if (root->right)
            dfs(root->right, level + 1);
    }
    
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        
        return res;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max_depth = 1;
        if (root->left)
            max_depth = max(max_depth, 1 + maxDepth(root->left));
        if (root->right)
            max_depth = max(max_depth, 1 + maxDepth(root->right));
            
        return max_depth;
    }
};

// 2. 更简洁的写法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        else
        {
            int L = maxDepth(root->left);
            int R = maxDepth(root->right);
            return 1 + max(L, R);
        }
    }
};
// 3. 更容易想到的办法
// 这种方法和第2种方法一样，只是将有无临时变量而已。
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right)
            return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
}

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 第2方法写法更加简洁。
// 2. 求出左子树高度，求出右子树高度，求出左右中的最大者，加一返回。
// 3. 

```\n
- 1046\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *1046. Last Stone Weight
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
Note:
1 <= stones.length <= 30
1 <= stones[i] <= 1000
 */

/* my solution */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int len = stones.size();
        if (len == 1) return stones[0];
        if (len == 2) return stones[1] - stones[0];
        while (len > 2)
        {
            int first = stones.back(); stones.pop_back(); len--;
            int second = stones.back(); stones.pop_back(); len--;
            stones.push_back(first - second); len++;
            sort(stones.begin(), stones.end());
        }
        if (len == 1) return stones[0];
        if (len == 2) return stones[1] - stones[0];
        return 0;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意:
// 给定一个数组，每次选取其中最大值和次大值相减，如果两个数字一样，则在数组中消除这两个数字，如果不一样，则得到结果（为正）后添加进入数组中，进行一下选择最大和次大，最后如果数组中剩下一个数字，返回这个数字，如果没有数字剩下，则返回0.
// 2. 解决：
//   1. 排序
//   2. 循环找取最大和次大
//   3. 判断最后的数组。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1047\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1047. Remove All Adjacent Duplicates In String
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
 */

/* my solution */
class Solution {
public:
    string removeDuplicates(string S) {
        if (!S.empty()) return "";
        stack<string> s;  // !!!这里应该是char型
        s.push(S[0]);
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == s.top())
            {
                s.pop();
            }
            else
                s.push(S[i]);
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            printf("%c", s.top());
            s.pop();
        }
        
        return s;
    }
};

/* better solution */
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        stack<char> st;
        for (auto cur: S)
        {
            //if (st.empty())
            //    st.push(cur);
            //else if (st.top() == cur)
            if (!st.empty() && st.top() == cur)
                st.pop();
            else st.push(cur);
        }
        
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
            
        return res;
    }
};

/* 一些总结 */
// 1. S为string类型，可以for(auto e: S)
// 2. reverse(S.begin(), S.end())

```\n
- 107\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 107. Binary Tree Level Order Traversal II
 *Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
 */

/* my solution */
// 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> v;
            for (int i = 0; i < cnt; i++)
            {
                TreeNode* cur = q.front(); q.pop();
                v.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            vv.push_back(v);
        }
        
        reverse(vv.begin(), vv.end());
        return vv;
    }
    
    
};

// 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelorder(TreeNode* root, vector<vector<int>>& res, int height)
    {
        if (root) 
        {
            while (res.size() <= height)
                res.push_back({});
            res[height].push_back(root->val);
            levelorder(root->left, res, height+1);
            levelorder(root->right, res, height+1);
        }
        else
            return;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, res, 0);
        reverse(res.begin(), res.end());
        
        return res;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. reverse()
// 2. 
// 3. 

```\n
- 108\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 108. Convert Sorted Array to Binary Search Tree
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */

/* my solution */
// none

/* better solution */
// 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* toBST(vector<int>& nums, int start, int end)
    {
        if (end <= start) return nullptr;
        int midIndex = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[midIndex]);
        root->left = toBST(nums, start, midIndex);
        root->right = toBST(nums, midIndex+1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size());
    }
};

// 2
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int> nums, int L, int R)
    {
        if (L > R) return nullptr;
        // 建立当前子树根结点
        int mid = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // 左子树下层递归
        root->left = helper(nums, L, mid - 1);
        // 右子树下层递归
        root->right = helper(nums, mid + 1, R);
        // 返回根结点
        return root;
    }
};

/* 一些总结 */
// 1. 使用递归，递归边界: end <= start
// 2. 递归式: 找出中间索引
// 3. return toBST(nums, 0, nums.size());
// 这里的nums.size()为什么不是num.size()-1???
// 注意第二种方法，是对上一个问题的回答。
```\n
- 109\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *109. Convert Sorted List to Binary Search Tree
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/* my solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> sorted;
        sorted = toSorted(head);
        
        return toBST(sorted, 0, sorted.size() - 1);
    }
private:
    vector<int> toSorted(ListNode* head)
    {
        vector<int> sorted;
        while (head)
        {
            sorted.push_back(head->val);
            head = head->next;
        }
        return sorted;
    }
    TreeNode* toBST(vector<int> nums, int L, int R)
    {
        if (L > R) return nullptr;
        int m = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = toBST(nums, L, m - 1);
        root->right = toBST(nums, m + 1, R);
        
        return root;
    }
    
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. list →  vector →  BST
// 2. 
// 3. 

```\n
- 11\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointer */
/* 题目信息 */
/*
 *11. Container With Most Water
 */

/* my solution */
// brute force  - 超时 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int hi = min(height[i], height[j]);
                int width = j - i;
                res = max(res, hi * width);
            }
        }
        
        return res;
    }
};

/* better solution */
// two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int last = height.size() - 1;
        int res = 0;
        
        while (first < last)
        {
            if (height[first] >= height[last]) // 使用两者中较矮的作为高
            {
                res = max(res, (last - first) * height[last]);
                last--;
            }
            else
            {
                res = max(res, (last - first) * height[first]);
                first++;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
// 解法：使用two pointers, 初始时一个指向开始，一个指向最后位置，如果初始位置高度大于第二个指针所指高度，则第一个指针向后移动一个位置，算出结果；如果后一个指针高度小于第一个指针高度，则后一个指针向前移动一个位置。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 110\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: Tree */
/* 题目信息 */
/*
 *110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
 */

/* my solution */


/* better solution */
// 自底向上
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
        
    }
private:    
    int height(TreeNode* root)
    {
        if (!root)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
};

/* 一些总结 */
// 1. 题意: 判断一棵树是否为平衡二叉树
// 算出左子树高度，算出右子树高度，然后对比
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1108\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1108. Defanging an IP Address
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    string defangIPaddr(string address) 
    {
        string res = "";
        for (char c : address) {
            if (c == '.') {
                res += "[.]";
                continue;
            }
            res += c;
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 将字符串中的.替换为[.]
// 遍历然后替换
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

```\n
- 111\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 111. Minimum Depth of Binary Tree
 *Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
 */

/* my solution */
// none

/* better solution */
// 1. 这个解法我还没有看懂
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left || !root->right)
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
// 可能下面一种好理解一些
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left)  // root左子树不存在而且root不是叶子结点，只能去求右子树中找
            return minDepth(root->right) + 1;
        if (!root->right) // root右子树不存在而且root不是叶子结点，只能去左子树寻找
            return minDepth(root->left) + 1;
        // 对于左右孩子都存在的结点
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
/* 一些总结 */

```\n
- 1111\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1111. Maximum Nesting Depth of Two Valid Parentheses Strings

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        int depth = 0;
        for (int i = 0; i < n; i++)
        {
            if (seq[i] == '(')
            {
                depth++;
                res[i] = depth % 2;
            }
            else
            {
                res[i] = depth % 2;
                depth--;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 没有看懂题目
// 2. 
// 3. 

```\n
- 1119\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1119. 删去字符串中的元音
给你一个字符串 S，请你删去其中的所有元音字母（ 'a'，'e'，'i'，'o'，'u'），并返回这个新字符串。

 

示例 1：

输入："leetcodeisacommunityforcoders"
输出："ltcdscmmntyfrcdrs"
示例 2：

输入："aeiou"
输出：""
 

提示：

S 仅由小写英文字母组成。
1 <= S.length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-vowels-from-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string removeVowels(string S) {
        string res = "";
        for (char c : S) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                continue;
            } else {
                res += c;
            }
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 删除字符
// 很简单的一道题目。
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

```\n
- 112\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 112. Path Sum
 *Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

/* my solution */
// none

/* better solution */
// recursive ✓
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        int remaining_sum = sum - root->val;
        if (remaining_sum == 0 && !root->left && !root->right)
            return true;
        
        return hasPathSum(root->left, remaining_sum) || hasPathSum(root->right, remaining_sum);
    }
};
// 2 更易理解
class Solution {
public:
    bool res = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        helper(root, sum);
        
        return res;
    }
private:
    void helper(TreeNode* root, int sum)
    {
        if (!root) return;
        if (!root->left && !root->right && root->val == sum)
        {
            res = true;
            return;
        }
        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
    }
};
/* 一些总结 */
// 1. 题意: 
//[题意]找到从二叉树根结点到叶结点这条路径的值是否等于给定值，如果存在返回true.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 113\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *113. Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */

/* my solution */
// none

/* better solution */
// ✓ recursive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths)
    {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            paths.push_back(path);
        findPaths(root->left, sum-root->val, path, paths);
        findPaths(root->right, sum-root->val, path, paths);
        path.pop_back(); // important!!!
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> paths;
        findPaths(root, sum, path, paths);
        
        return paths;
    }
};
// better ✓ ✓  backtracking
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tempList;
        vector<vector<int>> res;
        backtrack(root, sum, res, tempList);
        
        return res;
    }
private:
    void backtrack(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& tempList)
    {
        if (!root) return;
        tempList.push_back(root->val);
        if (root->val == sum && !root->left && !root->right)
            res.push_back(tempList);
        else
        {
            backtrack(root->left, sum - root->val, res, tempList);
            backtrack(root->right, sum - root->val, res, tempList);
        }
        tempList.pop_back();
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. pop_back()的都是不符合条件的值。
// 2. 根结点必定加入，之后就是先遍历左子树，再遍历右子树。
// 3. 

```\n
- 1137\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1137. N-th Tribonacci Number
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 */

/* my solution */
class Solution {
public:
    int tribonacci(int n) {
        // recursive boundary
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        // recursion
        
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
// result
// Time Limit Exceeded

/* better solution */
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3;i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. dp is what? I saw it in the discuss area. dp is dynamic programming.
// 2. Need to record each state's value in vector.
// 3. Not recursion.
// 4. why is dp(n+1), not dp(n)? Because there is a dp[0]
// 5. 时刻谨记recursive boundary and 递归式

```\n
- 1154\n
```cpp
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
/* Type: math */
/* 题目信息 */
/*
 *1154. Day of the Year
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int dayOfYear(string date) {
        int yy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8, 2));
        
        int res = dd; // 初始化为当月的天数
        vector<int> month({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
        
        if (isLeapYear(yy))
            month[1] = 29; // 润年2月是29天
        for (int i = 0; i < mm - 1; i++)
        {
            res += month[i];
        }
        
        return res;
    }
    
private:
    bool isLeapYear(int y)
    {
        // 润年
        // 1. 能被400整除
        // 2. 是4的倍数但不是100的倍数
        if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) 
            return true;
        return false;
    }
};

/* 一些总结 */
// 1. 题意: 
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

```\n
- 1160\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *1160. Find Words That Can Be Formed by Characters
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
 */

/* my solution */


/* better solution */
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        string res = "";
        unordered_map<char, int> mp;
        for (char c: chars)
        {
            mp[c]++;
        }
        
        for (auto str: words)
        {
            bool flag = true;
            unordered_map<char, int> mp2;
            for (auto c: str)
                mp2[c]++;
            for (auto c: str)
            {
                if (mp2[c] > mp[c])
                    flag = false;
            }
            
            if (flag) res += str;
        }
        
        return res.size();
    }
};

/* 一些总结 */
// 1. 题意: 
// 看string类型的chars中字符能否组成words中每一个单词，如果可以组成，将这个单词的长度添加入结果之中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1165\n
```cpp
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
/* Type: string */

/* 题目信息 */
/*
 *1165. 单行键盘
我们定制了一款特殊的力扣键盘，所有的键都排列在一行上。

我们可以按从左到右的顺序，用一个长度为 26 的字符串 keyboard （索引从 0 开始，到 25 结束）来表示该键盘的键位布局。

现在需要测试这个键盘是否能够有效工作，那么我们就需要个机械手来测试这个键盘。

最初的时候，机械手位于左边起第一个键（也就是索引为 0 的键）的上方。当机械手移动到某一字符所在的键位时，就会在终端上输出该字符。

机械手从索引 i 移动到索引 j 所需要的时间是 |i - j|。

当前测试需要你使用机械手输出指定的单词 word，请你编写一个函数来计算机械手输出该单词所需的时间。

 

示例 1：

输入：keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
输出：4
解释：
机械手从 0 号键移动到 2 号键来输出 'c'，又移动到 1 号键来输出 'b'，接着移动到 0 号键来输出 'a'。
总用时 = 2 + 1 + 1 = 4. 
示例 2：

输入：keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
输出：73
 

提示：

keyboard.length == 26
keyboard 按某种特定顺序排列，并包含每个小写英文字母一次。
1 <= word.length <= 10^4
word[i] 是一个小写英文字母
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int res = 0;
        map<char, int> mp;
        int cnt = 0;
        for (char c : keyboard) {
            mp[c] = cnt++;
        }
        
        // 因为使用foreach语法不好处理第一个字符，所以还是使用了索引方法。
        res += (mp[word[0]] - 0);
        
        for (int i = 1; i < word.size(); i++) {
            int prev = mp[word[i-1]];
            int cur = mp[word[i]];
            res += abs(cur - prev);
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
// 需要考虑一些逻辑条件
// 需要注意的点: 
// 1. 当foreach不适用时考虑一下索引吧
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

```\n
- 118\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        
        for (int i = 1; i < numRows; i++)
        {
            vector<int> cur;
            vector<int> prevRow = res[i - 1];
            
            // 每行中第一个元素
            cur.push_back(1);
            
            // 算出中间所有元素
            for (int j = 1; j < i; j++)
            {
                cur.push_back(prevRow[j - 1] + prevRow[j]);
            }
            
            // 每行中最后一个元素
            cur.push_back(1);
            
            res.push_back(cur);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 杨辉三角
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
    vector<vector<int> > res;
    res = solution.generate(5);

    return 0;
}

```\n
- 1180\n
```cpp
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
/* Type: string */

/* 题目信息 */
/*
 *1180. 统计只含单一字母的子串
 *给你一个字符串 S，返回只含 单一字母 的子串个数。

示例 1：

输入： "aaaba"
输出： 8
解释： 
只含单一字母的子串分别是 "aaa"， "aa"， "a"， "b"。
"aaa" 出现 1 次。
"aa" 出现 2 次。
"a" 出现 4 次。
"b" 出现 1 次。
所以答案是 1 + 2 + 4 + 1 = 8。
示例 2:

输入： "aaaaaaaaaa"
输出： 55
 

提示：

1 <= S.length <= 1000
S[i] 仅由小写英文字母组成。

 */

/* my solution */
// solution-x, ms, defeat %

/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int countLetters(string S) {
        int res = 0;
        int cnt = 1;
        int len = S.size();
        for (int i = 1; i < len; i++) {
            if (S[i] == S[i - 1])
                cnt++;
            else {
                res += (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
        }
        res += (cnt * (cnt + 1)) / 2; // 这一句的作用是什么?
                                    // 因为最后一个字母还没有算进去，所以就需要算一个最后的。
        
        return res;
    }
};


/* 一些总结 */
// 1. 题意: 
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
    string input = "aaaba";
    int res = solution.countLetters(input);
    cout << res;

    return 0;
}

```\n
- 1189\n
```cpp
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
/* Type: hash table */
/* 题目信息 */
/*
 *1189. Maximum Number of Balloons
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.
 */

/* my solution */
// solution-1, 12ms, defeat 13.89%
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> mp; // map换成unordered_map, 时间变为8ms, 36.61%
        for (char c : text)
            mp[c]++;
        
        string base = "balloon";
        vector<int> nums;
        for (char c : base) {
            if (c == 'l' || c == 'o') {
                nums.push_back(mp[c] / 2);
                continue;
            }
            nums.push_back(mp[c]);
        }
        
        int min_val = nums[0];
        for (int i : nums)
            min_val = min(min_val, i);
        
        return min_val;
    }
};

/* better solution */
// solution-2, 4ms, defeat 81.51%
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b, a, l, o, n;
        b = 0;
        a = 0;
        l = 0;
        o = 0;
        n = 0;
        for (char c : text) {
            b += (c == 'b') ? 1 : 0;
            a += (c == 'a') ? 1 : 0;
            l += (c == 'l') ? 1 : 0;
            o += (c == 'o') ? 1 : 0;
            n += (c == 'n') ? 1 : 0;
        }
        
        return min({b, a, l / 2, o / 2, n});
        
    }
};

/* 一些总结 */
// 1. 题意: 给定一字符串,看这个字符串中的字符可以组成多少个balloon.
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

```\n
- 1200\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Array */
/* 题目信息 */
/*
 *1200. Minimum Absolute Difference
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
 */

/* my solution */
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        // 1. find out the minium
        int min_diff = INT_MAX;
        // sort arr
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            min_diff = min(min_diff, arr[i] - arr[i-1]);
        }
        printf("%d\n", min_diff);
        
        // 2. compare and find out results
        for (int i = 1; i < arr.size(); i++)
        {
            vector<int> temp;
            if (arr[i] - arr[i-1] == min_diff)
            {
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }
        
        return res;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//    1. 找到最小的比较值
//    2. sort arr，然后一一对比后一个值与前一个值的差值是否与最小比较值相同，然后推入.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1207\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1207. Unique Number of Occurrences
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
 */

/* my solution */


/* better solution */
// map, set ✓
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        set<int> s;
        // find out each number's occurrence number
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            s.insert(it->second);
        }
        
        return mp.size() == s.size();
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1209\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1209. Remove All Adjacent Duplicates in String II
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
 */

/* my solution */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.empty()) return "";
        stack<char> stk;
        unordered_map<char, int> ump;
        
        for (auto e : s)
        {
            if (stk.empty())
                stk.push(e);
            else if (stk.top() == e && k-1 == ump[e])
                stk.pop();
            else if (stk.top() == e)
                ump[e]++;
            else
                stk.push(e);
        }
        
        string res = "";
        for (auto e : ump)
        {
            for (int i = 0; i < e.second; i++)
                res += to_string(e.first);
        }
        
        return res;
    }
};
// 上边这种做法为什么是错的?
/* better solution */
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> vec;
        
        for (char& c: s)
        {
            if (vec.empty())
                vec.push_back(make_pair(c, 1));
            else if (c == vec.back().first && vec.back().second == k-1) // 注意这里是k-1, not k!!!
                vec.pop_back();
            else if (c == vec.back().first)
                vec.back().second++;
            else 
                vec.push_back(make_pair(c, 1));
        }
        
        string res;
        for (auto &p: vec)
        {
            for (int i = 0; i < p.second; i++)
                res += p.first;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. make_pair()
// 2. 这一道题是关于栈的题目，但是使用了vector，将vector改成了stack，出了错，stack里不能使用pair吗?
// 这道题再一次做时出了很多问题: 
// 1. 为什么使用vector而不是stack
// 2. k 与 k-1
// 3. 复合元素类型的构造

```\n
- 121\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

/* my solution */
// solution-1, ms, defeat %
// time limited 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                res = max(res, (prices[j] - prices[i]));
            }
        }
        return res;
    }
};

/* better solution */
// solution-2, 12ms, defeat 62.42%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if (prices.empty()) return res;
        
        int min_val = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                // 找出最大利润
                profit = max(profit, prices[i] - min_val);
            else
                // 找出最小值
                min_val = min(min_val, prices[i]);
        }
        
        return profit;
    }
};

/* 一些总结 */
// 1. 题意: 买股票，低价购入，高价卖出，找出最大利润。
//
// 需要注意的点: 
// 1. 还有一种动态规划的做法，但是现在并不懂
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

```\n
- 122\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *122. Best Time to Buy and Sell Stock II
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

/* my solution */
// solution-1, 4ms, defeat 99.75%
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一数组，买卖股票，可以进行多次交易，算出最大利润
// 找出前一天股价低于后一天的这种, 画出股价走势图即可
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

```\n
- 1221\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1221. Split a String in Balanced Strings

Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
Example 4:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
 

Constraints:

1 <= s.length <= 1000
s[i] = 'L' or 'R'
 */

/* my solution */


/* better solution */
class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int balance = 0;
        for (char c : s)
        {
            if (c == 'R') balance++;
            else balance--;
            
            if (balance == 0) res++;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 一组字符串中含有相同数量的'R'和'L', 看这个字符串可以分成几组，每个组中R和L数量相同。
//
// 需要注意的点: 
// 1. R和L的顺序不用管，只有R和L数量相等即可。
// 2. 
// 3. 

```\n
- 125\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 65.92%
// 将除字母和数字外的字符过滤，存入一个新的字符串中，将这个字符串颠倒后，如果和原来的字符串相同，则为true
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char c : s)
        {
            if (isalnum(c))
            {
                if (isupper(c))
                    c = tolower(c);
                str += c;
            }
        }
        
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        
        return str == rev_str;
        
    }
};

/* 一些总结 */
// 1. 题意: 判断一个字符串是否为回文串，但是这个字符串中包含空格
//
// 需要注意的点: 
// 1. `isalpha()`: 判断字符是否为字母
// 2. `isalnum()`: 判断字符是否为数字或字母
// 3. `islower()`: 判断字符是否为小写字母
// 4. `isupper()`: 判断字符是否为大写字母

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

```\n
- 128\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 16ms, defeat 87.08%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int max_val = 1; // 最大连续序列长度
        int cur_val = 1; // 当前连续序列长度
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                    cur_val++;
                else
                {
                    max_val = max(max_val, cur_val);
                    cur_val = 1; // reset
                }
            }
        }
        
        return max(max_val, cur_val);
        
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中的最长连续子序列
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

```\n
- 1281\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1281. Subtract the Product and Sum of Digits of an Integer
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
 

Example 1:

Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 

Constraints:

1 <= n <= 10^5
 */

/* my solution */
// solution-1, 0ms, defeat 100%
// 将数字转化为string,这样好算出每一个数字.
class Solution {
public:
    int subtractProductAndSum(int n) {
        string str = to_string(n);
        int len = str.size();
        vector<int> nums;
        for (int i = 0; i < len; i++) {
            nums.push_back(str[i] - '0');
        }
        
        int product = product_of_each_digit(nums);
        int sum = sum_of_each_digit(nums);
        
        return product - sum;
    }
private:
    int product_of_each_digit(vector<int> vec) {
        int product = 1;
        for (int i : vec) {
            product *= i;
        }
        return product;
    }
    
    int sum_of_each_digit(vector<int> vec) {
        int sum = 0;
        for (int i : vec)
            sum += i;
        return sum;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一整数,算出这个的整数的各位数字,计算出数字的积和数字的和,返回两者的差.
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

```\n
- 129\n
```cpp
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

```\n
- 1299\n
```cpp
/* 1299. Replace Elements with Greatest Element on Right Side
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

/* my solution */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            int max = -1;
            // 找出arr[i]右方最大的数
            for (int j = i + 1; j < len; j++) {
                if (arr[j] > max) max = arr[j];
            }
            arr[i] = max;
        }
        arr[len-1] = -1;
        return arr;
    }
};
/* better solution */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxv = -1, temp;
        for (int i = arr.size() - 1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = maxv;
            maxv = max(maxv, temp);
        }
        return arr;
    }
};
/* 一些总结 */
// 1. c++ max()函数掌握
// 2. 从右向左遍历，因为总是在找右边最大的。
```\n
- 13\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

/* my solution */


/* better solution */
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m{{'I',  1}, {'V',  5}, {'X',  10}, {'L',  50}, 
                          {'C',  100}, {'D',  500}, {'M',  1000}};
        char p = 0; // previous
        int res = 0;
        for (char c : s)
        {
            res += m[c];
            if (p && m[c] > m[p]) // 注意上一个字母存在条件
                res -= (2 * m[p]);
            p = c;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 将罗马数字转换成对应的数字
// 需要总结出一般性规律。
// 需要注意的点: 
// 1.  IV = I + V - 2 * I
// 2.  IX = I + X - 2 * I
// 3. 

```\n
- 1304\n
```cpp
/* Leetcode */
/* 题目信息 */
/* 
 * 1304. Find N Unique Integers Sum up to Zero
 * Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000
*/

/* my solution */
//none

/* better solution */
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        // n is odd
        if (n % 2 != 0) res.push_back(0);
        for (int i = 1; i <= n/2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        return res;
    }
};
/* 一些总结 */
//不用在意数组顺序，最终数组中元素相加为0就行
```\n
- 1305\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */


/* better solution */
// solution1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& num)
    {
        if (!root) return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right, num);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> num1, num2, res;    
        inorder(root1, num1);
        inorder(root2, num2);
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        res.resize(i + j + 2);
        int k = res.size()-1;
        printf("i=%d j=%d k=%d\n", i, j, k);
        
        while (i >= 0 && j >= 0)
        {
            if (num1[i] > num2[j])
            {
                res[k] = num1[i];
                i--;
                k--;
            }
            else
            {
                res[k] = num2[j];
                j--;
                k--;
            }
        }
        
        while (i >= 0)
            res[k--] = num1[i--];
        while (j >= 0)
            res[k--] = num2[j--];
        
        return res;
    }
};
// runtime: 284ms

// solution2
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& num)
    {
        if (!root) return;
        inorder(root->left, num);
        num.push_back(root->val);
        inorder(root->right, num);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;    
        inorder(root1, res);
        inorder(root2, res);
        
        sort(res.begin(), res.end());
        
        return res;
    }
};
// runtime: 284ms

/* 一些总结 */
// 1. vector是可以使用sort()函数的，形式为sort(vector.begin(), vector.end());
// 2. 第一种方式借鉴与88题

```\n
- 1309\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1309. Decrypt String from Alphabet to Integer Mapping

Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"
Example 3:

Input: s = "25#"
Output: "y"
Example 4:

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"
 

Constraints:

1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < s.size();)
        {
            if ((i + 2) < s.size() && s[i + 2] == '#')
            {
                int ss = (s[i] - '0') * 10 + (s[i + 1] - '0');
                res += char(ss + 'a' - 1);
                i += 3;
            }
            else
            {
                res += char(s[i] -'0' + 'a' - 1);
                i++;
            }
        }
        return res;
    }
};

/* 一些总结 */
// 1. 题意: decode, 给定数字串，转换为字符串
// 每三个对比
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 131\n
```cpp
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
/* Type:  backtracking */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 求所有可能解。
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

```\n
- 1324\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1324. Print Words Vertically

Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

 

Example 1:

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"
Example 2:

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"
Example 3:

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    vector<string> printVertically(string s) {
        int words_nums = 0;
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
                continue;
            }
            word += s[i];
        }

        words.push_back(word);
        
        int max_val = 0;
        for (string str : words) {
            max_val = max_val < str.size() ? str.size() : max_val;
        }
        
        vector<string> res(max_val);
        int cnt = 0;
        while (cnt < max_val) {
            for (int i = 0; i < words.size(); i++) {
                if (cnt < words[i].size())
                    res[cnt] += words[i][cnt];
                else
                    res[cnt] += ' ';
            }
            cnt++;
            
        }
        for (string& str : res) {
            erase_space(str);
        }

        return res;
        
    }
private:
    void erase_space(string& temp) {
        int pos = temp.size() - 1;
        for (int i = pos; i >= 0; i--) {
            if (temp[i] != ' ') {
                break;
            }
            pos--;
        }
        temp.erase(pos + 1, temp.size());
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 这道题自己做时极度麻烦,很绕.
// 2. 每一个单词都要检查末尾空格.
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string s = "HOW ARE YOU";
    vector<string> res = solution.printVertically(s);
    cout << res.size();
    

    return 0;
}

```\n
- 1325\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  tree*/
/* 题目信息 */
/*
 *1325. Delete Leaves With a Given Value

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it's parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you can't).

 */

/* my solution */


/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if (!root->left && !root->right && root->val == target)
        {
            root = nullptr;
        }
            
        return root;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 为什么是postorder，写成preorder就错了
// https://blog.csdn.net/qq_43827595/article/details/104262588
// 2. 我们需要删除所有值为 target 的叶子节点，那么我们的操作顺序应当从二叉树的叶子节点开始，逐步向上直到二叉树的根为止
// 3. 常见的二叉树遍历中，后序遍历是先遍历完所有子结点之后再遍历根结点，符合题意
```\n
- 1337\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: array*/
/* 题目信息 */
/*
 *1337. The K Weakest Rows in a Matrix
 Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

 A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

  

 Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
  [1,0,0,0,0],
   [1,1,0,0,0],
    [1,1,1,1,1]], 
    k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
  [1,0,0,0],
   [1,0,0,0]], 
   k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //vector<int> soldiers;
        multimap<int, int> mp;
        for (int i = 0; i < mat.size(); i++)
        {
            int soldiers = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                    break;
                soldiers++;
            }
            mp.insert(pair<int, int> (soldiers, i));
        }
        
        vector<int> res;
        for (auto i = mp.begin(); i != mp.end() && k-- > 0; i++)
            res.push_back(i->second);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. multimap的使用，它可以存入重复的键
// 2. multimap.insert()
// 3. 

```\n
- 1342\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: bit */
/* 题目信息 */
/*
 *1342. Number of Steps to Reduce a Number to Zero
Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 

Example 1:

Input: num = 14
Output: 6
Explanation: 
Step 1) 14 is even; divide by 2 and obtain 7. 
Step 2) 7 is odd; subtract 1 and obtain 6.
Step 3) 6 is even; divide by 2 and obtain 3. 
Step 4) 3 is odd; subtract 1 and obtain 2. 
Step 5) 2 is even; divide by 2 and obtain 1. 
Step 6) 1 is odd; subtract 1 and obtain 0.
Example 2:

Input: num = 8
Output: 4
Explanation: 
Step 1) 8 is even; divide by 2 and obtain 4. 
Step 2) 4 is even; divide by 2 and obtain 2. 
Step 3) 2 is even; divide by 2 and obtain 1. 
Step 4) 1 is odd; subtract 1 and obtain 0.
Example 3:

Input: num = 123
Output: 12
 

Constraints:

0 <= num <= 10^6
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0)
        {
            // num is even
            if (num % 2 == 0)
                num /= 2;
            else
                // odd
                num--;
            step++;
        }
        return step;
        
    }
};

/* better solution */
// solution-2, 0ms, defeat 100%
class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while (num != 0)
        {
            // odd
            if (num & 1)
                num--;
            else
                // even
                num >>= 1;
            step++;
        }
        return step;
        
    }
};

/* 一些总结 */
// 1. 题意: 数步数，如果一个数为偶数，则除以2,若为奇数，则减一，知道最后为0,返回进行了几次。
//
// 需要注意的点: 
// 1. 判断奇偶，num & 1, 与操作，为1则为奇数，为0为偶数。
// 2. 除以2使用>>右移代替
// 3. 

```\n
- 136\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
 */

/* my solution */
// space: O(N) not good
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int res;
        // find out each number's frequency
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump[nums[i]] == 1)
            {
                res = nums[i];
                break;
            }
        }
        
        return res;
    }
};

/* better solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i: nums)
            res = res ^ i;
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 由于加上了时间复杂度必须是 O(n) ，并且空间复杂度为 O(1)的条件，因此不能用排序方法，也不能使用 map 数据结构。
// 2. 
// 3. 

```\n
- 1365\n
```cpp
// 1365. How Many Numbers Are Smaller Than the Current Number
// 
// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
// 
// Return the answer in an array.
// 
// 
// 
// Example 1:
// 
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation:
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1).
// For nums[3]=2 there exist one smaller number than it (1).
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
// Example 2:
// 
// Input: nums = [6,5,4,8]
// Output: [2,1,0,3]
// Example 3:
// 
// Input: nums = [7,7,7,7]
// Output: [0,0,0,0]
// 
// 
// Constraints:
// 
// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100

// better 
// map ✓
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mp;
        vector<int> res;
        
        // find out the number's frequence
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (auto e: mp)
            {
                if (e.first != nums[i] && e.first < nums[i])
                    cnt += e.second;
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};

// 先计算每个值的频数，然后数组进行遍历，在遍历的过程中，将每个数和map中的数进行对比,如果当前值大于map中元素的值，则加上这个元素的频数
```\n
- 137\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *137. Single Number II
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
 */

/* my solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ump;
        int res;
        // find out each number's frequency
        for (auto i: nums)
        {
            ump[i]++;
        }
        
        for (auto i: nums)
        {
            if (ump[i] != 3)
            {
                res = i;
                break;
            }
        }
        
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

```\n
- 1374\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1374. Generate a String With Characters That Have Odd Counts

Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

 

Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"
 

Constraints:

1 <= n <= 500
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string generateTheString(int n) {
        if (n == 0) return "";
        if (n == 1) return "a";
        
        string res = "";
        if (n % 2 == 0) {
            int len1 = 1;
            int len2 = n - 1;
            res += 'a';
            while (res.size() < n)
                res += 'b';
        } else {
            res += 'a';
            res += 'b';
            int len1 = n - 2;
            while (res.size() < n)
                res += 'c';
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 一道简单的字符串问题.
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

```\n
- 1380\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1380. Lucky Numbers in a Matrix
 * Given a m * n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]


Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5.
All elements in the matrix are distinct.
 */

/* my solution */
//none
/* better solution */
class Solution {
    public:
        vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            vector<int> res;
            unordered_set<int> s; // [ 1 ]

            // find out the min of every row
            for (int i = 0; i < matrix.size(); i++) {
                int mn = INT_MAX;  // [ 2 ]
                for (int j = 0; j < matrix[0].size(); j++)
                    mn = min(mn, matrix[i][j]);
                s.insert(mn);  // [4]
            }

            // find out the max of every column
            for (int j = 0; j < matrix[0].size(); j++) {
                int mx = INT_MIN;
                for (int i = 0; i < matrix.size(); i++)
                    mx = max(mx, matrix[i][j]);
                // if find out the mx is already in the unordered_set, the push
                // it into the res vector.
                if (s.find(mx) != s.end()) // [ 3 ]
                    res.push_back(mx);
            }
            return res;
        }
}

/* 一些总结 */

// [1]: c++ unordered_set定义
// [2]: C中常量INT_MAX和INT_MIN分别表示最大、最小整数，定义在头文件limits.h中. INT_MAX = 2^31-1，INT_MIN= -2^31
// [3]: unordered_set::find()函数是C++ STL中的内置函数，用于在容器中搜索元素。它返回元素的迭代器，如果找到其他元素，则返回指向unordered_set::end()的迭代器。
// 用法： unordered_set_name.find(key)
// if(s.find(xx) != s.end()) xxx
// [4]: unordered_set::insert(element)
```\n
- 1382\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1382. Balance a Binary Search Tree
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:
  1                                   2
    \                                /  \
      2                             1    3
        \                                  \
          3                                  4
            \
              4
 */

/* my solution */
// ✓  1396ms
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return helper(nums, 0, nums.size() - 1);
    }
private:
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    TreeNode* helper(vector<int>nums, int L, int R)
    {
        if (L > R) return nullptr;
        int m = L + (R - L) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = helper(nums, L, m - 1);
        root->right = helper(nums, m + 1, R);
        
        return root;
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

```\n
- 1395\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *1395. Count Number of Teams
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
 */

/* my solution */
// brute force
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        // brute force
        int n = rating.size();
        
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (rating[i] < rating[j] && rating[j] < rating[k] || 
                       rating[i] > rating[j] && rating[j] > rating[k])
                        res++;
                }
            }
        }
        
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

```\n
- 1408\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1408. String Matching in an Array
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
 */

/* my solution */
// solution-1, 4ms, defeat 95.77%
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        set<string> st;
        
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (words[i] != words[j])
                {
                    if (words[i].find(words[j]) != string::npos)
                    {
                        st.insert(words[j]);
                    }
                }
            }
        }
        
        for (string s : st)
        {
            res.push_back(s);
        }
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一个字符串数组，找出其中字符串为其他字符串子串的字符串。
//
// 需要注意的点: 
// 1. str.find(str2): 若str2为str的子串，返回str2在str中的下标.
// 2. 注意：有可能之串会重复，需要消除掉重复的字符串。
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

```\n
- 141\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 141. Linked List Cycle
 *
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

3 -> 2 -> 0 -> -4
     ^          |
     |          |
     ------------
 */

/* my solution */
// none

/* better solution */
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
   bool hasCycle(ListNode *head) {
	   if (head == NULL || head->next == NULL)
		   return false;
	   ListNode *fast = head, *slow = head;
	   while (fast && fast->next)
	   {
		   fast = fast->next->next;
		   slow = slow->next;
		   
		   if (fast == slow)
			   return true;
	   }
	   
	   return false;
   }
};

/* 一些总结 */
// [题意]查看链表中有没有环。two pointers, 在操场上慢跑，一个快，一个慢，快的每次两个结点，慢的一个结点，如果有环，肯定会相遇。
```\n
- 1417\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1417. Reformat The String

Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
Example 4:

Input: s = "covid2019"
Output: "c2o0v1i9d"
Example 5:

Input: s = "ab123"
Output: "1a2b3"
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.
 */

/* my solution */
// solution-1, 4ms, defeat 95.92%
class Solution {
public:
    string reformat(string s) {
        // boundary
        if (s.size() == 1)
            return s;
        

        bool is_all_alpha = true;
        bool is_all_digit = true;
        for (char c : s) {
            if (!isalpha(c)) {
                is_all_alpha = false;
                break;
            }
        }
        
        for (char c : s) {
            if (!isdigit(c)) {
                is_all_digit = false;
                break;
            }
        }
        
        if (is_all_alpha || is_all_digit)
            return "";
        


        // ---------------
        int alpha_nums = 0;
        int digit_nums = 0;
        vector<char> digits;
        vector<char> alphas;
        for (char c : s) {
            if (isalpha(c)) {
                alphas.push_back(c);
                alpha_nums++;
            }
            if (isdigit(c)) {
                digits.push_back(c);
                digit_nums++;
            }
        }
        
        string res = "";
        
        if (abs(alpha_nums - digit_nums) >= 2)
            return "";
        else {
            int round = min(alpha_nums, digit_nums);
            if (alpha_nums > digit_nums) {
                for (int i = 0; i < round; i++) {
                    res += alphas[i];
                    res += digits[i];
                }
                res += alphas.back();
            }
            else if (alpha_nums < digit_nums) {
                for (int i = 0; i < round; i++) {
                    res += digits[i];
                    res += alphas[i];
                }
                res += digits.back();
            }
            else{
                for (int i = 0; i < round; i++) {
                    res += digits[i];
                    res += alphas[i];
                }
                
            }
        }
        
        return res;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 隔着输出数字和字母.
//
// 需要注意的点: 
// 1. 条件控制写的确实很麻烦...
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string s = "a0b1c2";
    Solution solution;
    string res = solution.reformat(s);
    cout << res;

    return 0;
}

```\n
- 142\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: linked list */
/* 题目信息 */
/*
 *142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

 

Example 1:
3 → 2 → 0 → -4
    |        |
    ---------
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */

/* my solution */


/* better solution */
// solution 1 : 利用哈希表保存访问过的节点,
// 同时遍历过程中检查哈希表中是否已存在相同的节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mp;
        ListNode* cur = head;
        while (cur)
        {
            if (mp.count(cur))
                return cur;
            mp[cur]++;
            cur = cur->next;
        }
        
        return NULL;
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 一开始使用快慢指针做，但是结果不对，不知道是什么原因?
// 2. 
// 3. 

```\n
- 142.linked-list-cycle-ii\n
```cpp
// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        ListNode* res;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                res = fast;
                break;
            }
        }
        return res;
        //int index = 0;
        //while (head)
        //{
        //    if (head != res)
        //        index++;
        //}
        //return 
        
    }
};
// @lc code=end

```\n
- 1431\n
```cpp
/* 1431. Kids With the Greatest Number of Candies
 * Given the array candies and the integer extraCandies, where candies[i] represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such that he or she can have the greatest number of candies among them. Notice that multiple kids can have the greatest number of candies.



Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]
Explanation:
Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids.
Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Kid 3 has 5 candies and this is already the greatest number of candies among the kids.
Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies.
Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]
Explanation: There is only 1 extra candy, therefore only kid 1 will have the greatest number of candies among the kids regardless of who takes the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]


Constraints:

2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/
```\n
- 1436\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1436. Destination City
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
 */

/* my solution */
// solution-1, 16ms, defeat 95.68%
class Solution {
public:
    string destCity(vector<vector<string> >& paths) {
        bool flag = true;
        map<string, pair<int, int> > mp;
        for (int i = 0; i < paths.size(); i++)
        {
            mp[paths[i][0]].first++;
            mp[paths[i][1]].second++;
        }
        
        for (auto e : mp)
        {
            if (e.second.first == 0 && e.second.second != 0)
                return e.first;
        }
        return "";
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一二维数组，每个元素是包含起始地和目的地的数组，找出终点地是哪一个（只有入，没有出的那个地方）
// 遍历整个元素，以pair<int, int>, first出度，second是入度,最终结果出度为0入度不为0的就是目的地。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 144\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
 */

/* my solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (!root) return res;
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* cur = st.top(); st.pop();
            res.push_back(cur->val);
            if (cur->right) st.push(root->right);
            if (cur->left) st.push(root->left);
        }
        
        return res;
    }
};
// wrong1: nullptr
// 解决: 在35行前添加 if (!cur) continue;
// wrong2: 注意36行中是st.push(cur->right);下一行也是如此。

// ✓ iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* cur = st.top(); st.pop();
            if (!cur) continue;
            res.push_back(cur->val);
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        
        return res;
    }
};

/* better solution */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty())  // 注意这里是while，不是if
        {
            if (cur)
            {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top(); stk.pop();
                cur = cur->right;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 前根遍历迭代写法: 
//   1. 将根结点入栈
//   2. 出栈一个元素，将右结点和左结点依次入栈
//   3. 重复2步骤，即使用一个while循环即可。
```\n
- 1441\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1441. Build an Array With Stack Operations
 *Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

Build the target array using the following operations:

Push: Read a new element from the beginning list, and push it in the array.
Pop: delete the last element of the array.
If the target array is already built, stop reading more elements.
You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.

Return the operations to build the target array.

You are guaranteed that the answer is unique.

 

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: 
Read number 1 and automatically push in the array -> [1]
Read number 2 and automatically push in the array then Pop it -> [1]
Read number 3 and automatically push in the array -> [1,3]
Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: You only need to read the first 2 numbers and stop.
Example 4:

Input: target = [2,3,4], n = 4
Output: ["Push","Pop","Push","Push","Push"]
 

Constraints:

1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target is strictly increasing.
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int curElem = 1;
        for (int i = 0; i < target.size(); i++)  // 对象是target中的数字
        {
            // 对于不存在与target[]中的数字，给予push/pop服务
            while (curElem != target[i])
            {
                res.push_back("Push");
                res.push_back("Pop");
                curElem++;  // important!!!
            }
            res.push_back("Push"); // 在其中的基于push服务
            curElem++;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 对于在target[]中的数字，给予push服务
// 2. 对于不在target[]中的数字，给予push/pop服务
// 3. curNum的自增
```\n
- 1446\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1446. Consecutive Characters
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
 */

/* my solution */
// solution-1, 4ms, defeat 76.29%
class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            char base = s[i];
            int temp = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == base)
                    temp++;
                else
                    break;
            }
            res = max(res, temp);
           
        }
        return res;
        
    }
};

// 上边的代码的一种改进写法,更简洁!
class Solution {
public:
    int maxPower(string s) {
        int count = 0;
        int max_count = 0;
        char previous = ' ';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == previous) {
                count++;
            } else {
                count = 1;
                previous = c;
            }
            max_count = max(max_count, count);
        }
        return max_count;
        
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,找到这个字符串中最长的字符相同的子串
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

```\n
- 1448\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1448. Count Good Nodes in Binary Tree
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Example 1:
                3
              /   \
            1       4
          /        /  \
        3         1    5
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
 */

/* my solution */


/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        
        return cnt;
    }
private:
    void dfs(TreeNode* root, int greatest)
    {
        if (!root) return;
        if (root->val >= greatest) {
            cnt++;
            greatest = root->val;
        }
        dfs(root->left, greatest);
        dfs(root->right, greatest);
    }
};

/* 一些总结 */
// 1. 题意: 
//给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
// 需要注意的点: 
// 1. 需要注意在迭代过程中不断更新greastest.
// 2. 
// 3. 

```\n
- 145\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/* my solution */


/* better solution */
// iterative ✓
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) // 这个是或操作
        {
            if (cur)
            {
                res.push_back(cur->val);
                st.push(cur); // 不要忘记将元素压入栈中
                cur = cur->right;
            }
            else
            {
                cur = st.top(); st.pop();
                cur = cur->left;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 因为后序遍历的压栈顺序是左-右-根，由于先遍历完左子树，然后遍历完右子树，然后才能处理当前节点，为了和之前的代码的结构保持一致，我们可以反向处理，也就是按根-右-左的顺序压栈，结果反向输出即可
// 2. 不要对root这个变量名执迷不悟
// 3. 

```\n
- 1455\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Given a sentence that consists of some words separated by a single space, and a searchWord.

You have to check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).

If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string S is any leading contiguous substring of S.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
Example 4:

Input: sentence = "i use triple pillow", searchWord = "pill"
Output: 4
Example 5:

Input: sentence = "hello from the other side", searchWord = "they"
Output: -1
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string temp = "";
        for (char c : sentence) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        words.push_back(temp);
        // test ok
        //cout << words.size() << " " << words.back() << endl;
        
        int res = -1;
        int cnt = 1;
        
        for (string str : words) {
            if (str.find(searchWord) != str.npos) {
                // 检查searchWord是否为str的前缀
                int prefix = str.find(searchWord);
                if (prefix == 0) {
                    res = cnt;
                    break;
                }
            }
            cnt++;
        }
        
        return res;
    }
};

// 上边代码第86到93行代码更加精简的写法
//        for (string str : words) {
//            if (str.find(searchWord) == 0)
//                res = cnt;
//            cnt++;
//        }

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一字符串str1,还有另一个字符串str2,检查str2是否为str1中某个词的前缀.
//
// 需要注意的点: 
// 1. str.find(str2)的用法
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

```\n
- 1464\n
```cpp
/* 1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

/* mine's solution */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            // attention to the 'j = i + 1'
            // the i and j are two different indics
            // i and j is equal to j and i, switching them is meaningless.
            for (int j = i + 1;  j < nums.size(); j++) {
                int temp = (nums[i] - 1) * (nums[j] - 1);
                if (temp > max) max = temp;
            }
        }
        return max;
    }
};

// 题解: 在数组中任选两个不同的下标，找出其对应的数组值相乘后的最大值。
// 注: 两个下标是不同的，写循环时一定要注意。

/* better solution */
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort() default ascending
        int len = nums.size();
        return (nums[len-1] - 1) * (nums[len-2] - 1);
    }
};
*/
// 先将数组中的数字排序，最高的两个数一定在数组的最后两位，再进行相乘，这样就不必使用循环了。
// 解法1是104ms, 解法2是12ms
```\n
- 1469\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1469. 寻找所有的独生节点
二叉树中，如果一个节点是其父节点的唯一子节点，则称这样的节点为 “独生节点” 。二叉树的根节点不会是独生节点，因为它没有父节点。

给定一棵二叉树的根节点 root ，返回树中 所有的独生节点的值所构成的数组 。数组的顺序 不限 。

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        dfs(root, res);
        return res;
    }
private:    
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;
        
        if (root->left && root->right) {
            dfs(root->left, res);
            dfs(root->right, res);
        } else if (root->left || root->right) {
            TreeNode* remaining = root->left ? root->left : root->right;
            res.push_back(remaining->val);
            dfs(remaining, res);
        } else
            return;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 重点在于有无父结点
// 2. 太长时间没有做树方面的题目了，有些不熟悉。
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

```\n
- 147\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: linked list */
/* 题目信息 */
/*
 *147. Insertion Sort List
Sort a linked list using insertion sort.
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
 */

/* my solution */
// solution-1, 116ms, defeat 8.84%
// 将链表转化为数组，然后使用插入排序，再转化为链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        insertionSort(nums);
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        
        for (int i = 0; i < nums.size(); i++)
        {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return dummy->next;
        
    }
private:    
    void insertionSort(vector<int>& R)
    {
        int temp;
        for (int i = 1; i < R.size(); i++)
        {
            temp = R[i];
            int j = i - 1;
            while (j >= 0 && temp < R[j])
            {
                R[j + 1] = R[j];
                j--;
            }
            R[j + 1] = temp;
        }
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1470\n
```cpp
/* 1470. Shuffle the Array

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].



Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]


Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
*/


//class Solution {
//public:
//    vector<int> shuffle(vector<int>& nums, int n) {
//        vector<int> a[n], b[n];
//        for (int i = 0; i < n; i++) {
//            a[i] = nums[i];
//            b[i] = nums[i+n];
//        }
//        int ai = 0, bi = 0
//        for (i = 0; i < 2n; i += 2) {
//            nums[i] = a[ai];
//            nums[i+1] = b[bi];
//            ai++;
//            bi++;
//        }
//        
//    }
//};

// 我的思路：将nums分成两个长度为n的ventor，然后就重新赋值，一个接一个，但是编译报错。
// 看了一个别人解析的，非常简单，使用了vector的push_back()方法
//
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
        }
        return res;
    }
};
```\n
- 1475\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1475. Final Prices With a Special Discount in a Shop
 * Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.



Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]


Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 10^3
 */

/* my solution */
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size() - 1; i++) {
            // 最后一个元素不用考虑
            // 1. 找出i右侧最近小于price[i]的数
            printf("i=%d prices[i]=%d\n", i, prices[i]);
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
            printf("----");
            printf("i=%d prices[i]=%d\n", i, prices[i]);
        }
        return prices;
    }
};
/* better solution */
//none
/* 一些总结 */
// 最后一个元素不用考虑
```\n
- 148.sort-list\n
```cpp
/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

/* algorithms	Medium (42.78%)	3000	140
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        vector<int> nums;
        to_vector(head, nums);
        sort(nums.begin(), nums.end());
        ListNode* yummy = new ListNode(-1);
        ListNode* cur = yummy;
        for (int i : nums)
        {
            cur->next = new ListNode(i);
            cur = cur->next;
        }

        return yummy->next;
    }
private:
    void to_vector(ListNode* head, vector<int>& nums)
    {
        if (!head) return;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }
};
// @lc code=end

```\n
- 1480\n
```cpp
// 1480. Running Sum of 1d Array
// 
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// 
// Return the running sum of nums.
// 
// 
// 
// Example 1:
// 
// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:
// 
// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
// Example 3:
// 
// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]
// 
// 
// Constraints:
// 
// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6
//
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        int sum[len];
        //sum[len] = {0};
        int whole = 0;
        for (int i = 0; i < len; i++) {
            sum[i] = nums[i] + whole;
            whole += nums[i];
        }
        for (int i = 0; i < len; i++) {
            nums[i] = sum[i];
        }
        return nums;
    }
};


// 1.
// 这是从新算了一个新的数组，将每次算的sum存入新数组中，再循环将对应的数字赋值给nums
//

// better choice

//class Solution {
//public:
//    vector<int> runningSum(vector<int>& nums) {
//        int i = 1;
//        while (i < nums.size()) {
//            nums[i] += nums[i-1];
//            i++;
//        }
//        return nums;
//    }
//};
```\n
- 1491\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 1491. Average Salary Excluding the Minimum and Maximum Salary
 * Given an array of unique integers salary where salary[i] is the salary of the employee i.

Return the average salary of employees excluding the minimum and maximum salary.



Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500
Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000
Example 3:

Input: salary = [6000,5000,4000,3000,2000,1000]
Output: 3500.00000
Example 4:

Input: salary = [8000,9000,2000,3000,6000,1000]
Output: 4750.00000


Constraints:

3 <= salary.length <= 100
10^3 <= salary[i] <= 10^6
salary[i] is unique.
Answers within 10^-5 of the actual value will be accepted as correct.
 */

/* my solution */
class Solution {
public:
    double average(vector<int>& salary) {
        int len = salary.size();
        // 1. sort
        sort(salary.begin(), salary.end());
        // 2. calculate result
        double sum = 0.0;
        for (int i = 1; i < len - 1; i++) {
            sum += salary[i];
        }
        return sum / (len-2);
    }
};
/* better solution */
// none

/* 一些总结 */
// 注意数组的索引情况，本题并不难，但是确实花了较长时间
```\n
- 15\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointers */
/* 题目信息 */
/*
 *15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0)
            return res;
        
        for (int k = 0; k < nums.size(); k++)
        {
            //
            if (k > 0 && nums[k] == nums[k- 1]) continue;
            int target = 0 - nums[k];
            int l = k + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] == target)
                {
                    res.push_back({nums[k], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[r])  // 避免重复情况
                        l++;
                    while (r > l && nums[r] == nums[r-1]) // 避免重复情况
                        r--;
                    l++, r--;
                }
                else if (nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
            
        }
        
        return res;
    }
};
/* 一些总结 */
// 1. 题意: 求在数组中三个数之和为给定值的组合。
//
// 需要注意的点: 
// 1. 求三数之和转变为求两数之和。
// 2. 先选择一个数，在去求另外两个数。
// 3. 

```\n
- 150\n
```cpp
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
/* Type: stack */
/* 题目信息 */
/*
 *150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 */

/* my solution */
// solution-1, 16ms, defeat 81.55%
// ✓
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string c : tokens)
        {
            //char c = c0[0];
            if (atoi(c.c_str()) || c == "0")
                stk.push(atoi(c.c_str()));
                //stk.push(atoi(c.c_str()) - '0');
                //stk.push(c - '0');
            else
            {
                int a1 = stk.top(); stk.pop();
                int a2 = stk.top(); stk.pop();
                if (c == "+")
                    stk.push(a1 + a2);
                else if (c == "-")
                    stk.push(a2 - a1);
                else if (c == "*")
                    stk.push(a1 * a2);
                else
                    stk.push(a2 / a1);
            }
        }
        
        return stk.top();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 逆波兰求解表达式
//
// 需要注意的点: 
// 1.
// 因为vector中存储的是string,一开始想要使用isdigit()进行判断，但是这个函数的参数需要是字符，所有使用了atoi()进行转换
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    //vector<string> input = { "2", "1", "+", "3", "*" };
    //vector<string> input = {"4","13","5","/","+"};
    vector<string> input = {"0", "3", "/"};
    int res = solution.evalRPN(input);
    cout << res;

    return 0;
}

```\n
- 1502\n
```cpp
/* 1502. Can Make Arithmetic Progression From Sequence
 * Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.



Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


Constraints:

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6
*/

/* mine's solution */
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // 1. sort
        sort(arr.begin(), arr.end());
        // 2. 对比相邻两个元素的差值是否相同
        int compare_val = arr[1] - arr[0];
        printf("%d\n", compare_val);
        for (int i = 1; i < arr.size() - 1; i++) {
            //for (int j = i + 1; j < arr.size(); j++) {
            int j = i + 1;
            printf("i=%d, j=%d, 差值=%d\n", i, j, arr[j] - arr[i]);
            if (arr[j] - arr[i] != compare_val) return false;
            //}
        }
        return true;
    }
};

/* better solution */
// 下面这段可以改成这样的
        for (int i = 2; i < arr.size() - 1; i++) {
            if (arr[i] - arr[i-1] != compare_val) 
                return false;
        }
```\n
- 151\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-1, 8ms, defeat 50%
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        // remove begining and end space
        while (s[0] == ' ')
            s.erase(s.begin());
        while (s.back() == ' ')
            s.erase(s.size() - 1);
        
        vector<string> vec;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                vec.push_back(temp);
                temp = "";
                continue;
            }
            temp += c;
        }
        vec.push_back(temp);
        
        reverse(vec.begin(), vec.end());
        string res = "";
        for (string str : vec) {
            if (str == "") // important
                continue;  // remove middle space
            res += str;
            res += ' ';
        }
        res.erase(res.size() - 1);
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,翻转字符串中的单词.
//
// 需要注意的点: 
// 1. 字符串前后的空格要删去,但是词与词中间的多个空格不能删去.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input = "a good   example";
    string res = solution.reverseWords(input);
    cout << res;

    return 0;
}

```\n
- 1512\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1512. Number of Good Pairs
Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 */

/* my solution */
// 1. 枚举，看有多少对数字相同，然后返回。
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    cnt++;
        }
        
        return cnt;
    }
};

// 2. 计算出每个数字的数组，则每个数字可以组成(n * (n - 1)) / 2对
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> freq;
        int cnt = 0;
        // find out every number's frequency
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        for (auto e: freq)
        {
            if (e.second != 1)  // exclude the frequency == 1's number
                cnt += (e.second * (e.second - 1)) / 2;
        }
        
        return cnt;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
// 2. 解决: 计算每个数字的频数，然后使用n(n-1) / 2
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 152\n
```cpp
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
/* Type: dp */
/* 题目信息 */
/*
 *152. Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

/* my solution */
// solution-x, ms, defeat %
// brute force
// time limited
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = i ; j < nums.size(); j++) {
                product *= nums[j];
                res = max(res, product);
            }
        }
        
        return res;
    }
};

/* better solution */
// solution-x, 8ms, defeat 70.47%
// 这种解法还未看懂
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int curMax = nums[0];
        int curMin = nums[0];
        int maxProduct = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int p1 = curMax * nums[i];
            int p2 = curMin * nums[i];
            
            curMax = max(nums[i], max(p1, p2));
            curMin = min(nums[i], min(p1, p2));
            
            maxProduct = max(maxProduct, curMax);
        }
        return maxProduct;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，返回这个数组中连续数字乘积的最大值。
//
// 需要注意的点: 
// 1. kadane's algo
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    vector<int> input = {2,3,-2,4};
    int res = solution.maxProduct(input);
    cout << res;

    return 0;
}

```\n
- 1528\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1528. Shuffle String
Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
Example 3:

Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"
Example 4:

Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"
Example 5:

Input: s = "art", indices = [1,0,2]
Output: "rat"
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).
 */

/* my solution */
// solution-1, 8ms, defeat 93.22%
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = indices.size();
        vector<char> store_chars(len);
        //string res(len);
        
        for (int i = 0; i < len; i++) {
            int index = indices[i];
            store_chars[index] = s[i];
        }
        
        string res;
        for (char c : store_chars)
            res += c;
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串和一个索引数组，返回字符串根据索引的正确字符串。
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

    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    string res = solution.restoreString(s, indices);
    cout << res;
    

    return 0;
}

```\n
- 155\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: stack */
/* 题目信息 */
/*
 *155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.
 */

/* my solution */


/* better solution */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (min_stk.empty() || x < min_stk.top())
            min_stk.push(x);
        else
            min_stk.push(min_stk.top());
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
private:    
    stack<int> stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/* 一些总结 */
// 1. 题意: 将栈加入取最小指功能
// 2. 解决: 使用一个辅助栈, 存入每次压栈的最小值，也就是说，辅助栈中元素从栈底到栈顶是递减的。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1556\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1556. Thousand Separator
Given an integer n, add a dot (".") as the thousands separator and return it in string format.

 

Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"
Example 3:

Input: n = 123456789
Output: "123.456.789"
Example 4:

Input: n = 0
Output: "0"
 

Constraints:

0 <= n < 2^31
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string thousandSeparator(int n) {
        string num = to_string(n);
        int len = num.size();
        if (len <= 3)
            return num;
        else {
            int cnt = 1;
            for (int i = len - 1; i >= 0; i--) {
                if (cnt % 3 == 0 && cnt != len)
                    num.insert(i, 1, '.');
                cnt++;
            }
        }
        return num;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 基本字符串操作.
//
// 需要注意的点: 
// 1. string.insert操作
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

```\n
- 1572\n
```cpp
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
/* Type: array */

/* 题目信息 */
/*
 *1572. Matrix Diagonal Sum
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5
 

Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100
 */

/* my solution */
// solution-1, 20ms, defeat 99.25%
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        int len = mat[0].size();
        for (int i = 0; i < len; i++) {
            res += mat[i][i];
            res += mat[i][len - i - 1];
        }
        if (len % 2 == 1)
            res -= mat[len/2][len/2];
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 计算矩阵对角线和斜对角线上元素的和.
//
// 需要注意的点: 
// 1. 很容易的一道题目.
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

```\n
- 160\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:   a1 -> a2 
              \
               c1 -> c2 -> c3
              /
B: b1->b2->b3

begin to intersect at node c1.

 

Example 1:

A:   4 -> 1 
              \
               8 -> 4 -> 5
              /
B: 5->6->1

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Each value on each linked list is in the range [1, 10^9].
Your code should preferably run in O(n) time and use only O(1) memory.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int countA = 0, countB = 0;
        
        // compute len of list A
        while (curA)
        {
            curA = curA->next;
            countA++;
        }
        
        // compute len of list B
        while (curB)
        {
            curB = curB->next;
            countB++;
        }
        
        // find out the longer one 
        int diff = abs(countA - countB);
        if (countB > countA)
            swap(headA, headB);
        
        while (diff--)
        {
            headA = headA->next;
        }
        
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

// 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *p = headA, *q = headB;
        while (p || q)
        {
            if (!p) p = headB;
            if (!q) q = headA;
            if (p == q) return p;
            p = p->next; // 这句前面为什么不能加上if (p->next)
            q = q->next;
        }
        
        return nullptr;
    }
};
// 由于链表一长一短，当链表A先到结尾时，让其指向B的开头，如果B先到达结尾，则指向A的开头。这样当有相遇的地方时，两个指针走过的行程是一样的。

/* 一些总结 */
// 1. [题意]寻找两个链表相同部分的第一个结点。two pointers, 计算两个的长度，让指针向前走，是当前长度相同，当两个指针相同时，返回即可
// 2. the diff should be positive

```\n
- 1614\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1614. Maximum Nesting Depth of the Parentheses
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int maxDepth(string s) {
        int a = s.size();
        int res = 0, maxVal = 0;
        for (int i = 0; i < a; i++)
        {
            if (s[i] == '(')
                res++;
            else if (s[i] == ')')
                res--;
            
            maxVal = max(maxVal, res);
        }
        
        return maxVal;
        
    }
};

/* 一些总结 */
// 1. 题意: 给定一字符串，寻找字符串中括号的最深层数
// 维护一个最大值和层数，层数遇左括号加1,遇右括号减1,在遍历整个字符串中不断更新最大值，最终结果返回最大值。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1624\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1624. Largest Substring Between Two Equal Characters
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
Example 4:

Input: s = "cabbac"
Output: 4
Explanation: The optimal substring here is "abba". Other non-optimal substrings include "bb" and "".
 

Constraints:

1 <= s.length <= 300
s contains only lowercase English letters.
 */

/* my solution */
// solution-1, 28ms, defeat 51.90%
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        
        for (int i = 0; i < s.size() - 1; i++) {
            char base = s[i];
            int count = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] != base)
                    count++;
                else if (s[j] == base) {
                    res = max(res, count);
                    count++; // 注意这里!例如字符串s中有多个字符t,当遍历完t后,还要将当前t计入count,以期待遇到下一次t时更新.
                }
            }
        }
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串,找到相同字符之间的最长子串长度.
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

```\n
- 1636\n
```cpp
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
/* Type: array */
/* 题目信息 */
/*
 *1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        
        vector<pair<int, int>> vec;
        for (auto e : mp) {
            vec.push_back({e.first, e.second});
        }
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> res;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].second; j++) {
                res.push_back(vec[i].first);
            }
        }
        return res;
        
    }
private:
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 多值排序问题
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

```\n
- 1662\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *1662. Check If Two String Arrays are Equivalent
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
 */

/* my solution */
// solution-1, 8ms, defeat 46.70%
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        
        for (string str : word1)
            str1 += str;
        for (string str : word2)
            str2 += str;
        
        return str1 == str2;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定两个字符串数组，看两个数组中的字符串分别合起来是否是相同的。
// 很简单的一道题目，遍历生成最终字符串然后对比返回。
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

```\n
- 1669\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1669. Merge In Between Linked Lists
 */

/* my solution */
// solution-x, ms, defeat %
 // Definition for singly-linked list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur = new ListNode(-1);
        ListNode* cur1 = list1;
        int len1 = 0;
        
        ListNode* last = new ListNode(-1);
        while (cur1) {
            len1++;
            cur1 = cur1->next;
            if (len1 == b)
                last->next = cur1->next;
        }
        
        int cnt = 0;
        cur = list1;
        while (cur) {
            if (cnt == a - 1) {
                cur->next = list2;
            }
            cnt++;
            
            if (cur->next == NULL) // 使cur指向第二个链表末端
                break;
            cur = cur->next;
        }
        cur->next = last->next;
        
        return list1;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 截取链表并粘连链表
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
    return 0;
}

```\n
- 167\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *167. Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000
 */

/* my solution */
// hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> ump;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
            ump[numbers[i]] = i;
        for (int i = 0; i < numbers.size(); i++)
        {
            int complement = target - numbers[i];
            if (ump.count(complement) && ump[complement] != i)
            {
                res.push_back(i+1);
                res.push_back(ump[complement]+1);
                return res;
            }
        }
        
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

```\n
- 1672\n
```cpp
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
/* Type: very easy */
/* 题目信息 */
/*
 *1672. Richest Customer Wealth
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

 

Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
Example 3:

Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
 

Constraints:

m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // compute each line
        vector<int> money;
        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            money.push_back(sum);
        }
        sort(money.begin(), money.end());
        return money.back();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 计算二维矩阵中每一行的和.
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

```\n
- 1678\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %

class Solution {
public:
    string interpret(string command) {
        map<string, string> mp;
        mp["G"] = "G";
        mp["()"] = "o";
        mp["(al)"] = "al";
        
        string temp = "";
        string res = "";
        for (char c : command) {
            if (!mp.count(temp))
                temp += c;

            if (mp.count(temp)) { // 一开始我的这个代码段写成了上一个
                                  // if 的else块,但是结果是错误的.
                res += mp[temp];
                temp = "";
            }
        }
        
        return res;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 一个映射的设置.
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
    string command = "G()(al)";
    Solution solution;
    string res = solution.interpret(command);
    cout << res;



    return 0;
}

```\n
- 1684\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1684. Count the Number of Consistent Strings
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> mp;
        // record allowed's characters' freq
        for (char c : allowed) {
            mp[c]++;
        }
        
        int res = 0;
        for (string str : words) {
            set<char> s;
            bool flag = true;
            for (char c : str) {
                s.insert(c);
            }
            
            for (char c : s) {
                if (!mp.count(c)) {
                    flag = false;
                    break;
                }
                    
            }
            if (flag)
                res++;
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意:
// 给定一标准字符串,字符唯一,再给定一个字符串数组,字符不唯一,找到这个字符串数组中的字符串中有字符和标准字符串中的字符一样的字符串个数.
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

```\n
- 1689\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9
 

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
 */

/* my solution */
// solution-1, 52ms, defeat 52.96%
class Solution {
public:
    int minPartitions(string n) {
        int res = 0;
        for (char c : n) {
            res = max(res, (c-'0'));
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
// 因为需要最少的1和0组成的数字,所以元素首部都得是1,
// 找到字符串中最大的那个数,就需要多少个首部为1的元素.
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

```\n
- 169\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
 */

/* my solution */
// solution-1, 44ms, defeat 62.39%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // record each element's freq
        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        
        int n = nums.size();
        for (auto e : mp)
        {
            if (e.second > n / 2)
                return e.first;
        }
        
        return -1;
    }
};


// more precies
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // record each element's freq
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i : nums)
        {
            if (++mp[i] > n / 2)
                return i;
        }
        
        return -1;
    }
};
/* better solution */
// solution-2, 72ms, defeat %
// 因为给定数组中肯定有某个数字的频次大于n/2，所以在给数组排序后，数组中间的数字肯定就是我们想要的数字。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中频次大于n/2的数字
// 使用map算出每个数字的频次
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 1694\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-1, ms, defeat %
class Solution {
public:
    string reformatNumber(string number) {
        string temp1 = "";
        for (char c : number) {
            if (c == ' ' || c == '-')
                continue;
            temp1 += c;
        }
        cout << temp1 << endl;
        
        string res = "";
        int remainder = temp1.size() % 3;
        int groups = 0;
        if (remainder == 1) 
            groups = temp1.size() / 3 - 1;
        else
            groups = temp1.size() / 3;
        
        for (int group = 0; group < groups; group++) {
            int idx = 0;
            while (idx < 3) {
                res += temp1[3 * group + idx];
                idx++;
            }
            
            res += '-';
        }
        if (remainder == 1) {
            res += temp1.substr(temp1.size() - 4, 2);
            res += '-';
            res += temp1.substr(temp1.size() - 2, 2);
        }
        else
            res += temp1.substr(temp1.size() - remainder, temp1.size());
        
        // 抹除掉结尾多余的'-'
        if (res.back() == '-')
            res.erase(res.size()-1);

        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 字符串的一些简单操作.
//
// 需要注意的点: 
// 1. substr(position, n); // n: 代表n个字符
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input = "123 4-567";
    string res = solution.reformatNumber(input);
    cout << res;

    return 0;
}

```\n
- 171\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *171. Excel Sheet Column Number
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int n = s.size();
        int cnt = n - 1;
        for (char c : s)
        {
            
            res += (c - 'A' + 1) * pow(26, cnt);
            cnt--;
        }
        
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 进制转换问题
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 


```\n
- 172\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Follow up: Could you write a solution that works in logarithmic time complexity?

 

Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0
 

Constraints:

1 <= n <= 104
 */

/* my solution */
// solution-1, ms, defeat %
// runtime error
// class Solution {
// public:
//     int trailingZeroes(int n) {
//         int res = 1;
//         while (n > 0)
//         {
//             res = (res * n--);
//         }
//         
//         string str = to_string(res);
//         int zeros = 0;
//         for (int i = str.size() - 1; i >= 0; i--)
//         {
//             if (str[i] == '0')
//                 zeros++;
//             else
//                 break;
//         }
//         
//         return zeros;
//         
//     }
// };

/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 5)
        {
            n /= 5;
            res += n;
        }
        
        return res;
        
    }
};

/* 一些总结 */
// 1. 题意: 算出一个数的阶乘后，算出这个数字尾部有多少0
//
// 需要注意的点: 
// 1. 2*5 = 10 → 5的个数比2多的多 → 得出有多少5这个因子
// 2. 例如10有2个5：5, 10
// 3. 15有3个5：5, 10, 15

/*
 * main test
 */

int main(void)
{
    Solution solution;
    int input = 4;
    int res = solution.trailingZeroes(input);
    cout << res;

    return 0;
}

```\n
- 179\n
```cpp
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
/* Type: sort */
/* 题目信息 */
/*
 *179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
Example 3:

Input: nums = [1]
Output: "1"
Example 4:

Input: nums = [10]
Output: "10"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 4ms, defeat 98.59%
// 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < num.size(); i++)
            if (nums[i] == 0)
                x++;
        if (x == nums.size()) return "0";
        
        vector<string> s(nums.size(), ""); // 使用数组存储string这一步，是很关键的, 因为需要对字符串进行排序!
        for (int i = 0; i < nums.size(); i++)
            s[i] = to_string(nums[i]);
        
        sort(s.begin(), s.end(), cmp);
        
        string res = "";
        for (int i = 0; i < s.size(); i++)
            res += s[i];
        
        return res;
        
    }
private:
    bool cmp(string &s1, string &s2) {
        return (s1 + s2) > (s2 + s1);
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，返回由数组中的数字所组成的最大的字符串。
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

```\n
- 189\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0
Accepted
519,212
Submissions
1,491,833
 */

/* my solution */


/* better solution */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> newNums(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            newNums[(i + k) % nums.size()] = nums[i];
        }
        
        // copy to the original vector
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = newNums[i];
        }
    }
};

/* 一些总结 */
// 1. 题意: 
// 旋转k次数组，每次动一个元素。
// 需要注意的点: 
// 1. 使用新的元素存储旋转后的元素，再将元素复制回原数组。
// 2. 
// 3. 

```\n
- 19\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
 */

/* my solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        int len = computeLen(head);
        int processNum = len - n - 1;
        printf("%d\n", processNum);
        ListNode* cur = head;
        while (processNum--)
        {
            cur = cur->next;
        }
        printf("%d \n", cur->val);
        cur->next = cur->next->next;
        
        return head;
    }
private:
    int computeLen(ListNode* head)
    {
        if (!head) return 0;
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
};
// 不知道问题在哪？提交说有nullptr

/* better solution */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        int len = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        int processNum = len - n;
        cur = dummy; // 这个赋值很重要，不要赋值为head,这样当链表中只有一个元素，而这个元素就是要被删除的时候会很有用
        while (processNum--)
            cur = cur->next;
        cur->next = cur->next->next;
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 必须要注意只有一个元素的链表的情况
// 2. 
// 3. 

```\n
- 191\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: bit manipulation  */
/* 题目信息 */
/*
 *191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above, the input represents the signed integer. -3.
Follow up: If this function is called many times, how would you optimize it?

 

Example 1:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            cnt++;
        }
        
        return cnt;
    }
};

/* 一些总结 */
// 1. 题意: 算出整数中1的个数
// 一个技巧: n & (n-1)可以消除n中的最后一个1
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

```\n
- 199\n
```cpp
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

```\n
- 2\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        int carry = 0; 
        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            cur->next = new ListNode(sum);
            cur = cur->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
            cur->next = new ListNode(carry);
        
        return head->next;
    }
};

// 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        int carry = 0;
        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            tail->next = new ListNode(sum);
            tail = tail->next;
            
            //if (l1) l1 = l1->next;
            //if (l2) l2 = l2->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry)
            tail->next = new ListNode(carry);
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. dummy head
// 2. l1 = l1 ? l1->next : nullptr;
```\n
- 20\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
//            if (stk.empty()) stk.push(s[i]);
            if (!stk.empty() && ((stk.top() == '(' && s[i] == ')') || \
                (stk.top() == '{' && s[i] == '}') || \
                (stk.top() == '[' && s[i] == ']')))
            {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }

        if (stk.empty())
            return true;
        return false;

    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 判断(){}[]是否匹配
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
    string input = "()";
    bool res = solution.isValid(input);
    cout << res;

    return 0;
}

```\n
- 201\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: bitwise */
/* 题目信息 */
/*
 *201. Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
 */

/* my solution */
// solution-x, ms, defeat %
// brute force
// time limited
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = m; i <= n; i++)
            m &= i;
        return m;
    }
};

/* better solution */
// solution-x, 0ms, defeat 100%
// bitwise
// 找到m和n的公共部分
// 例如26-30
// 26: 11010
// 27: 11011
// 28: 11100
// 29: 11101
// 30: 11110
// 找到相同的部分即11
// 然后在左移
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n)
        {
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        return n << count;
    }
};

/* 一些总结 */
// 1. 题意: 求m和n之间（包括m和n）所有数的与操作并返回。
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 202\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *202. Happy Number
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */

/* my solution */
// solution-x, ms, defeat %
/*
class Solution {
public:
    bool isHappy(int n) {
        int res = sum_digit_square(n);
        int cnt = 0;
        while (res != 1)
        {
            cnt++;
            cout << "running..." << cnt << endl;
            res = sum_digit_square(res);
            if (res == 1)
                return true;
                
        }
        
        return true;
    }
private:
    int sum_digit_square(int num)
    {
        int sum = 0;
        while (num)
        {
            int remainder = num % 10;
            num /= 10;
            sum += remainder * remainder;
        }
        return sum;
    }
};

*/

// 上边这种做法是错误的, 因为如果陷入死循环后，就只能一直死循环下去，但是
// 不知道进入死循环的条件是什么？
// 下面找到一个例子 from leetcodeAnimation
// 我们先举一个例子

// 输入： 59
// 1. 5^2 + 9^2 = 106
// 2. 1^2 + 0^2 + 6^2 = 37
// 3. 3^2 + 7^2 = 58
// 4. 5^2 + 8^2 = 89
// 5. 8^2 + 9^2 = 145
// 6. 1^2 + 4^2 + 5^2 = 42
// 7. 4^2 + 2^2 = 20
// 8. 2^2 + 0^2 = 4
// 9. 4^2 = 16
// 10. 1^2 + 6^2 = 37
// 
// 这个例子，我们可以看到输入59，第10步的结果和第2步一样，一直进行计算的话，会死循环，所以这个数肯定不会是快乐树。

/* better solution */
// solution-2, 0ms, defeat 100%
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int res = sum_digit_square(n);
        s.insert(res);
        while (res != 1)
        {
            res = sum_digit_square(res);
            if (s.count(res)) return false;
            s.insert(res);
        }
        
        return true;;
    }
private:
    int sum_digit_square(int num)
    {
        int sum = 0;
        while (num)
        {
            int remainder = num % 10;
            num /= 10;
            sum += remainder * remainder;
        }
        return sum;
    }
};

/* 一些总结 */
// 1. 题意: 寻找快乐数。
//
// 需要注意的点: 
// 1. 关键点在于如何判断死循环。使用一个set，在求解过程中如果发现求出了同样的数字，则是进入死循环的标志
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    int input = 2;
    bool res = solution.isHappy(input);
    cout << res;

    return 0;
}

```\n
- 203\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *203. Remove Linked List Elements
 Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
 */

/* my solution */
// none

/* better solution */
// 不好理解
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head)
        {
            ListNode* p = head;
            while (p->next)
            {
                if (val == p->next->val)
                    p->next = p->next->next;
                else
                    p = p->next;
            }
            if (head->val == val)
                head = head->next;
        }
        
        return head;
    }
};

// better better
// 这种更好
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        ListNode* yummy = new ListNode(-1);
        yummy->next = head;
        ListNode* cur = yummy;
        // 1. 头结点是val如何处理?
        while (cur->next)
        {
            
            if (cur->next->val == val)
            {
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        ListNode* resNode = yummy->next;
        
        return resNode;
    }
};
/* 一些总结 */
// 1. 记录在链表中行动的cur是需要cur = cur->next;的
// 2. delete yummy的操作
// 3. 判断当前结点的下一个结点是否为空!

```\n
- 204\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 10^6
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
// class Solution {
// public:
//     int countPrimes(int n) {
//         int res = 0;
//         for (int k = 0; k < n; k++)
//             if (isPrime(k))
//             {
//                 res++;
//             }
//         return res;
//         
//     }
// private:
//     bool isPrime(int i)
//     {
//         if (i < 2) return false;
//         for (int j = 2; j <= sqrt(i); j++)
//         {
//             if (i % j == 0 && i != j)
//                 return false;
//         }
//         return true;
//     }
// };

/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;
        vector<bool> primes(n, true);
        primes[0] = false, primes[1] = false;
        for (int i = 0; i < sqrt(n); i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j+=i)
                {
                    primes[j] = false;
                }
            }
        }
        
        return count(primes.begin(), primes.end(), true);
        
    }
};

/* 一些总结 */
// 1. 题意: 计算小于n的区间中有多少prime number
//
// 需要注意的点: 
// 1. Sieve of Eratosthenes: algorithm steps for primes
// 2. 暴力操作会超时
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

```\n
- 206\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 206. Reverse Linked List
 *Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/* my solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 头插法
        ListNode* newHead = new ListNode(0);
        ListNode* node;
        while (head)
        {
            node = head;
            head = head->next;
            
            node->next = newHead->next;
            newHead->next = node;
            

        }
        
        return newHead->next;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
// 反转链表
// 需要注意的点: 
// 1. 头插法
// 2. 
// 3. 

```\n
- 21\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */

/* my solution */
// none

/* better solution */
// solution 1:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *res = head;
        
        while (l1 || l2)
        {
            if (!l2)
            {
                head->next = l1;
                break; // 注意这里的break不要忘记!!!
            } 
            else if (!l1)
            {
                head->next = l2;
                break;// 注意这里的break不要忘记!!!
            }
            
            else if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else 
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        return res->next;
    }
};

// solution 1.1 
// 第一种方法的精简
// 每次都将指针指向值较小的结点
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while (l1 && l2)
        {
            if (l1->val > l2->val) swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};


// 2 recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val)
        {
            newHead = l1;
            l1->next = mergeTwoLists(l1->next, l2);
            //printLinkedList(newHead);
        }
        else
        {
            newHead = l2;
            l2->next = mergeTwoLists(l1, l2->next);
            //printLinkedList(newHead);
        }
        //printLinkedList(newHead);
        return newHead;
    }
};

/* 一些总结 */


```\n
- 215\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

/* my solution */
// solution-1, 12ms, defeat 97.02%
// 先排序，在倒序，然后输出num[k-1]
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

/* better solution */
// solution-2, 20ms, defeat %
// min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq; // min heap
        for (int i : nums)
        {
            if (pq.size() < k)
                pq.push(i);
            else 
            {
                if (i > pq.top())
                {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        
        return pq.top();
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. min heap,
// 当size为k时，再插入元素时，比较top元素和当前元素大小，如果当前元素较大，则pop掉top元素，当前元素进堆，这样min heap里的元素就是整个序列的前k大元素，而top元素又是这前k大元素中最小的，此时返回top元素即可。
// 2. 
// 3. 

```\n
- 217\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
 */

/* my solution */
// solution-1, 60ms, defeat 75.13%
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // record each number's freq
        unordered_map<int, int> ump;
        for (int i : nums)
        {
            if (++ump[i] >= 2)
                return true;
        }
        return false;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 如果给定数组中有重复数字，返回true
// 使用map记录频次
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 222\n
```cpp
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

```\n
- 224\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *224. Basic Calculator
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.

 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 94.73%
class Solution {
public:
    int calculate(string s) {
        stack<int> stk, op;
        int res = 0;
        int sign = 1;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                double num = c - '0';
                // 数字位数大于1,需要将字符串转换成为数字
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                res += num * sign;
            }
            else if (c == '+')
                sign = 1;
            else if (c == '-')
                sign = -1;
            else if (c == '(') {
                stk.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res = res * op.top(); op.pop();
                res += stk.top(); stk.pop();
            }
        }
        return (int)res;
        
    }
};

/* 一些总结 */
// 1. 题意: 对字符串表达式求值
//
// 需要注意的点: 
// 1. 括号那一步需要加强理解。
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    string input =  "(1+(4+5+2)-3)+(6+8)";
    int res = solution.calculate(input);
    cout << res << endl;

    return 0;
}

```\n
- 226\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *226. Invert Binary Tree
 Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        // 注意这一句，我之前写成swap(root->left->val, root->right->val);
        // 但是这种左右的孩子就没有交换过来，注意注意。
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

/* 一些总结 */
// 注意这一句，我之前写成swap(root->left->val, root->right->val);
// 但是这种左右的孩子就没有交换过来，注意注意。
```\n
- 23\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: linked list */
/* 题目信息 */
/*
 * 23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
 */

/* my solution */


/* better solution */
// solution 1 ✓:
// 将几个链表中元素的值导入到新的数组中，将数组排序，然后生成新的链表，返回即可。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            
            ListNode* first = lists[i];
            while (first)
            {
                nums.push_back(first->val);
                first = first->next;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        for (int i = 0; i < nums.size(); i++)
        {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};

// solution 2: priority queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* first = lists[i];
            while (first)
            {
                pq.push(first->val);
                first = first->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        while (!pq.empty())
        {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        
        return dummy->next;
    }
};

// solution 3: use merge two sorted list
// divide and conquer
class solution {
public:
    listnode* mergeklists(vector<listnode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
        
    }
private:
    listnode* merge(vector<listnode*>& lists, int l, int r)
    {
        
        if (l > r) return nullptr;
        if (l == r) return lists[l]; // 注意这一句
        if (l + 1 == r) return mergetwosortedlists(lists[l], lists[r]); // 注意这一句
        int m = l + (r - l) / 2;
        listnode* l1 = merge(lists, l, m);
        listnode* l2 = merge(lists, m + 1, r);
        return mergetwosortedlists(l1, l2);
    }
    listnode* mergetwosortedlists(listnode* l1, listnode* l2)
    {
        listnode* dummy = new listnode(-1);
        listnode* tail = dummy;
        
        while (l1 && l2)
        {
            if (l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 多个输入，一个输出，类似漏斗，可以使用小顶堆
// 2. 
// 3. 

```\n
- 230\n
```cpp
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
 *230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 */

/* my solution */
// solution-1, 28ms, defeat 39.50%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        to_sorted_array(root, nums);
        
        int res = -1;
        res = nums[k - 1];
        
        return res;
    }
private:
    void to_sorted_array(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        if (root->left)
            to_sorted_array(root->left, nums);
        nums.push_back(root->val);
        if (root->right)
            to_sorted_array(root->right, nums);
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找出给定BST中第k小的数字，k从1开始。
// 先使用中序遍历得到有序数组，然后取值即可。
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

```\n
- 234\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
 */

/* my solution */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = overturn(head);
        vector<int> origin, overturned;
        toVector(head, origin);
        toVector(newHead, overturned);
        
        return origin == overturned;
    }
private:
    void toVector(ListNode* head, vector<int>& v)
    {
        if (!head) return;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    ListNode* overturn(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode* yummy = new ListNode(-1);
        //yummy->next = head;
        while (head)
        {
            ListNode* inserted = new ListNode(head->val);
            inserted->next = yummy->next;
            yummy->next = inserted;
            head = head->next;
        }
        
        return yummy->next;
    }
};

// 将原来的链表和翻转的链表导入数组中进行对比。

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) 
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        
        ListNode* pre = NULL;
        ListNode* cur = slow;
        ListNode* next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        while (pre)
        {
            if (pre->val != head->val)
                return false;
            pre = pre->next;
            head = head->next;
        }
        
        return true;
    }
};

/* 一些总结 */


```\n
- 235\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 *
 *                       6
 *                     /   \
 *                   2      8
 *                 /  \    /  \
 *               0     4  7    9
 *                  /  \
 *                3    5
 *
 *  Example 1:
 *
 *  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 *  Output: 6
 *  Explanation: The LCA of nodes 2 and 8 is 6.
 */

/* my solution */
// none

/* better solution */
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parentVal = root->val;
        int pVal = p->val;
        int qVal = q->val;
        if (pVal > parentVal && qVal > parentVal)
            return lowestCommonAncestor(root->right, p, q);
        else if (pVal < parentVal && qVal < parentVal)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

/* 一些总结 */
// [题意]找到两个结点的挨着最近的父亲。画图，三种不同的情况，递归写出来的代码很好理解。
// 难点: 当p和q的值都大于根结点值或者都小于根结点值的时候，应该如何缩小范围，这里的缩小范围就是对根结点右子树或者左子树进行递归操作，写出这个并不难，但是想出这个还是有些费时的。
```\n
- 236\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Tree */
/* 题目信息 */
/*
 *236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
                   3
                 /   \
                5    1
             /  \    /  \
           6    2   0   8
               / \
             7   4
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
 */

/* my solution */


/* better solution */
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果我们找到了p，直接进行返回，那如果下面就是q呢？ 其实这没有影响，但是还是要多考虑一下
        if (!root || root == p || root == q) 
            return root;
        root->left = lowestCommonAncestor(root->left, p, q); // 去左边找，期待返回找到的结点
        root->right = lowestCommonAncestor(root->right, p, q);// 去右边找，期待返回找到的结点
        if (!root->left) // left subtree isn't exist, return right
            return root->right;
        if (!root->right)  // right subtree isn't exist, return left
            return root->left;
        return root;  // 左右子树分别有一个，则返回root
    }
};

/* 一些总结 */
// 1. 题意: 二叉树的最近公共祖先(236)
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 237\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 237. Delete Node in a Linked List
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
 */

/* my solution */
// none
/* better solution */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};

/* 一些总结 */
// 1. 令一个临时变量tmp,将被删除的结点的下一个结点赋值给tmp，然后将tmp的信息赋值给node，最后删除tmp.
```\n
- 238\n
```cpp
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
/* Type: array */
/* 题目信息 */
/*
 *238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> res;
//         
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int temp_product = 1;
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (i != j)
//                     temp_product *= nums[j];
//             }
//             res.push_back(temp_product);
//         }
//         
//         return res;
//     }
// };
// 
/* better solution */
// solution-1, 40ms, defeat 52.43%
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        // 第一次循环，每个位置存放i之前所有元素的乘积
        for (int i = 0, temp = 1; i < nums.size(); i++)
        {
            res[i] = temp;
            temp *= nums[i];
        }
        
        // 第二次循环，从后往前，每个位置和i之后的元素再次相乘
        for (int i = nums.size() - 1, temp = 1; i >= 0; i--)
        {
            res[i] *= temp;
            temp *= nums[i];
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
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

```\n
- 239\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: sliding window */
/* 题目信息 */
/*
 *239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 348ms, defeat 47.19%
// monotonic queue(单调队列)
// 1. 队列里存放的是索引吗? 确实是，存放的是数组下标。为什么要这样，为什么不直接存值?
// 2. 总是维护最大值在deque的最左端
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        vector<int> res;
        deque<int> q; // only indexes are stored
        for (int i = 0; i < nums.size(); i++)
        {
            // 当当前元素下标与deque头部下标之差>=k时，清除头部
            // 因为是滑动窗口！能够遮盖的元素是一定的。
            while (!q.empty() && (i - q.front()) >= k)
                q.pop_front();
            // 若当前q不空且当前元素大于q尾部元素，循环清除尾部元素
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            // 当滑动窗口刚满时，将首部元素推入结果中
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 24\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 */

/* my solution */


/* better solution */
// iterative 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevNode = dummy;
        
        while (head && head->next)
        {
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;
            
            // swap
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            
            prevNode = firstNode;
            head = firstNode->next;
        }
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 自己手动模拟即可
// 2. 
// 3. 

```\n
- 242\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 */

/* my solution */
// solution-1, 64ms, defeat 24.69%
// 给两个字符串排序，然后比较即可, 当然也可以使用hash table记录每个字符的频次
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 查看给定的两个字符串是不是构成回文
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 257\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 257. Binary Tree Paths
 * Given a binary tree, return all root-to-leaf paths.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Input:
 *
 *    1
 *     /   \
 *     2     3
 *      \
 *        5
 *
 *        Output: ["1->2->5", "1->3"]
 *
 *        Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */

/* my solution */
// ✓
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        
        return res;
    }
private:
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        if (!root) return;
        string s_val = to_string(root->val);
        if (!root->left && !root->right)
        {
            path += s_val;
            res.push_back(path);
        }
        else
            path += (s_val + "->");
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }
};

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<string>& res, string t)
    {
        if (!root) return;
        // 1. root
        if (!t.empty())
            t += ("->" + to_string(root->val));
        else
            t = to_string(root->val);
        // 2. left
        if (root->left)
            preorder(root->left, res, t);
        // 3. right
        if (root->right)
            preorder(root->right, res, t);
        // leaf
        if (!root->left && !root->right)
            res.push_back(t);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root)
            preorder(root, res, "");
        
        return res;
    }
};

/* 一些总结 */
// 1. 第一种方法更好，容易理解。

```\n
- 26\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *26. Remove Duplicates from Sorted Array
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
 

Constraints:

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 68ms, defeat 19.75%
// 使用另一个数组保存结果，最后再赋值到原数组。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.empty())
            {
                temp.push_back(nums[i]);
                continue;
            }
            
            if (temp.back() == nums[i])
            {
                continue;
            }
            else
            {
                temp.push_back(nums[i]);
                cout << nums[i] << endl;
            }
        }
        nums.erase(nums.begin(), nums.end());
        for (int i = 0; i < temp.size(); i++)
            nums.push_back(temp[i]);
        return nums.size();
    }
};

/* 一些总结 */
// 1. 题意: 去除数组中的重复元素，保持元素的唯一。
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 268\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *268. Missing Number

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 */

/* my solution */
// solution-1, 56ms, defeat 20.02%
// sort
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt++ != nums[i])
                return nums[i] - 1;
        }
        return nums.size();
    }
};

// solution-2
// set
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> s;
        for (int i : nums)
        {
            s.insert(i);
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.count(i))
                return i;
        }
        return nums.size();
        
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找出给定数组中缺失的那个数字
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

```\n
- 27\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:array  */
/* 题目信息 */
/*
 *27. Remove Element

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length. For example if you return 2 with nums = [2,2,3,3] or nums = [2,3,0,0], your answer will be accepted.
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]
Explanation: Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4. Note that the order of those five elements can be arbitrary. It doesn't matter what values are set beyond the returned length.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
 */

/* my solution */
// solution-1, 4ms, defeat 64.03%
// 使用另一个数组存入结果，然后赋值回原数组。
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
                temp.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.end());
        for (int i = 0; i < temp.size(); i++)
        {
            nums.push_back(temp[i]);
        }
        return nums.size();
        
    }
};

/* better solution */
// solution-2, 4ms, defeat %
// two pointers
// 当nums[r] != val时，r++;
// 当nums[r] == val时，l++, r++;
// 长度为l

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] != val)
            {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};

/* 一些总结 */
// 1. 题意: 给定数字val和数组，去除数组中和val相等的数字。
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 278\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: binary search */
/* 题目信息 */
/*
 *278. First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
 */

/* my solution */
// time limited
// 以线性扫描超时
class Solution {
public:
    int firstBadVersion(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isBadVersion(i) == true)
            {
                res = i;
                break;
            }
        }
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

```\n
- 283\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */

/* my solution */


/* better solution */
// 下边这种做法并没有用到in-place算法，只是另外用了一个数组，虽然通过，但并不适合。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        
        // find out the non-zero and the push it to res
        for (int i = 0; i < len; i++)
        {
            if (nums[i] != 0)
                res.push_back(nums[i]);
        }
        printf("res's size = %d\n", res.size());
        // find out the zero's freq
        int zeros = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 0)
                zeros++;
        }
        printf("zeros = %d\n", zeros);
        // push 0 to res
        while (zeros--)
            res.push_back(0);
        // res to nums
        for (int i = 0; i < len; i++)
        {
            nums[i] = res[i];
        }
        
    }
};


// 符合题意的in-place解法 better
// ✓
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 当前元素不为0,则将当前元素值赋值给最后的0元素位置
            if (nums[i] != 0)
                nums[lastNonZeroFoundAt++] = nums[i];
        }
        
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 如果没有返回类型的话，代表要在原数组上修改，但是在过程中可以新开一个数组存储，最后在赋值回去。
// 2. 
// 3. 

```\n
- 287\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *287. Find the Duplicate Number
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 */

/* my solution */
// solution-1, 32ms, defeat 11.16%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums)
        {
            if (++mp[i] > 1)
                return i;
        }
        
        return -1;
    }
};

/* better solution */
// solution-2, 20ms, defeat 42.77%
// sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                res = nums[i];
                break;
            }
        }
        
        return res;
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 还可以使用binary search和two pointers做，还没有尝试
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

```\n
- 290\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
 */

/* my solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                vec.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        vec.push_back(temp);
        
        // ok
        //cout << vec.size() << endl;
        
        if (pattern.size() != vec.size())
            return false;
            
        map<char, string> mp;
        bool flag1 = true;
        bool flag2 = true;
        int cnt = 0;
        for (char c : pattern) {
            if (!mp.count(c)) {
                mp[c] = vec[cnt++];
            } else {
                if (mp[c] != vec[cnt++]) 
                    flag1 = false;
            }
        }
       
        int cnt2 = 0;
        map<string, char> mp2;
        for (string str : vec) {
            if (!mp2.count(str))
                mp2[str] = pattern[cnt2];
            else {
                if (mp2[str] != pattern[cnt2])
                    flag2 = false;
            }
            cnt2++;
        }
        
        cout << flag1 << " :" << flag2 << endl;
        return flag1 && flag2;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 根据模式匹配字符串
//
// 需要注意的点: 
// 1. 不仅值是唯一,键也是唯一的,所以这里我使用了两个map
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string pattern = "abba"; 
    string s = "dog cat cat dog";
    Solution solution;
    bool res = solution.wordPattern(pattern, s);
    cout << res;

    return 0;
}

```\n
- 295\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *
295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 1. 先把数据插入maxHeap
        maxHeap.push(num);
        // 2. 把maxHeap的最大值拿出来插入minHeap
        // 保证minHeap最小的值都是maxHeap中最大的
        int x = maxHeap.top(); maxHeap.pop();
        minHeap.push(x);
        //
        if (maxHeap.size() < minHeap.size())
        {
            int y = minHeap.top(); minHeap.pop();
            maxHeap.push(y);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) * 0.5;
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/* 一些总结 */
// 1. 题意: 在动态数据流中找到中位数。
// 使用两个堆，首先将数据流分成两部分，左边使用max heap存储，右边使用min
// heap存储，左边最大的值小于右边最小的值，保证两个堆的大小不超过1.
// 需要注意的点: 
// 1. 一个数据流，让找出中位数。对于数据流这种动态（流动）的数据，如果使用数组存储，那么每次新进来一个数据都进行排序的话，效率很低。处理动态数据来说一般使用的数据结构是栈、队列、二叉树、堆。
// 2. 
// 3. 

```\n
- 3\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: sliding window */
/* 题目信息 */
/*
 *3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 40ms, defeat 51.61%
// sliding window + map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int start = 0;
        
        map<char, int> mp; // 记录字符出现位置
        
        for (int i = 0; i < n; i++)
        {
            char c = s[i]; // 当前字符
            if (mp.count(c)) // 若当前字符出现过
            {
                start = max(start, mp[c] + 1); // 则start置为重复字符地址+1, 即滑动窗口左边索引右移一位
            }
            res = max(res, i - start + 1);
            mp[c] = i;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 寻找字符串中的最长无重复子串
//
// 需要注意的点: 
// 1. 手动模拟自然可以知道line 65是什么意思
// 2. 
// 3. 

```\n
- 322\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res;
        map<int, int> mp;
        for (int i : coins)
            mp[i]++;
        
        int remaining;
        if (coins.back() <= amount) {
            remaining = amount % coins.back();
            res += amount / coins.back();
        }
        if (mp.count(remaining))
            res += 1;
        
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = solution.coinChange(coins, amount);
    cout << res;

    return 0;
}

```\n
- 326\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *326. Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you do it without using any loop / recursion?
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 90.89%
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        
        while (n % 3 == 0)
            n /= 3;
        
        return n == 1;
        
    }
};

/* 一些总结 */
// 1. 题意: 检查一个数字是否为3的幂次
//
// n = 3^x
// n = 3 * 3 * 3 * 3 * 3 * ... * 3;
// 不断循环除以3,查看最终数字是否为1,循环条件为n%3 != 0
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

```\n
- 328\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 

Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        
        return head;
    }
};

/* 一些总结 */
// 1. 第一个想法是构造两个链表，一个存放奇数，一个存放偶数，构造完毕之后，再将两个连接起来。
// 确实是这样做的，但是题目中的第二个样例没有看懂。
// 2. 按照这个写法，是奇数和偶数间隔出现，需要将前边放奇数，后边放偶数，这样的意思，但是题目中并没有这样的东西，很迷。
```\n
- 33.search-in-rotated-sorted-array\n
```cpp
/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
    }
};
// @lc code=end

```\n
- 338\n
```cpp
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
/* Type: bit */
/* 题目信息 */
/*
 *338. Counting Bits
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */

/* my solution */
// solution-1, 44ms, defeat 5.32%
// so slow
class Solution1 {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            res.push_back(compute_one_nums(i));
        } 
        return res;
    }
private:
    int compute_one_nums(int num) {
        string num_to_bin = dec_to_bin(num);
        int one_nums = 0;
        for (char c : num_to_bin) {
            if (c == '1')
                one_nums++;
        }
        return one_nums;
    }
    
    string dec_to_bin(int num) {
        string res = "";
        while (num) {
            int remainder = num % 2;
            res += (remainder + '0');
            num /= 2;
        }
        // 省略了一个reverse字符串过程,但是这个二进制串的顺序和结果并不相关,省去也没事.
        return res;
    }
};

/* better solution */
// solution-2, 8ms, defeat 68.55%
// 位操作
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};

// i&(i-1) res[14] = res[12] + 1, 总是隔着一个数字
// 0, 1, 10, 11, 110, 111, 1110, 1111
// 0, +1, skip, +1, ...

/* 一些总结 */
// 1. 题意: 给定一整数n,计算从0到n(包括n)之内的二进制数的1的个数.
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

```\n
- 34\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: binary search */
/* 题目信息 */
/*
 *34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
 */

/* my solution */
// not O(logn)
// but AC
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first_position = -1, last_position = -1;
        // from left to right
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                first_position = i;
                break;
            }
        }
        // from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                last_position = i;
                break;
            }
        }
        
        return {first_position, last_position};
    }
};

/* better solution */
// binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int leftIdx = binarySearch(nums, target, true);
        if (leftIdx == nums.size() || nums[leftIdx] != target)
            return res;
        res[0] = leftIdx;
        res[1] = binarySearch(nums, target, false) - 1;
        
        return res;
    }
private:
    int binarySearch(vector<int> nums, int target, bool left)
    {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target || (left && target == nums[mid]))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

/* 一些总结 */
// 1. 题意: 给出一个值，求出它在给定数组中第一次和最后一次出现的位置。
//
// 需要注意的点: 
// 1. 第二种方法暂时还写不出来，特别是这个left置为bool类型的写法。
// 2. 二分查找很不简单!!!细节很难把握，思路很清晰
// 3. 

// a comment: Usually when you are given a sorted data structure and are asked
// for a log(n) algo, 90% of the time its binary search. Just like when you are
// given a tree, 90% of the time you use recursion with dfs or bfs.
```\n
- 344\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */

/* my solution */
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

/* better solution */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);
    }
};

/* 一些总结 */
// 1. 题意: 
//[题意]翻转字符串。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 347\n
```cpp
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
/* Type: hash table */
/* 题目信息 */
/*
 *347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
 */

/* my solution */
// solution-1, 36ms, defeat 39.93%
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        // record each number's freq
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        
        vector<pair<int, int> > vec;
        for (auto e : mp)
        {
            vec.push_back({e.first, e.second});
        }
        
        sort(vec.begin(), vec.end(), compare);
        
        for (int i = 0; i < k; i++)
            res.push_back(vec[i].first);
        
        return res;
        
    }
private:
    static bool compare(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一数字，找到前k个频次最高的数字。
// 先使用map得到每个数字的频次，然后根据频次排序，最后输出前k个即可。
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

```\n
- 349\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *349. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s_std;
        for (int i = 0; i < nums1.size(); i++)
            s_std.insert(nums1[i]);
        set<int> s_compare;
        for (int i = 0; i < nums2.size(); i++)
            s_compare.insert(nums2[i]);
        
        for (auto e : s_compare)
            if (s_std.find(e) != s_std.end())
                res.push_back(e);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 找到两个数组中相同的元素，以数组形式返回。
// 2. 解决: 使用set对两个数组分别去重，然后遍历其中一个set，看另一个set中是否存在，存在则加入结果中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 35\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: binary search */
/* 题目信息 */
/*
 *35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
 */

/* my solution */


/* better solution */
// binary search ✓
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1])
            return nums.size();
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意第一个if条件语句，如果目标是大于所有的元素的话，就返回数组长度
// 2. 
// 3. 

```\n
- 350\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> mp1; // record each number's freq
        map<int, int> mp2;
        for (auto i : nums1)
            mp1[i]++;
        for (auto i : nums2)
            mp2[i]++;
        
        for (auto e : mp1)
        {
            if (mp2.find(e.first) != mp2.end())
            {
                int cnt = min(e.second, mp2[e.first]);
                for (int i = 0; i < cnt; i++)
                    res.push_back(e.first);
            }
            
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 找出两个数组中相同的数，即使数重复也要返回
// 2. 对两个数组中每个数字分别记频次，然后遍历其中一个map，对另一个map作比较，有则计算此数最低频次，根据这个最低频次添加进入结果中。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 371\n
```cpp
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
/* Type: bit manipulation */
/* 题目信息 */
/*
 *371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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

```\n
- 378\n
```cpp
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
/* Type: heap */
/* 题目信息 */
/*
 *378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
 */

/* my solution */
// solution-1, 88ms, defeat 60.61%
// 没有使用heap，新建一个数组存入matrix中所有的元素，然后排序，返回第k项
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                nums.push_back(matrix[i][j]);
        }
        
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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

```\n
- 38\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: string  */
/* 题目信息 */
/*
 *38. Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
 */

/* my solution */


/* better solution */
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; // base case
        string prevRes = countAndSay(n - 1);
        int count = 1; // count
        string res;
        for (int i = 0; i < prevRes.size(); i++)
        {
            if (prevRes[i] == prevRes[i + 1]) // find out the same number's freq
            {
                count++;
                continue;
            }
            else
            {
                if (prevRes[i] != prevRes[i + 1])
                {
                    res += to_string(count) + prevRes[i];
                    count = 1; // reset
                }
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 报数
//
// 需要注意的点: 
// 1. 后一个是对前一个的报数
// 2. 不理解在下边手动模拟一遍就可以看懂了
// 3. 
// 模拟
// 1 → "1"
// 2 → "1" 个"1" → "11"
// 3 → "2" 个"1" → "21"
// 4 → "1" 个"2" "1"个"1" → "1211"

```\n
- 383\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 * 383. Ransom Note
 *Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for (char c : magazine)
            mp[c]++;
        
        bool res = true;
        for (char c : ransomNote) {
            if (mp[c] > 0) {
                mp[c]--;
            } else {
                res = false;
            }
        }
        return res;
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定str1和str2,检查str2所提供的字符是否可以组成str1
//
// 需要注意的点: 
// 1. 在这道题中我错用了map.count(c),
// 我认为如果一个map中,某个字符的频次为0后,这个count结果返回就是0,但是这个只是map检查它自己中是否有这个键,和这个键的频次是没有关系的.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    string ransomNote = "aa"; 
    string magazine = "ab";
    Solution solution;
    bool res = solution.canConstruct(ransomNote, magazine);
    cout << res;

    return 0;
}

```\n
- 384\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *384. Shuffle an Array
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls will be made to reset and shuffle.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 152ms, defeat 35.70%
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i : nums) {
            nums_first.push_back(i);
            nums_copy.push_back(i);
        }
        //return nums_first;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(nums_first.begin(), nums_first.end(), std::default_random_engine(seed));
        return nums_first;
    }
private:
    vector<int> nums_copy;
    vector<int> nums_first;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/* 一些总结 */
// 1. 题意: 实现两个函数，一个重置数组函数，一个洗牌数组函数
//
// 需要注意的点: 
// 1. std::shuffle
// 2. std::array
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

```\n
- 387\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 */

/* my solution */
// solution-1, 156ms, defeat 18.43%
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找到给定字符串中第一个频次为1的字符索引。
// 先算出每个字符的频次，然后遍历字符串每个字符，查看该字符频次是否为1
// 需要注意的点: 
// 1. 只找第一个频次为1的字符
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

```\n
- 389\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *389. Find the Difference
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
Example 3:

Input: s = "a", t = "aa"
Output: "a"
Example 4:

Input: s = "ae", t = "aea"
Output: "a"
 

Constraints:

0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lower-case English letters.
 */

/* my solution */
// solution-1, 8ms, defeat 35.09%
class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mps;
        // map for s
        for (char c : s) {
            mps[c]++;
        }
        // map for t
        map<char, int> mpt;
        for (char c : t) {
            mpt[c]++;
        }
        
        for (char c : t) {
            if (!mps[c])
                return c;
            if (mps[c] != mpt[c])
                return c;
        }
        return NULL;
    }
};

// 上边的代码更新一下,不必有两个map结构的

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> mps;
        // map for s
        for (char c : s) {
            mps[c]++;
        }
        
        for (char c : t) {
            if (!mps[c])
                return c;
            mps[c]--; // 如果多出来的那个字母是相同的,就次数减一次
        }
        return NULL;
    }
};
/* better solution */
// solution-2, 8ms, defeat 35.09%
// sort
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        // sort
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // compare
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i])
                return t[i];
        }
        
        return t.back();
    }
};
// solution-3, 4ms, defeat 73.18%
// xor method
// 找只出现一次的字符
class Solution3 {
public:
    char findTheDifference(string s, string t) {
        char x = 0;
        string mix = s + t;
        for (char c : mix)
            x ^= c;
        return x;
        
    }
};
/* 一些总结 */
// 1. 题意: 给定两个字符串s和t, 找出t和s中多出的那个字母.
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

```\n
- 4\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *4. Median of Two Sorted Arrays(media: 中位数)
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 */

/* my solution */
// solution-1, 56ms, 31.5%
// brute force
// 1. 将nums2中元素加入nums1中
// 2. sort nums1
// 3. 求出中间元素
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge nums2's elements to nums1
        for (int i : nums2)
        {
            nums1.push_back(i);
        }
        // sort
        sort(nums1.begin(), nums1.end());
        
        int n = nums1.size();
        int left = n / 2;
        
        
        // even
        if (n % 2 == 0) 
            return (double(nums1[left] + nums1[left-1]) / 2);
        
        return nums1[left];
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 应该是可以使用二分法的
// 2. 
// 3. 

```\n
- 404\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 404. Sum of Left Leaves
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 *            3
 *           / \
 *          9  20
 *             /  \
 *            15   7
 *
 *                 There are two left leaves in the binary tree, with values 9
 *                 and 15 respectively. Return 24.
 */

/* my solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void preorder(TreeNode* root)
    {
        if (root)
        {
            if (root->left)
                if (!root->left->left && !root->left->right)
                    sum += root->left->val;
            preorder(root->left);
            preorder(root->right);
        }
        else
            return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        preorder(root);
        
        return sum;
    }
};

/* better solution */

/* 一些总结 */
// 1. 本题不难，按照题目字面逻辑即可。

```\n
- 412\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;

/* Leetcode */
/* Type: string  */
/* 题目信息 */
/*
 *412. Fizz Buzz
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 != 0)
                res.push_back("Fizz");
            else if (i % 3 != 0 && i % 5 == 0)
                res.push_back("Buzz");
            else if (i % 3 == 0 && i % 5 == 0)
                res.push_back("FizzBuzz");
            else
            {
                //char x = i + '0';
                //string str = "";
                //str += x;
                res.push_back(to_string(i));
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. to_string的用法要掌握
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

```\n
- 415\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: String */
/* 题目信息 */
/*
 *415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/* my solution */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0)
        {
            if (i >= 0)
            {
                carry = (num1[i] - '0') + carry;
                i--;
            }
            if (j >= 0)
            {
                carry = (num2[j] - '0') + carry;
                j--;
            }
            
            res = to_string(carry % 10) + res;
            carry /= 10;
        }
        
        return res;
    }
};

/* better solution */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int x1 = (i >= 0 ? num1[i] - '0' : 0);
            int x2 = (j >= 0 ? num2[j] - '0' : 0);
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res += to_string(value);
            i--;
            j--;
        }
        
        if (carry != 0)
            res += to_string(carry);
        reverse(res.begin(), res.end());
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. int to string，注意加上to_string()，它不会自动转换。
// 2. 下边这种方法更易于理解。
// 3. 

```\n
- 42\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: two pointers */
/* 题目信息 */
/*
 *42. Trapping Rain Water
 */

/* my solution */


/* better solution */
// two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n == 0) return 0;
        int l = 0;
        int r = n - 1;
        // max_l与max_r是两块板子在挡水
        int max_l = height[l];
        int max_r = height[r];
        int res = 0;
        
        while (l < r)
        {
            if (max_l < max_r)
            {
                res += max_l - height[l];
                max_l = max(max_l, height[++l]);
            }
            else
            {
                res += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 43\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 * 43. Multiply Strings
 *Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 71.16%
// 双层遍历, 难点是乘积的处理
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) // 遍历num1的每一位数字
        {
            for (int j = num2.size() - 1; j >= 0; j--) // 遍历num2的每一位数字
            {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); //当前位加上乘积
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        
        // 去除开头的0
        int i = 0;
        while (i < num.size() && num[i] == 0) i++;
        
        // vector -> string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0'); // 注意这里的i++,不要掉了
        return res;
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 437\n
```cpp
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int self = helper(root, sum);
        int L = helper(root->left, sum);
        int R = helper(root->right, sum);
        
        return L + R + self;
    }
private:
    int helper(TreeNode* root, int sum)
    {
        if (!root) return 0;
        int self;
        if (root->val == sum)
            self = 1;
        else 
            self = 0;
        int L = helper(root->left, sum - root->val);
        int R = helper(root->right, sum - root->val);
        
        return L + R + self;
    }
    
};

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
// 2. 这道题总是做不好，不知道为什么?
// 3. 

```\n
- 438\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: sliding window */
/* 题目信息 */
/*
 *438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 20ms, defeat 69.85%
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int l = p.size(); // window size
        vector<int> res;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0); // 使用vector当hashtable
        
        for (char c : p) vp[c - 'a']++;
        for (int i = 0; i < n; i++)
        {
            // 索引大于window size
            if (i >= l)
                vs[s[i - l] - 'a']--; // 移除窗口最左边元素
            // 更新窗口, 加入当前元素
            vs[s[i] - 'a']++;
            
            // 如果vs == vp, 推入当前滑动窗口最左元素下标
            if (vs == vp) res.push_back(i + 1 - l);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 给定字符串s,和字符串p，在s中寻找与p相同的子串，顺序不管。
// 使用滑动窗口和hashtable, 每次找寻到相同的vector,就推入滑动窗口最左元素下标
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 443\n
```cpp
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
#include <unordered_map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
Example 4:

Input: chars = ["a","a","a","b","b","a","a"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","3","b","2","a","2"].
Explanation: The groups are "aaa", "bb", and "aa". This compresses to "a3b2a2". Note that each group is independent even if two groups have the same character.
 

Constraints:

1 <= chars.length <= 2000
chars[i] is a lower-case English letter, upper-case English letter, digit, or symbol.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int compress(vector<char>& chars) {
        unordered_map<string, int> mp;
        for (char c : chars)
            mp[to_string(c)]++;
        
        vector<string> res;
        for (auto entry : mp) {
            res.push_back(entry.first);
            string num = to_string(entry.second);
            int num_len = num.size();
            if (num_len == 1 && (num[0] - '0') == 1)
                continue;
            else if (num_len > 2) {
                for (char c : num)
                    res.push_back(to_string(c));
            }
        }
        return res.size();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 这个题目有问题,传输的参数是vector<char> ,但是样例中是vector<string>类型的.
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    vector<char>  chars = { "a","a","b","b","c","c","c" };
    Solution solution;
    int res = solution.compress(chars);
    cout << res;

    return 0;
}

```\n
- 445\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        
        ListNode* Temp = new ListNode(0);
        Temp->next = nullptr;
        int carry = 0, num1 = 0, num2 = 0;
        
        while (!s1.empty() || !s2.empty() || carry)
        {
            if (!s1.empty())
            {
                num1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                num2 = s2.top();
                s2.pop();
            }
            
            int sum = num1 + num2 + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            num1 = 0;
            num2 = 0;
            
            ListNode* newNode = new ListNode(value);
            newNode->next = Temp->next;
            Temp->next = newNode;
        }
        
        return Temp->next;
        
    }
};

/* 一些总结 */
// 1. 头插法
// 2. 可能更习惯将carry拿到最后写的写法
// 注意本题中两个链表长度可能是不一样的
```\n
- 448\n
```cpp
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
/* Type: array */
/* 题目信息 */
/*
 *448. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

/* my solution */
// solution-1, 312ms, defeat 5.63%
// 使用set存入nums元素
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        set<int> s;
        for (int i : nums)
            s.insert(i);
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!s.count(i + 1))
                res.push_back(i + 1);
        }
        
        return res;
    }
};

/* better solution */
// solution-2, 96ms, defeat 73.61%
// 因为有重复的
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> results;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        
        // A positive element means that the element (index + 1) does not appear in the array, so save it
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                results.push_back(i + 1);
        
        return results;
    }
};

/* 一些总结 */
// 1. 题意: 找到给定数组中缺失的元素
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

```\n
- 45\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: greedy */
/* 题目信息 */
/*
 *
 */

/* my solution */


/* better solution */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxReachPos = nums[0];
        int curMaxReachPos = nums[0]; 
        int minStep = 1; // 最少跳跃次数
        for (int i = 1; i <= min(n - 1, maxReachPos); i++)
        {
            curMaxReachPos = max(curMaxReachPos, i + nums[i]);
            if (i == n - 1)
                return minStep; // why?
            if (i == maxReachPos)
            {
                maxReachPos = curMaxReachPos;
                minStep++;
            }
        }
        
        return 0;
    }
};

// better 
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0; // 如果数组元素个数小于2, 不用跳
        int curMaxPos = nums[0];
        int preMaxMaxPos = nums[0];
        int minStep = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > curMaxPos)
            {
                minStep++;
                curMaxPos = preMaxMaxPos;
            }
            
            preMaxMaxPos = max(preMaxMaxPos, nums[i] + i);
        }
        
        return minStep;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 451\n
```cpp
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
/* Type: hash table */
/* 题目信息 */
/*
 *451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        vector<pair<char, int>> vec;
        for (auto e : mp) {
            vec.push_back({e.first, e.second});
        }
        sort(vec.begin(), vec.end(), cmp);
        
        string res = "";
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].second; j++) {
                res += vec[i].first;
            }
        }
        return res;
    }
private:
    static bool cmp(pair<char, int> p1, pair<char, int> p2) {
        return p1.second > p2.second;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 多值排序问题
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

```\n
- 46\n
```cpp
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
/* Type: backtracking */
/* 题目信息 */
/*
 *46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 4ms, defeat %
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        helper(nums, 0, nums.size() - 1);
        return _res;
    }
private:
    vector<vector<int> > _res;
    void helper(vector<int> num_arr, int l, int r)
    {
        if (l == r)
            _res.push_back(num_arr);
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(num_arr[l], num_arr[i]);
                helper(num_arr, l + 1, r);
                swap(num_arr[l], num_arr[i]); // backtracking
            }
        }
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，求数组元素的全排列
//
// 需要注意的点: 
// 1. 使用backtracking
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;
    vector<vector<int> > res;
    vector<int> nums = {1, 2, 3};
    res = solution.permute(nums);

    return 0;
}

```\n
- 47\n
```cpp
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
/* Type:backtracking  */
/* 题目信息 */
/*
 *47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ?[1] 为什么要排序
        helper(nums, 0, nums.size() - 1);
        return _res;
        
    }
private:
    vector<vector<int> > _res;
    void helper(vector<int> nums_ano, int l, int r)
    {
        if (l == r)
            _res.push_back(nums_ano);
        else
        {
            for (int i = l; i <= r; i++)
            {
                if (i != l && nums_ano[i] == nums_ano[l]) // 跳过重复数字
                    continue;
                swap(nums_ano[l], nums_ano[i]);
                helper(nums_ano, l + 1, r);
                //swap(nums_ano[l], nums_ano[i]); // ?[2] 这一步为什么会舍去,
                //为什么不可以swap twice
            }
        }
            
    }
};

/* 一些总结 */
// 1. 题意: 
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
    vector<int> nums = {1, 1, 2, 2};
    vector<vector<int> > output;
    
    output = solution.permuteUnique(nums);
    

    return 0;
}

```\n
- 49\n
```cpp
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
/* Type: hash table */
/* 题目信息 */
/*
 *49. Group Anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
 */

/* my solution */
// solution-1, 68ms, defeat 37.89%
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (string str : strs) {
            string index = str;
            sort(index.begin(), index.end());
            mp[index].push_back(str);
        }
        vector<vector<string>> res;
        for (auto e : mp) {
            res.push_back(e.second);
        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 找到字符组成相同的字符串。
// 使用map进行。
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

```\n
- 496\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *496. Next Greater Element I
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (auto e: nums2)
        {
            while (!s.empty() && s.top() < e) // 这个地方为什么使用了while而不是if???
            {
                m[s.top()] = e;
                s.pop();
            }
            s.push(e);
        }
        
        for (auto &e: nums1)
            e = m.count(e) ? m[e] : -1;
        
        return nums1;
    }
};

/* 一些总结 */
// 1. unordered_map<int, int> m;
// 2. m.count(e): 返回查找到e的个数。map中不存在相同元素，返回0/1.

```\n
- 501\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 501. Find Mode in Binary Search Tree
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& umap)
    {
        if (!root) return;
        umap[root->val]++;  // 记录每个值出现的频次
        dfs(root->left, umap);
        dfs(root->right, umap);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> umap;
        vector<int> res;
        
        dfs(root, umap);
        int maxVal = 0;
        for (auto i : umap)
        {
            if (i.second > maxVal)
            {
                res.clear(); // 最终只有一个结果
                maxVal = i.second;
            }
            if (i.second >= maxVal)
                res.push_back(i.first);
        }
        
        return res;
    }
};
// easy to understand
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> ump;
        inorder(root, ump);
        vector<int> res;
        
        int max_freq = 0;
        for (auto e : ump)
        {
            if (e.second > max_freq)
                max_freq = e.second;
        }
        printf("%d\n", max_freq);
        for (auto e : ump)
        {
            if (e.second == max_freq)
            {
                res.push_back(e.first); 
            }
        }
        
        return res;
    }
private:
    void inorder(TreeNode* root, unordered_map<int, int>& ump)
    {
        if (!root) return;
        inorder(root->left, ump);
        ump[root->val]++;
        inorder(root->right, ump);
    }
};
/* 一些总结 */
// [题意]找出二叉树中出现频次最高的数字。unordered_map<int, int> umap, umap.first, umap.second; 

```\n
- 503\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Stack */
/* 题目信息 */
/*
 *503. Next Greater Element II

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.

 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> st;
        
        for (int i = 0; i < 2 * len; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i % len])
            {
                
                res[st.top()] = nums[i % len];
                st.pop();
            }
            st.push(i % len);
            
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 单调栈?
// 2. 栈中存放的也不在是数值，而是对应的索引。为什么?
// 3. 

```\n
- 507\n
```cpp
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
/* Type: math */
/* 题目信息 */
/*
 *507. Perfect Number

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 6
Output: true
Example 3:

Input: num = 496
Output: true
Example 4:

Input: num = 8128
Output: true
Example 5:

Input: num = 2
Output: false
 

Constraints:

1 <= num <= 108
 */

/* my solution */
// solution-x, ms, defeat %
// time limited
//
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 0;
        for (int i = 1; i < num; i++)
        {
            if (num % i == 0)
                res += i;
        }
        
        return num == res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 看一个数是不是完美数字: 数字等于所有正数因子之和
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

```\n
- 509\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
Note: 0 ≤ N ≤ 30.
 */

/* my solution */
// 1 √ 12ms
class Solution {
public:
    int fib(int N) {
        // recursive boundary
        if (N <= 1) return N;
        // recursion
        return fib(N-1) + fib(N-2);
        
    }
};

// 2 √ 0ms
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> record(N+1);
        record[0] = 0;
        record[1] = 1;
        for (int i = 2; i <= N; i++)
            record[i] = record[i-1] + record[i-2];
        return record[N];
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

```\n
- 525\n
```cpp
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
/* Type: hash table */
/* 题目信息 */
/*
 *525. Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.


 */

/* my solution */
// solution-x, ms, defeat %
// time limited
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int res = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] == 0)
                    zeros++;
                else 
                    ones++;
                if (zeros == ones && zeros == (i-start + 1) / 2) {
                    res = max(res, (i - start + 1));
                }
            }
            zeros = 0;
            ones = 0;
            
        }
        return res;
    }
};

// 上个代码优化下
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        for (int start = 0; start < nums.size(); start++) {
            int zeros = 0, ones = 0;
            for (int end = start; end < nums.size(); end++) {
                if (nums[end] == 0)
                    zeros++;
                else 
                    ones++;
                if (zeros == ones) {
                    res = max(res, (end - start + 1));
                }
            }
            
        }
        return res;
    }
};

/* better solution */
// solution-1, 292ms, defeat 46.18%
// 没有看懂下面这种解法
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ump;
        int max_len = 0, cnt = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1) ? 1 : -1;
            if (cnt == 0)
                max_len = max(max_len, i+1);
            if (ump.count(cnt))
                max_len = max(max_len, i-ump[cnt]);
            else
                ump[cnt] = i;
        }
        return max_len;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组,求子数组,子数组满足1和0的个数相同.
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

```\n
- 53\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type:  array*/
/* 题目信息 */
/*
 *53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
 */

/* my solution */


/* better solution */
// brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
        
    }
};
// 二层循环，每次固定一个位置，从当前位置开始循环，每次将当前数组添加1一个元素，查看当前数组所有元素的和，遇到比当前最大值更大的，更新当前最大值。


// better ✓✓
// 优化前缀和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;
        int minSum = 0;
        for (int num : nums)
        {
            sum += num;
            maxSum = max(maxSum, sum - minSum); // sum - minSum 怎么来的???
            minSum = min(minSum, sum);
        }
        
        return maxSum;
    }
};

// solution-2
// 下面这种解法比上一种解法更加容易理解。

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前和小于等于0, 则放弃当前和，重新将当前元素值赋值给当前和。
            // 及时止损。
            if (curSum <= 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            // 更新当前最大和。
            maxSum = max(maxSum, curSum);
        }
        return maxSum;

    }
};
// 1. 求出所有元素的前缀和

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 
```\n
- 530\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 530. Minimum Absolute Difference in BST
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note:

There are at least two nodes in this BST.
This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 */

/* my solution */
// none

/* better solution */
// O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    int minVal = INT_MAX;
    void helper(TreeNode* root)
    {
        if (root)
        {
            helper(root->left);
            if (prev != nullptr)
                minVal = min(minVal, abs(prev->val - root->val));
            prev = root;
            helper(root->right);
        }
        else
            return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        // 1. root is NULL
        if (!root) return 0;
        helper(root);
        return minVal;
    }
};

// O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& sorted)
    {
        if (!root) return;
        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }
    
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        vector<int> sorted;
        int minVal = INT_MAX;
        inorder(root, sorted);
        
        //for (int i = sorted.size()-1; i >= 0; i--)
        for (int i = 1; i < sorted.size(); i++)
            minVal = min(minVal, sorted[i] - sorted[i-1]);
        
        return minVal;
    }
};
/* 一些总结 */
// 1. 对于prev这个在其中的变换自己需要好好想一下，比较混乱。
// 2. 第二种方法是较为容易的方法，但是时间复杂度比第一种大。
```\n
- 54\n
```cpp
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
 *剑指 Offer 54. 二叉搜索树的第k大节点
给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
 

限制：

1 ≤ k ≤ 二叉搜索树元素个数
 */

/* my solution */
// solution-1: 32ms defeat 66.77%
// 二叉树中序遍历
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int index = nums.size() - k;
        return nums[index];
    }
private:    
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
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

```\n
- 543\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 543. Diameter of Binary Tree
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *       / \     
 *     4   5    
 *    Return 3, which is the length of
 *    the path [4,2,1,3] or [5,2,1,3].
 *
 *    Note: The length of path between
 *    two nodes is represented by the
 *    number of edges between them.
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    int ans;
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L+R+1);
        return max(L, R) + 1; // 这个1可以看作是root到root->left或到root->right之间的边
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        
        return ans - 1;
    }
};
// 2 better
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res_ = 0;
        dfs(root);
        return res_; // 注意这里返回的变量，我总是将return dfs(root);这样写了
    }
private:
    int res_;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        res_ = max(res_, L + R);
        
        return 1 + max(L, R);
    }
};
/* 一些总结 */
// [题意]找到二叉树中距离最远的两个结点的距离; 这个加一是什么逻辑?

```\n
- 55-1\n
```cpp
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

```\n
- 55\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: greedy */
/* 题目信息 */
/*
 *55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
 */

/* my solution */


/* better solution */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        // index[]: 存入当前位置可以跳到的最远位置
        for (int i = 0; i < nums.size(); i++)
            index.push_back(i + nums[i]);

        int curPosition = 0;
        int max_index = index[0]; // 当前位置可以跳到的最远位置
        while (curPosition < nums.size() && curPosition <= max_index)
        {
            max_index = max(max_index, index[curPosition]);
            curPosition++;
        }
        
        if (curPosition == nums.size())
            return true;
        
        return false;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 贪心算法：只考虑局部最优
// 2. 使用index[]存入当前位置可以跳到的最远位置，然后遍历index，更新max_index
// 3. 

```\n
- 557\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *557. Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

/* my solution */
// solution-1, 28ms, defeat 27.73%
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        if (s.size() == 0)
            return res; // 这句加入后时间变为20ms
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
                temp = "";
                continue;
            }
            temp += c;
        }
        reverse(temp.begin(), temp.end());
        res += temp;
        
        //for (int i = res.size() - 1; i >= 0; i--) {
        //    if (res[i] == ' ')
        //        res.erase(i-1, i);
        //}
        return res;
    }
};

/* better solution */
// solution-2, 24ms, defeat 45.20%
// 下面这种写法更简洁
class Solution2 {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        
        int i = 0;
        int len = s.size();
        int j = 0;
        while (i < len) {
            j = i + 1;
            while (s[j] != ' ' && j < len) j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1; // 跳过空格!
        }
        return s;
        
    }
};

/* 一些总结 */
// 1. 题意: 
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
    string input = "Let's take LeetCode contest";
    string res = solution.reverseWords(input);
    cout << res;

    return 0;
}

```\n
- 56\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
 */

/* my solution */

/* better solution */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        // 1. sort
        sort(intervals.begin(), intervals.end(), cmp);
        // 2. check if has interlap
        vector<vector<int>> res;
        for (auto interval : intervals)
        {
            // 1. res is empty
            // res has no interlap with cur vector
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1] , interval[1]);
        }
        
        return res;
    }
private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
    }
};

/* 一些总结 */
// 1. 题意: 给定一组二维数组，将这些有交叉的区间进行合并。
// 2. 解决: 对整个二维数组根据第一个元素值大小进行排序，之后进行合并
// 需要注意的点: 
// 1. 注意sort的高级用法， 那个cmp的写法
// 2. 
// 3. 

```\n
- 560\n
```cpp
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
#include <unordered_map>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *560. Subarray Sum Equals K

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, time limited!
// brute force
// 遍历得到每一种结果,但是这种start, end的写法当时并不会写.
// O(n^3)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                int sum = 0;
                for (int i = start; i < end; i++) 
                    sum += nums[i];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

// solution-2 累计和 prefix sum
// 后一个减去前一个就是中间元素的和.
// O(n^2)
// time limited, java版本的可以通过,但是cpp版本不行.
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
        
    }
};

// solution-3: hash table prefix sum
// ✓
// 唯一通过的方法
class Solution3 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, 1}};
        int count = 0, sum = 0;
        
        for (int& i : nums) {
            sum += i;
            count += mp[sum - k]; // 这一句让我很困惑.
                                  // 查看mp中是否有sum-k的存在, 这个是为什么?
                                  // 有些绕
            //cout << mp[sum-k] << endl;
            mp[sum]++;
        }
        return count;
        
    }
};
/* 一些总结 */
// 1. 题意: 给定一数组,给定一k值,查看数组中有多少连续子数组的和等于k.
//
// 需要注意的点: 
// 1. prefix sum
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution3 solution3;
    vector<int> input = {1, 1, 1};
    int k = 2;
    int res = solution3.subarraySum(input, k);
    cout << res;

    return 0;
}

```\n
- 5690\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 * 5690. 最接近目标价格的甜点成本
 *你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：

必须选择 一种 冰激凌基料。
可以添加 一种或多种 配料，也可以不添加任何配料。
每种类型的配料 最多两份 。
给你以下三个输入：

baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回 成本相对较低 的一种。

 

示例 1：

输入：baseCosts = [1,7], toppingCosts = [3,4], target = 10
输出：10
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 7
- 选择 1 份 0 号配料：成本 1 x 3 = 3
- 选择 0 份 1 号配料：成本 0 x 4 = 0
总成本：7 + 3 + 0 = 10 。
示例 2：

输入：baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
输出：17
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 3
- 选择 1 份 0 号配料：成本 1 x 4 = 4
- 选择 2 份 1 号配料：成本 2 x 5 = 10
- 选择 0 份 2 号配料：成本 0 x 100 = 0
总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
示例 3：

输入：baseCosts = [3,10], toppingCosts = [2,5], target = 9
输出：8
解释：可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
示例 4：

输入：baseCosts = [10], toppingCosts = [1], target = 1
输出：10
解释：注意，你可以选择不添加任何配料，但你必须选择一种基料。
 

提示：

n == baseCosts.length
m == toppingCosts.length
1 <= n, m <= 10
1 <= baseCosts[i], toppingCosts[i] <= 104
1 <= target <= 104
 */

/* my solution */
// solution-x, ms, defeat %
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int> sum(10, 0);
        for (int i = 0; i < baseCosts.size(); i++) {
            sum[i] += baseCosts[i];
            for (int j = 0; j < toppingCosts.size(); j++) {
                if (sum[i] + 2 * toppingCosts[j] <= target) {
                    sum[i] += 2 * toppingCosts[j];
                } else if (sum[i] + toppingCosts[j] <= target){
                    sum[i] += toppingCosts[j];
                }
            }
        }

        sort(sum.begin(), sum.end());
        int before, end;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] == target)
                return sum[i];
            else if (sum[i] < target)
                before = target - sum[i];
            else if (sum[i] > target)
                end = sum[i] - target;
        }
        if (before <= end)
            return target - before;
        else if (before > end)
            return target + end;
        return 0;
    }
};


/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
// 没有做出来,这是组合题,然后找到最接近目标的方案.
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

/*
 * main test
 */


int main()
{
    Solution solution;
    vector<int> baseCosts = {2, 3};
    vector<int> toppingCosts = {4, 5, 100};
    int target = 18;
    int res = solution.closestCost(baseCosts, toppingCosts, target);
    cout << res << endl;
}
```\n
- 5698\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long a = goal;
        for (int i : nums) {
            a -= i;
        }
        //cout << "goal: " << goal << endl;
        int abs_goal = abs(a);

        //if (limit >= abs_goal) // 将这两句注释掉了就通过了?!
         //   return 1;

        if (abs_goal % limit == 0)
            return abs_goal / limit;
        return abs_goal / limit + 1;
    }
};


/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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
    vector<int> nums = {1, -1, 1};
    int limit = 3;
    int goal = -4;
    int res = solution.minElements(nums, limit, goal);
    
    cout << "res: " << res << endl;

    return 0;
}

```\n
- 57\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: array */
/* 题目信息 */
/*
 *57. Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 105
 */

/* my solution */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        intervals.push_back(newInterval);
        // 1. sort
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto interval : intervals)
        {
            if (res.empty() || res.back()[1] < interval[0])
                res.push_back(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }
        
        return res;
    }
private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0];
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

```\n
- 572\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 572. Subtree of Another Tree
 *Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool areEqual(TreeNode* s, TreeNode* t)
    {
        if (!s && !t)
            return true;
        if (!s || !t)
            return false;
        return (s->val == t->val) && areEqual(s->left, t->left) && areEqual(s->right, t->right);
    }
    
    //bool traverse(TreeNode* s, TreeNode* t)
    //{
    //    if (!s && !t)
    //        return true;
    //    if (!s || !t)
    //        return false;
    //    return (!s && areEqual(s, t)) || traverse(s->left, t) || traverse(s->right, t); 
    //}
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return areEqual(s, t) || (s->left && isSubtree(s->left, t) || (s->right) && isSubtree(s->right, t));
    }
};

/* 一些总结 */
// [题意]判断一棵树是不是另一棵树的子树。另外写两个函数，第一个函数从相等的那个结点开始对比，第二个函数看s是否包含t

```\n
- 58\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *58. Length of Last Word
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
 */

/* my solution */
// solution-1, 0ms, defeat 100%

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        
        int i = len - 1;
        // 消除末尾多余空格
        while (s[i--] == ' ')
            s.erase(s.size() - 1, s.size());
        
        if (s.size() == 0)
            return 0;   
        if (s.size() == 1 && s[s.size() - 1] == ' ')
            return 0;
        
        
        
        bool flag = false; // space mark
        
        // 注意使用新的字符串长度
        for (int k = s.size() - 1; k >= 0; k--) {
            if (s[k] == ' ') {
                flag = true;
                return s.size() - 1 - k;
            }
        }
        if (!flag)
            return s.size();
        return 0;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串，求出字符串中最后一个单词的长度
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
    string input = "      ";
    string input2 = " a ";
    int res = solution.lengthOfLastWord(input2);
    cout << res;
        

    return 0;
}

```\n
- 590\n
```cpp
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

```\n
- 606\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 606. Construct String from Binary Tree
 * You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        // 1. root == null
        if (!root) return "";
        string s = to_string(root->val);
        // 2. root->left == null && root->right == null
        if (!root->left && !root->right)
            return s + "";
        // 3. root->right == null
        if (!root->right)
            return s + "(" + tree2str(root->left) + ")";
        // 4. default is that the root->left must have ()
        return s + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};

/* 一些总结 */
// 分情况讨论
// 1. root == null
// 2.   root
//     /   \
//   null   null
// 3.   root
//    /    \
//   lchild null
// 4.   root
//    /    \
//  null   rchild
// 5.   root
//    /    \
// lchild  rchild
```\n
- 61\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: Linked list */
/* 题目信息 */
/*
 *61. Rotate List
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */

/* my solution */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        // len
        int len = 0;
        ListNode* cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        k %= len;
        if (k == 0) return head; // !!!
        int process = len - k;
        ListNode* prev = head;
        while (--process)
            prev = prev->next;
        ListNode* newHead = prev->next;
        prev->next = nullptr;
        cur = newHead;
        while (cur->next)
            cur = cur->next;
        cur->next = head;
        
        return newHead;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 给定链表和一个k值，把链表顺时针循环移动k次
//
// 需要注意的点: 
// 1. 重要的点就是k = k % len, 这个取余需要注意。循环移动k次 ↔ 循环移动k%len次
// 2. 还有一些边界条件例如k%len == 0时，直接返回head即可，等价于没有移动。
// 3. 

```\n
- 617\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 617. Merge Two Binary Trees
 * Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:

Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7


Note: The merging process must start from the root nodes of both trees.
 */

/* my solution */
// none
//
/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. 递归边界
        if (!t1) return t2;
        if (!t2) return t1;
        // 2. 递归式
        t1->val += t2->val;
        if (t2->left)
            t1->left = mergeTrees(t1->left, t2->left);
        if (t2->right)
            t1->right = mergeTrees(t1->right, t2->right);
            
        return t1; 
    }
};
/* 一些总结 */
// 1. 这个题也不知道该怎么写，就相加知道，当然递归边界这个不好想，也不是不好想。
```\n
- 653\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 653. Two Sum IV - Input is a BST
 *Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 1. cur的功能呢个是?
    // 2. n是target减去当前根节点的值之后的值
    bool traverse(TreeNode* root, TreeNode* cur, int n)
    {
        if (root->val == n && root != cur)
            return true;
        if (root->left)
            if (traverse(root->left, cur, n) == true)
                return true;
        if (root->right)
            if (traverse(root->right, cur, n) == true)
                return true;
        
        return false;
    }
    
    bool search(TreeNode* root, int k, TreeNode* cur)
    {
        int temp = k - root->val;
        if (traverse(cur, root, temp) == true)
            return true;
        if (root->left)
            if (search(root->left, k, cur) == true)
                return true;
        if (root->right)
            if (search(root->right, k, cur) == true)
                return true;
        
        return false;
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        // 3. 为什么需要root的左右孩子都存在不?
        if (!root || (!root->left && !root->right)) return false;
        else
            return search(root, k, root);
    }
};

/* 一些总结 */
// 题解我没有看懂
```\n
- 66\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Array */
/* 题目信息 */
/*
 *66. Plus One
 *Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        vector<int> res;
        if (len == 0)
            return res;
        
        int sum = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            sum += digits[i];
            digits[i] = sum % 10;
            sum /= 10;
            if (sum == 0) break;
        }
        
        if (sum > 0) res.push_back(sum);  // first
        for (int i = 0; i < len; i++)
        {
            res.push_back(digits[i]);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 669\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 669. Trim a Binary Search Tree
 * Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
    1
   / \
  0   2

  L = 1
  R = 2

Output:
    1
      \
       2
Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output:
      3
     /
   2
  /
 1
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        if (root->val < L)
            return trimBST(root->right, L, R);
        if (root->val > R)
            return trimBST(root->left, L, R);
            
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};

// better
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return nullptr;
        if (root->val < L)
            return trimBST(root->right, L, R);
        else if (root->val > R)
            return trimBST(root->left, L, R);
        else 
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
        }
        
        return root;
    }
};
// 当根结点值小于区域左边界时，对根结点右子树剪枝，当根结点值大于区域右边界时，对根结点左子树剪枝，如果根结点值处于区域之间，不剪枝，并且递归推出其左右子树的剪枝结果。
/* 一些总结 */
// 分类讨论，不在区间之间和在区间之间
```\n
- 67\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Math */
/* 题目信息 */
/*
 *67. Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
 */

/* my solution */


/* better solution */
class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size() - 1; 
        int lenB = b.size() - 1;
        int carry = 0;
        string res = "";
        while (lenA >= 0 || lenB >= 0 || carry)
        {
            if (lenA >= 0)
            {
                carry += a[lenA] == '0' ? 0 : 1;
                lenA--;
            }
            if (lenB >= 0)
            {
                carry += b[lenB] == '0' ? 0 : 1;
                lenB--;
            }
            
            res = ((carry % 2) == 0 ? "0" : "1") + res;
            carry /= 2;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 从后往前开始
// 2. carry % 2与 carry / 2容易混
// 3. 

```\n
- 671\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 */

/* my solution */
// none
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        unordered_set<int> st;
        inorder(root, st);
        cout << "st.size()=" << st.size() << endl;
        int cnt = 2;
        for (auto e : st)
        {
            cout << cnt << endl;
            if (!--cnt)
            {
                //cout << cnt << endl;
                return e;
            }
        }
        return -1;
    }
private:
    void inorder(TreeNode* root, unordered_set<int>& st)
    {
        if (!root) return;
        inorder(root->left, st);
        st.insert(root->val);
        inorder(root->right, st);
    }
};
// 上边这个出了什么问题???没检查出来
// 上边这个错误的原因是使用了unordered_set，这个容器中的数据是无序的。
/* better solution */
class Solution {
public:
    void preorder(TreeNode* root, set<int>& s)
    {
        if (!root) return;
        s.insert(root->val);
        preorder(root->left, s);
        preorder(root->right, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        preorder(root, s);
        
        int cnt = 2;
        for (auto& e : s)
        {
            if (!--cnt)
                return e;
        }
        
        return -1;
    }
};

/* 一些总结 */
// 1. set 使用
// 2. auto 使用

```\n
- 687\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val)
            arrowLeft += (L + 1);
        if (root->right && root->right->val == root->val)
            arrowRight += (R + 1);
        
        res = max(res, arrowLeft + arrowRight);
        
        return max(arrowLeft, arrowRight);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//[题意]找到二叉树中结点值全相同的最长路。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 69\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: math */
/* 题目信息 */
/*
 *69. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
 */

/* my solution */


/* better solution */
// brute force
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        // 注意这个long long, 如果定义为int类型会导致溢出
        for (long long s = 1; s <= x; s++)
        {
            if (s * s > x)
                return s - 1;
        }
        
        return -1;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. huahua还有另外两种解，有兴趣可以了解一下
// 2. 
// 3. 

```\n
- 70\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
Constraints:

1 <= n <= 45
 */

/* my solution */


/* better solution */
// 1. brute force
// ✗ Time Limit Exceeded
class Solution {
public:
    int climb_stair(int step, int top)
    {
        if (step > top)
            return 0;
        if (step == top)
            return 1;
        return climb_stair(step+1, top) + climb_stair(step+2, top);
    }
    
    int climbStairs(int n) {
        return climb_stair(0, n);
    }
};

// 2. Recursion with Memoization
// ✓
class Solution {
public:
    int climb_stair(int i, int n, vector<int>& memo)
    {
        if (i > n) return 0;
        if (i == n) return 1;
        if (memo[i] > 0) return memo[i];
        memo[i] = climb_stair(i+1, n, memo) + climb_stair(i+2, n, memo);
        
        return memo[i];
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1);
        return climb_stair(0, n, memo);
    }
};
/* 一些总结 */
// 1. 题意: 
//[题意]爬楼梯，每次可以爬一阶或是二阶，问有多少中方法可以爬到顶部。
// 需要注意的点: 
// 1. 数组记录每个state的值
// 2. 
// 3. 

```\n
- 700\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 700. Search in a Binary Search Tree
 * Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example,

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2
     / \
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/// Solution 1
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root)
        {
            if (val == root->val)
                break;
            else if (val > root->val)
                root = root->right;
            else
                root = root->left;

        }

        return root;
    }
};


/// solution 2
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && val != root->val)
        {
            root = (val > root->val) ? root->right : root->left;
        }
        
        return root;
    }
};

// solution3
class Solution {
public:
    TreeNode* find(TreeNode* root, int val)
    {
        if (!root) return root;
        if (root->val == val)
            return root;
        else if (val < root->val)
            return find(root->left, val);
        else 
            return find(root->right, val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return find(root, val);
    }
};

/* 一些总结 */
// 1. while(root)的方式就可以一直循环下去
// 2. nullptr: c++中的空指针常量
```\n
- 701\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 701. Insert into a Binary Search Tree
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
 

Constraints:

The number of nodes in the given tree will be between 0 and 10^4.
Each node will have a unique integer value from 0 to -10^8, inclusive.
-10^8 <= val <= 10^8
It's guaranteed that val does not exist in the original BST.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) 
        {
            TreeNode* done = new TreeNode(val);
            return done;
        }
        
        if (val > root->val)
            root->right = insertIntoBST(root->right, val); // not return
        else if (val < root->val)
            root->left = insertIntoBST(root->left, val);  // not return
        
        return root;
    }
};

/* 一些总结 */
// 递归插入操作

// 注意结点为空是也是要新建结点进行返回的。!
```\n
- 75\n
```cpp
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
/* Type: sort */
/* 题目信息 */
/*
 *75. Sort Colors
 */

/* my solution */
// solution-x, ms, defeat %
// 自己使用快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        
    }
private:
    void quickSort(vector<int>& nums, int low, int high)
    {
        int temp;
        int i = low, j = high;
        
        if (low < high)
        {
            temp = nums[low];
            while (i < j)
            {
                // find value that less than temp
                while (j > i && nums[j] >= temp) j--;
                if (i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }
                while (i < j && nums[i] < temp) i++;
                if (i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = temp;
            quickSort(nums, low, i - 1);
            quickSort(nums, i + 1, high);
        }
    }
};

/* better solution */
// solution-2, 0ms, defeat 100%
// two pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int pn = nums.size() - 1;
        int curr = 0;
        while (curr <= pn)
        {
            if (nums[curr] == 0)
            {
                swap(nums[p0], nums[curr]);
                p0++;
                curr++;
            }
            else if (nums[curr] == 2)
            {
                swap(nums[curr], nums[pn]);
                pn--;
            }
            else
                curr++;
        }
        
    }
};

/* 一些总结 */
// 1. 题意: 为给定数组排序, 不能使用函数sort, 只有3种数字：0, 1, 2
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

```\n
- 771\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *771. Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
 */

/* my solution */


/* better solution */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        int cnt = 0;
        for (char c: S)
        {
            m[c]++;
        }
        for (char c: J)
        {
            if (m.count(c))
                cnt += m[c];
        }
        
        return cnt;
    }
};

/* 一些总结 */
// 1. 题意: 
// 字符串J和S，看J中字符串中字符在S中出现了几次。
// 解: 使用map，
// 先遍历字符串S，将字符对应次数记录下来，再遍历字符串J，看有哪些字符出现。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 78\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: backtracking combination */
/* 题目信息 */
/*
 *78. Subsets Medium
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

/* my solution */


/* better solution */
// 1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res, tmp, nums, 0);
        
        return res;
    }
private:
    void backtrack(vector<vector<int>>& list, vector<int>& tempList, vector<int>& nums, int start)
    {
        list.push_back(tempList);
        for (int i = start; i < nums.size(); i++)
        {
            tempList.push_back(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.pop_back();
        }
    }
};

// 2 dfs + backtracking from huahua
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        // 0个元素可以，n个元素也可以
        for (int i = 0; i <= nums.size(); i++)
            dfs(nums, i, 0, cur, res);
        
        return res;
    }
private:
    /*
     * C(m, n): m个元素中取n个元素
     * s: start point
     * n: 要取多少个元素
     * cur: 当前的数组
     */
    void dfs(const vector<int>& nums, int n, int s,
             vector<int>& cur, vector<vector<int>>& res)
    {
        if (n == cur.size()) // 找到了一个解
        {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur, res);
            cur.pop_back();
        }
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. combination基本写法
// 2. combination不关心顺序
// 3. 

```\n
- 783\n
```cpp
/*
 * 783. Minimum Distance Between BST Nodes
 * Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 *
 */

// my solution
// none

// better
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = nullptr;
    int min_diff = INT_MAX;
    void helper(TreeNode* root)
    {
        if (root)
        {
            if (root->left) helper(root->left);
            if (prev != nullptr)
            {
                min_diff = min(min_diff, abs(root->val - prev->val));
            }
            prev = root;
            if (root->right) helper(root->right);
        }
        else
            return;
    }
    
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        
        return min_diff;
    }
};

// 1. 不要凭以往类似题，总是去想以前的题是怎么做的，需要想这道题的逻辑
```\n
- 79\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *79. Word Search
 */

/* my solution */
// solution-x, ms, defeat %
        map<char, int> mp;
        int m = board.size();
        int n = board[0].size();
        // borad char's freq
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[board[i][j]]++;
            }
        }
        // word char's freq
        for (int i = 0; i < word.size(); i++) {
            if (mp[word[i]]) {
                
            }
        }
        map<char, int> mp;
        int m = board.size();
        int n = board[0].size();
        // borad char's freq
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[board[i][j]]++;
            }
        }
        // word char's freq
        for (int i = 0; i < word.size(); i++) {
            if (!mp[word[i]]) {
                return false;
            }
            mp[word[i]]--;
        }
        return true;
    }
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一个mxn的字符矩阵，在矩阵中寻找一个单词，单词字符必须是挨着的。
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

```\n
- 804\n
```cpp
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
/* Type: string */
/* 题目信息 */
/*
 *804. Unique Morse Code Words
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
 */

/* my solution */
// solution-x, ms, defeat %
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        map<char, string> mp;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (int i = 0; i <  26; i++) {
            char x = (char)('a' + i);
            mp[x] = morse[i];
        }
        for  (string str : words) {
            string temp = "";
            for (char c : str) {
                temp += mp[c];
            }
            s.insert(temp);
        }
        return s.size();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
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

```\n
- 811\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *811. Subdomain Visit Count
A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

Example 1:
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation: 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:

The length of cpdomains will not exceed 100. 
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.
The answer output can be returned in any order.
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;
        for (string str: cpdomains)
        {
            int i = str.find(" "); // return the position of space
            int num = stoi(str.substr(0, i));
            string remaining = str.substr(i + 1);
            mp[remaining] += num;
            for (int j = 0; j < remaining.size(); j++)
            {
                if (remaining[j] == '.')
                {
                    mp[remaining.substr(j + 1)] += num;
                }
            }
        }
        
        vector<string> res;
        for (auto e: mp)
            res.push_back(to_string(e.second) + ' ' + e.first);
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. stoi(str, start_position, 2) 2是进制，此例意为将2进制的str从position转换成10进制
// 2. string.substr(start, [length])

```\n
- 814\n
```cpp
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

```\n
- 82\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Linked list */
/* 题目信息 */
/*
 *82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
 */

/* my solution */


/* better solution */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy, *q = head, *tmp = nullptr;
        
        while (q)
        {
            while (q->next && q->val == q->next->val)
                q = q->next;  // move q to the last duplicate element

            if (p->next == q) // no duplicates
                //return dummy->next;
                p = q;
            else
            {
                for (ListNode* it = p->next; it != q;)
                {
                    tmp = it;
                    it = it->next;
                    delete(tmp);
                }
                p->next = q->next;
                delete(q);
            }
            q = p->next; // 开始下一次的删除
            //p->next = q;
        }
        
        return dummy->next;
        
    }
};

/* 一些总结 */
// 1. 题意: 删除链表中重复的结点。
// 2. 解决方法:
// 先将指针移到最后一个重复的结点，删除p到q之间的结点，这里的删除可以有，也可以没有，或者直接next也能通过。
// 需要注意的点: 
// 1. p->next = q和q = p->next的区别
// 2. 
// 3. 

```\n
- 83\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 83. Remove Duplicates from Sorted List
 *Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == cur->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        
        return head;
    }
};

/* 一些总结 */
// 1. 总是需要一个复制的头结点。一个循环，一个不动。
```\n
- 832\n
```cpp
/* Leetcode */

/* 题目信息 */
/* 832. Flipping an Image
 * Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

/* my solution */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            // 1. reverse
            reverse(A[i].begin(), A[i].end());
            // 2. invert
            for (int j = 0; j < A[i].size(); j++) {
                if (A[i][j] == 0) A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
        return A;
    }
};
/* better solution */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            // 1. reverse
            std::reverse(A[i].begin(), A[i].end());
            // 2. invert
            for (int j = 0; j < A[i].size(); j++) {
                A[i][j] = A[i][j] ^ 1;
            }
        }
        return A;
    }
};
/* 一些总结 */
//1. 这种01运算可以使用异或，执行效率会更高
//2. reverse(arr.begin(), arr.end())
```\n
- 852\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: binary search */
/* 题目信息 */
/*
 *852. Peak Index in a Mountain Array

Let's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1
Example 4:

Input: arr = [3,4,5,1]
Output: 2
Example 5:

Input: arr = [24,69,100,99,79,78,67,36,26,19]
Output: 2
 

Constraints:

3 <= arr.length <= 104
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 */

/* my solution */


/* better solution */
// solution - 1
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

// solution - 2
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i+1])
        {
            i++;
        }
        return i;
    }
};
/* 一些总结 */
// 1. 题意: 
// 一组元素像山峰一样，中间有个值是最大的，左边都是比这个数小，右边也都小于这个数，返回这个数在数组中的下标
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 861\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *861. Score After Flipping Matrix
 */

/* my solution */
// solution-x, ms, defeat %
// 我自己考虑的太简单了.
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            string temp = "";
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j] == 0)
                    temp += "1";
                else 
                    temp += "0";
            }
            res += bin_to_dec(temp);
        }
        return res;
    }
private:
    int bin_to_dec(string str) {
        int nums = 0;
        int len = str.size();
        for (int i = 0; i < len; i++) {
            int x = (int)(str[i] - '0');
            nums += x * pow(2, len - 1 - i);
        }
        return nums;
    }
    
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一二维数组,任意移动:1→0, 0→1, 这样,之后返回最大的值
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
    vector<vector<int>> input = { { 0,0,1,1 },{ 1,0,1,0 },{ 1,1,0,0 } };
    int res = solution.matrixScore(input);
    cout << res;

    return 0;
}

```\n
- 872\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 872. Leaf-Similar Trees
 * Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

                 3
               /   \
            5        1
         /   \       /   \
       6      2     9     8
            /   \  
          7      4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Constraints:

Both of the given trees will have between 1 and 200 nodes.
Both of the given trees will have values between 0 and 200
 */

/* my solution */
// none

/* better solution */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v)
    {
        if (!root) return;
        if (!root->left && !root->right)
            v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        
        return leaf1 == leaf2;
    }
};
/* 一些总结 */
// 1. 现在觉得if(!root)这样的写法更简洁
// 2. dfs
// 3. 对比两个vector是否相同，题解中使用的是vector1 == vector2这样进行判断。
// 也可以自己写一个循环进行判断，当然得先对比两个vector的长度是否一样。
```\n
- 876\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Linked list */
/* 题目信息 */
/*
 *876. Middle of the Linked List
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.
 */

/* my solution */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return nullptr;
        // len
        ListNode* cur = head;
        int len = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        int stop;
        //if (len % 2 == 0) // len is even
        //    stop = len / 2;
        //else
        //    stop = len / 2 + 1;
        stop = len / 2 + 1; // 偶数奇数都得加一
        int cnt = 0;
        while (head)
        {
            cnt++;
            if (cnt == stop)
                break;
            head = head->next;
        }
        return head;
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

```\n
- 88\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n
 */

/* my solution */
// none

/* better solution */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (i >= 0 && j >= 0) // 这个控制不可少
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            
        }
        
        while (i >= 0)
            nums1[k--] = nums1[i--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
        
    }
};

/* 一些总结 */


```\n
- 889\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *889. Construct Binary Tree from Preorder and Postorder Traversal
 */

/* my solution */


/* better solution */


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 关键是确定左子树的长度
// 2. 
// 3. 

```\n
- 894\n
```cpp
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

```\n
- 897\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 897. Increasing Order Search Tree
Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
 

Constraints:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.
 */

/* my solution */
// none


/* better solution */
// 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        TreeNode* pre = head;
        stack<TreeNode*> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left   ;
            }
            
            root = todo.top();
            todo.pop();
            pre->right = root;
            pre = pre->right;
            root->left = NULL;
            root = root->right;
        }
        return head->right;
    }
};

// 2
// √
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* cur;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        root->left = NULL;
        cur->right = root;
        cur = root;
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0); // 注意需要初始化，不然会报错。
        cur = res;
        inorder(root);
        
        return res->right;
    }
};
/* 一些总结 */
// 1. recursive看着更清晰一些。
// 2. 118行需要初始化
```\n
- 9\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 9. Palindrome Number
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
 */

/* my solution */
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. x < 0 won't be a palindrome
        // and if the last digit of x is 0, x won't be a palindrome.
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int compare = x;
        int revertedNum = 0;
        while (x)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        printf("%d\n", revertedNum);
        return compare == revertedNum;
        //if (x == revertedNum)
        //    return true;
        //else 
        //    return false;
    }
};
// 这种方法会导致最后一个测试用例超时。

/* better solution */ 
// √
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. x < 0 won't be a palindrome
        // and if the last digit of x is 0, x won't be a palindrome either.
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        
        int revertedNum = 0;
        while (x > revertedNum)
        {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        
        return x == revertedNum || x == revertedNum / 10;
    }
};

/* 一些总结 */
// 1. 需要考虑到输入的值特别大的情况，那个时候运行的时间会超过限制。

// 第二种方法: 判断 x 是不是小于 revertNum，当它小于的时候，说明数字已经对半或者过半了
// 最后，判断奇偶数情况：如果是偶数的话，revertNum 和 x
// 相等；如果是奇数的话，最中间的数字就在revertNum 的最低位上，将它除以 10
// 以后应该和 x 相等。
```\n
- 905\n
```cpp
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
/* Type: two pointers */
/* 题目信息 */
/*
 *905. Sort Array By Parity
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 */

/* my solution */
// solution-1, 52ms, defeat 5.89%
// so slow.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for (int e : A) {
            if (e % 2 == 1)
                res.push_back(e);
            else
                res.insert(res.begin(), 1, e);
        }
        return res;
    }
};

/* better solution */
// solution-2, 20ms, defeat 34.95%
// in-place; two pointers.
class Solution2 {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        
        while (left < right) {
            if (A[left] % 2 != 0) {
                if (A[right] % 2 == 0) // 加上这个判断条件后, 16ms, 69.73%, 避免不必要的交换
                    swap(A[left], A[right]);
                right--;
            } else {
                left++;
            }
        }
        
        return A;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组,将数组中的偶数放在数组左端,将奇数放在数组右端.
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

```\n
- 92\n
```cpp
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Linked List */
/* 题目信息 */
/*
 *92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

/* my solution */


/* better solution */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre, *front, *last;
        // cur to m
        for (int i = 0; i < m - 1; i++) cur = cur->next;
        pre = cur;
        last = cur->next;
        
        for (int i = m; i <= n; i++) // 注意是<=n
        {
            cur = pre->next;
            pre->next =  cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 循环的那四步是怎么想出来的???自己动手模拟了一遍，看懂了，但是肯定写不出来
// 2. 
// 3. 

```\n
- 929\n
```cpp
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
/* Type:  */
/* 题目信息 */
/*
 *929. Unique Email Addresses
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 

Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
 */

/* my solution */
// solution-1, 36ms, defeat 43.47%
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (string email : emails) {
            string temp = "";
            bool flag = true;
            bool at_flag = false;
            for (char c : email) {
                if (c == '.' && !at_flag)
                    continue;
                if (c == '+')
                    flag = false;
                if (c == '@') {
                    flag = true;
                    at_flag = true;
                }
                if (flag)
                    temp += c;
            }
            s.insert(temp);
        }

        return s.size();
        
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一字符串数组,根据一些规则进行处理.
// 其实并不难,之前打开过这道题的页面,但是"感觉"有些麻烦,就跳过了...
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
    vector<string> emails = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
    int res = solution.numUniqueEmails(emails);
    cout << res;

    return 0;
}

```\n
- 938\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *938. Range Sum of BST
 Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.
Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32
Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23


Note:

The number of nodes in the tree is at most 10000.
The final answer is guaranteed to be less than 2^31.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/* my solution */
// none
/* better solution */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0; 
    
    void inorder(TreeNode *root, int L, int R)
    {
        if (root->left)
            inorder(root->left, L, R);
        if (root->val >= L && root->val <= R)
            sum += root->val;
        if (root->right)
            inorder(root->right, L, R);
    }

    int rangeSumBST(TreeNode *root, int L, int R)
    {
        inorder(root, L, R);
        
        return sum;
    }

};
/* 一些总结 */
// 1. 使用的是中序遍历，这样看来并不难。
```\n
- 94\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/* my solution */
// 1. recursive ✓
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

/* better solution */
// 2. iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top(); st.pop();
                // 这一步如果写成
                // TreeNode* cur = st.top(); st.pop();
                // 这样就会是错的，为什么?
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 从根节点开始，先将根节点压入栈
//
// 然后再将其所有左子结点压入栈，取出栈顶节点，保存节点值
//
// 再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中，
// 重复上步骤
// 2. 
// 3. 

```\n
- 946\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: stack */
/* 题目信息 */
/*
 *946. Validate Stack Sequences
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
 */

/* my solution */


/* better solution */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        stack<int> stk;
        
        int j = 0;
        for (int x : pushed)
        {
            stk.push(x);
            while (!stk.empty() && j < n && stk.top() == popped[j])
            {
                stk.pop();
                j++;
            }
        }
        
        if (!stk.empty())
            return false;
        
        return true;
    }
};

/* 一些总结 */
// 1. 题意: 给定一个输入序列，一个输出序列，验证这个输出序列是否是以输入序列入栈后的输出序列
// 解决：每次pushed进栈一个元素，检查当前栈的栈顶是否和输出序列当前所指元素相同，不同则继续进栈，相同则出栈，并且输出序列指针(其实是地址)后移一位。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 95.unique-binary-search-trees-ii\n
```cpp
/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        
    }
};
// @lc code=end

```\n
- 961\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: hash table */
/* 题目信息 */
/*
 *961. N-Repeated Element in Size 2N Array
In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

Example 1:

Input: [1,2,3,3]
Output: 3
Example 2:

Input: [2,1,2,5,3,2]
Output: 2
Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5

Note:

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length is even
 */

/* my solution */
// 176ms
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N = A.size() / 2;
        map<int, int> mp;
        // find out each number's occurrence number
        for (int i = 0; i < 2 * N; i++)
        {
            mp[A[i]]++;
        }
        
        for (auto e: mp)
        {
            if (e.second == N)
                return e.first;
        }
        
        return 0;
    }
};
// 对整个数组进行遍历，将每个数字出现的次数载入到map中，再对比其中出现次数为N的，返回这个数字。
/* better solution */
// 76ms
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int N = A.size() / 2;
        map<int, int> mp;
        int res;
        // find out each number's occurrence number
        for (int i = 0; i < 2 * N; i++)
        {
            mp[A[i]]++;
            if (mp[A[i]] > 1)
            {
                res = A[i];
                break;
            }
        }
        
        return res;
    }
};
// 因为题目中说一共2N个数字，共N+1个不同的数字，其中一个数字出现了N次，所以可以确定另外N个数字每个只出现了1次，就可以在遍历中缩小步骤。
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 976\n
```cpp
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
/* Type: math */
/* 题目信息 */
/*
 *976. Largest Perimeter Triangle
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.

 

Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8
 

Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 88ms, defeat 77.03%
// 先排序，然后循环遍历判断三条边是否符合三角形
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 3; i >= 0; --i) {
            if (A[i] + A[i + 1] > A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};

/* 一些总结 */
// 1. 题意: 给定一数组，求出在其中三个数值满足三角形的情况下的最大周长
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

```\n
- 977\n
```cpp
#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 977. Squares of a Sorted Array
 * Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
 */

/* my solution */
// 132ms - O(nlogn)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // 1. 先整体平方
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
        // 2. 排序
        sort(A.begin(), A.end());
        return A;
    }
};

/* better solution */
// 48ms - O(n)
// 双指针
// 一个指针在数组最坐，一个在最右，当左指针所指元素值的平方大于右指针所指元素值的平方，将左指针元素值平方放入新开的大小为n的数组的最后一个位置，反之亦然。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;)
        {
            if (A[i] * A[i] > A[j] * A[j])
            {
                res[pos] = A[i] * A[i];
                i++;
            }
            else
            {
                res[pos] = A[j] * A[j];
                j--;
            }
            pos--;
        }
        return res;

    }
};
// 讨论区有更好的解，但是我没有看懂
/* 一些总结 */

```\n
- 98\n
```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */

/* my solution */
// ✗
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
private:
    bool helper(TreeNode* root, TreeNode* lower, TreeNode* upper)
    {
        if (!root) return true;
        if (lower && root->val <= lower->val) return false;
        if (upper && root->val > upper->val) return false;
        
        if (!helper(root->left, lower, root)) return false;
        if (!helper(root->right, root, upper)) return false;
        
        return true;
    }
};
// 上边这段程序不知出了什么问题，通不过
// 在63行少了一个等号，添加了之后就可以了。

/* better solution */
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* nmin = nullptr, TreeNode* nmax = nullptr) {
        if(!root) 
            return true;
        if(nmin && root->val <= nmin->val)
            return false;
        if(nmax && root->val >= nmax->val)
            return false;
        return isValidBST(root->left, nmin, root) && isValidBST(root->right, root, nmax);
    }
};

// 2
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
        
    }
private:
    bool helper(TreeNode* root, long min_val, long max_val)
    {
        if (!root) return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return helper(root->left, min_val, root->val) &&
            helper(root->right, root->val, max_val);
        
    }
};
// 如果LLONG_MIN和LLONG_MAX没有用怎么办
// 需要注意下边这种方法中指针和取地址的操作，很容易错
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr); // 避免使用数据类型，用空指针来表示无穷大和无穷小
        
    }
private:
    bool helper(TreeNode* root, int *min_val, int *max_val)
    {
        if (!root) return true;
        if ((min_val && *min_val >= root->val) || 
           (max_val && *max_val <= root->val))
            return false;
        return helper(root->left, min_val, &root->val) &&
            helper(root->right, &root->val, max_val);
    }
};

// 使用BST性质,这种最容易理解
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev_ = nullptr;
        return inorder(root);
    }
private:
    TreeNode* prev_;
    bool inorder(TreeNode* root)
    {
        if (!root) return true;
        if (!inorder(root->left))  // 这句不好写出来
            return false;
        if (prev_ && prev_->val >= root->val)  // 因为是排序过的，所以只需要比较当前结点和上一个结点的值就可以了
            return false;
        prev_ = root;              // 这一步也很容易漏掉
                                   // 总是把这一步给忘掉
        return inorder(root->right);
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 多个||和&&，注意添加括号
// 2. 
// 3. 

```\n
- 989\n
```cpp
#//include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *989. Add to Array-Form of Integer
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Note：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
 */

/* my solution */


/* better solution */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int N = A.size();
        int cur = K;
        vector<int> res;

        int i = N;
        while (--i >= 0 || cur > 0)
        {
            if (i >= 0)
                cur += A[i];
            res.push_back(cur % 10);
            cur /= 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- 99\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: tree */
/* 题目信息 */
/*
 *99. Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
 */

/* my solution */


/* better solution */
// solution 1: 中序遍历BST，重新排序得到的数组，将之赋值为原来的树。
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        vector<TreeNode*> nodeList;
        inorder(root, nums, nodeList);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            nodeList[i]->val = nums[i];
        }
        
    }
private:
    void inorder(TreeNode* root, vector<int>& nums, vector<TreeNode*>& nodeList)
    {
        if (!root) return;
        inorder(root->left, nums, nodeList);
        nums.push_back(root->val);
        nodeList.push_back(root);
        inorder(root->right, nums, nodeList);
    }
};


// solution 2
class Solution {
public:
    void recoverTree(TreeNode* root) {
        pre_ = nullptr;
        first_ = nullptr;
        second_ = nullptr;
        inorder(root);
        if (first_ && second_)
            swap(first_->val, second_->val);
        
    }
private:
    TreeNode* pre_;
    TreeNode* first_;
    TreeNode* second_;
    
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        if (!pre_) pre_ = root;
        else
        {
            if (pre_->val > root->val)
            {
                if (!first_)
                    first_ = pre_;
                second_ = root;
            }
            pre_ = root;
        }
        inorder(root->right);
    }
};
/* 一些总结 */
// 1. 题意: 给定一颗BST，但是这颗树中有些值不符合BST定义，将之调整成为正确的BST.
//
// 需要注意的点: 
// 1. 第二种方法还没看懂
// 2. 
// 3. 

```\n
- 993\n
```cpp
// 993. Cousins in Binary Tree
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
/*

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:
     1
   /  \
  2   3
 /
 4

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
         1
       /   \
     2      3
      \      \ 
      4       5

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:
         1
       /   \
     2       3
       \
         4

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
*/


// my solution
// none

// better solution
// 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int xdepth, ydepth, xparent, yparent;
    void depth(TreeNode* root, int x, int y, int dep, int par_val)
    {
        if (!root) return;
        if (root->val == x)
        {
            xdepth = dep;
            xparent = par_val;
            return;
        }
        if (root->val == y)
        {
            ydepth = dep;
            yparent = par_val;
            return;
        }
        depth(root->left, x, y, dep+1, root->val);
        depth(root->right, x, y, dep+1, root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y)
            return false;
        depth(root, x, y, 0, 0);
        
        if (xdepth == ydepth && xparent != yparent)
            return true;
        
        return false;
    }
};

// 2 ✓
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        preorder(root, x, y, nullptr, 0);
        return px_ != py_ && dx_ == dy_;
    }
private:
    TreeNode* px_; // x's parent
    TreeNode* py_;
    int dx_; // x's depth
    int dy_;
    
    void preorder(TreeNode* root, int x, int y, TreeNode* p, int d)
    {
        if (!root) return;
        if (root->val == x)
        {
            px_ = p;
            dx_ = d;
        }
        if (root->val == y)
        {
            py_ = p;
            dy_ = d;
        }
        
        preorder(root->left, x, y, root, d + 1);
        preorder(root->right, x, y, root, d + 1);
    }
};

// 1. dfs
```\n
- nc102\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。 
示例1
输入
[3,5,1,6,2,0,8,#,#,7,4],5,1
返回值
3
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 1214ms
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return helper(root, o1, o2)->val;
    }
private:
    TreeNode* helper(TreeNode* root, int o1, int o2)
    {
         if (!root || root->val == o1 || root->val == o2)
            return root;
        // find in left subtree
        root->left = helper(root->left, o1, o2);
        root->right = helper(root->right, o1, o2);
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;
        return root;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意题目中是二叉树，不是BST
// 2. 这道题和leetcode上的那道题不一样，返回的是结点的值。
// 3. 

```\n
- nc105\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* NowCoder */
/* Type:  binary search*/
/* 题目信息 */
/*
 *题目描述
 请实现有重复数字的有序数组的二分查找。
 输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
 示例1
 输入
 5,4,[1,2,4,4,5]
 输出
 3
 */

/* my solution */


/* better solution */
class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (v <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low == n)
            return n + 1;
        return low + 1; // 这里返回的为什么是low + 1, 为什么要加一。
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- nc119\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
示例1
输入 [4,5,1,6,2,7,3,8],4
返回值 [1,2,3,4]
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1
// 直接排序选取前k
// 注意边界条件，一个边界条件可能用例就通不过超80%
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        sort(input.begin(), input.end());
        if (k > input.size()) // 注意这一句
            return {};
        for (int i = 0; i < k; i++)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};

// solution-2, 3ms
// 优先队列

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size())
            return res;
        priority_queue<int, vector<int> > pq;
        for (int val : input)
        {
            if (pq.size() < k)
            {
                pq.push(val);
            }
            else
            {
                if (val < pq.top())
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- nc61\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Nowcoder */
/* Type:  */
/* 题目信息 */
/*
 *题目描述
给出一个整数数组，请在数组中找出两个加起来等于目标值的数，
你给出的函数twoSum 需要返回这两个数字的下标（index1，index2），需要满足 index1 小于index2.。注意：下标是从1开始的
假设给出的数组中只存在唯一解
例如：
给出的数组为 {20, 70, 110, 150},目标值为90
输出 index1=1, index2=2


示例1
输入
[3,2,4],6
返回值
[2,3]
 */

/* my solution */
// solution-1, 4ms
// hash

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int, int> mp;  // value: index
        for (int i = 0; i < numbers.size(); i++)
            mp[numbers[i]] = i + 1;
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
        {
            int remaining = target - numbers[i];
            //res.erase(res.begin(), res.end());
            res.clear();
            res.push_back(i+1);
            if (mp.count(remaining) && (i+1) != mp[remaining])
            {
                res.push_back(mp[remaining]);
                break;
            }

        }
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 注意索引是从1开始的
// 2. 
// 3. 

```\n
- offer07\n
```cpp
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

```\n
- offer09\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: Stack */
/* 题目信息 */
/*
 *剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */


/* better solution */
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if (stk2.empty())
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        
        if (stk2.empty())
        {
            return -1;
        }
        else
        {
            int res = stk2.top();
            stk2.pop();
            return res;
        }
        

    }
private:
    stack<int> stk1;
    stack<int> stk2;
};


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 不必看上边输入输出样例，很懵。
// 2. 两个栈实现队列，一个实现入队操作，一个实现出队操作，剩下的就是一些控制语句。
// 3. 

```\n
- offer10\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* offer */
/* Type: math */
/* 题目信息 */
/*
 *剑指 Offer 10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
 

提示： 0 <= n <= 100
 */

/* my solution */


/* better solution */
class Solution {
public:
    int constant = 1000000007;
    int fib(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        int temp = 0;

        for (int i = 2; i <= n; i++)
        {
            temp = first + second;
            first = second % constant;
            second = temp % constant;
        }
        
        return temp % constant;
    }
};

/* 一些总结 */
// 1. 题意: fib求解。
//
// 需要注意的点: 
// 1. 注意题目中最后注明的有一个取余的操作。
// 2. 不仅可以使用数组，而且可以使用first, second变量记录求取元素的前两个值，这两个值不断迭代。
// 3. 

```\n
- offer16\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: bit */
/* 题目信息 */
/*
 *剑指 Offer 16. 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

 

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
 

说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 0ms, defeat 100%
// 位运算
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1.0;
        if (x == 0 && n < 0) return 0.0;
        double res = 1.0;
        long exp = n;
        if (n < 0)
        {
            x = 1 / x;
            exp = -exp;
        }
        
        while (exp)
        {
            // &操作判断奇偶
            if (exp & 1) res *= x;
            x *= x;
            exp >>= 1;
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 位运算很不熟
// 2. 一些边界情况需要考虑
// 3. 

```\n
- offer17\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 17. 打印从1到最大的n位数
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：
用返回一个整数列表来代替打印
n 为正整数
 */

/* my solution */
// solution-1, 8ms, defeat 93.50%
// 没有考虑大数问题!
class Solution {
public:
    vector<int> printNumbers(int n) {
        int num = pow(10, n);
        vector<int> res;
        for (int i = 1; i < num; i++)
            res.push_back(i);
        return res;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer33\n
```cpp
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

```\n
- offer39\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制： 1 <= 数组长度 <= 50000
 */

/* my solution */
// solution-1, 44ms, defeat 75.70%
// 使用map找每个数字的频次，然后再遍历，找到频次符号条件的数字返回。
// O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        for (auto e : mp)
        {
            if (e.second > nums.size() / 2)
                return e.first;
        }
        return -1;
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer40\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: heap */
/* 题目信息 */
/*
 *剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 */

/* my solution */
// solution-1, 88ms, defeat 59.75%
// 整体排序后选取前k个值。
// O(nlogn)即排序的时间复杂度
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // 1. sort
        sort(arr.begin(), arr.end());
        // 2. k
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};

/* better solution */
// solution-2, 120ms, defeat 31.11%
// max heap
// O(nlogk): n个输入数字，树高为logk, 插入数据到树中为logk
// 
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        priority_queue<int> pq;
        // 先导入k个值
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }
        // 比较当前值和堆顶元素大小
        for (int i = k; i < arr.size(); i++)
        {
            if (pq.top() > arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++)
        {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer41\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: heap */
/* 题目信息 */
/*
 *剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制： 最多会对 addNum、findMedian 进行 50000 次调用。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap; // default is max heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 1. push element into maxHeap
        maxHeap.push(num);
        // 2. then pop the max value of maxHeap, push it into the minHeap
        int x = maxHeap.top(); maxHeap.pop();
        minHeap.push(x);
        if (maxHeap.size() < minHeap.size())
        {
            int y = minHeap.top(); minHeap.pop();
            maxHeap.push(y);
        }

    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) * 0.5;
        else
            return maxHeap.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer42\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
 */

/* my solution */
// solution-1, ms, defeat %
// brute force 
// time limited
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute force
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

/* better solution */
// solution-2, 64ms, defeat 13.81%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前和小于等于0, 则放弃当前和，重新将当前元素值赋值给当前和。
            if (curSum <= 0)
                curSum = nums[i];
            else
                curSum += nums[i];
            // 更新当前最大和。
            maxSum = max(maxSum, curSum);
        }
        return maxSum;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer43\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type:  */
/* 题目信息 */
/*
 *剑指 Offer 43. 1～n 整数中 1 出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
// brute force 
// time limited
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << getOnes(n) << endl;
            res += getOnes(i);
            //cout << res << endl;
        }
        return res;
    }
private:    
    int getOnes(int num)
    {
        int oneNumber = 0;
        while (num)
        {
            if (num % 10 == 1)
                oneNumber++;
            num /= 10;
        }
        return oneNumber;
    }
        
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer53\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: binary search */
/* 题目信息 */
/*
 *剑指 Offer 53 - I. 在排序数组中查找数字 I
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000
 */

/* my solution */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = binarySearch(nums, target);
        cout << "idx: " << idx << endl;
        if (idx == -1)
            return 0;
        int res = 1;
        for (int i = idx + 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
                res++;
        }
        return res;

    }
private:
    int binarySearch(vector<int> nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                while (nums[res - 1] == target)
                    res--;
            }
            if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return res;
    }
    
};

// solution-2 32ms defeat 10.79%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        if (mp.count(target))
            return mp[target];

        return 0;

    }
};
/* better solution */
// solution-3 20ms defeat 64.76%
// 1. 找到target第一次出现的下标
// 2. 找到target最后一次出现的下标
// 3. 返回last - first + 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int first = getFirstT(nums, len, 0, len - 1, target);
        //cout << num << endl;
        int last = getLastT(nums, len, 0, len - 1, target);
        
        cout << "first: " << first << endl;
        cout << "last: " << last << endl;
        int res = 0;
        if (first > -1 && last > -1)
            res = last - first + 1;

        return res;
    }
private:    
    int getFirstT(vector<int> nums, int len, int low, int high, int target)
    {
        if (low > high)
            return -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            //int mid = (low + high) / 2;
            int mid_data = nums[mid];
            if (mid_data == target)
            {
                if (mid > 0 && nums[mid - 1] != target || mid == 0) // 注意这个条件
                    return mid;
                else
                    high = mid - 1;
            }
            else if (mid_data > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1; 
    }
    int getLastT(vector<int> nums, int len, int low, int high, int target)
    {
        if (low > high)
            return -1;
        //int mid_index = low + (high)
        while (low <= high)
        {
            int mid_index = low + (high - low) / 2;
            int mid_data = nums[mid_index];
            if (mid_data == target)
            {
                if (mid_index < len - 1 && nums[mid_index + 1] != target || mid_index == len - 1) // 注意这个条件
                    return mid_index;
                else
                    low = mid_index + 1;
            }
            else if (mid_data > target)
                high = mid_index - 1;
            else
                low = mid_index + 1;
        }
            

        
        return -1;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer53_2\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: binary search */
/* 题目信息 */
/*
 *剑指 Offer 53 - II. 0～n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 */

/* my solution */
// solution-1: 36ms defeat 91.37%
// 1. 如果数组中缺失数据，使用循环找出返回。
// 2. 如果数组完整不缺，则返回数组长度。
// O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int cnt = -1;
        for (int i = 0; i < len; i++)
        {
            cnt++;
            if (nums[i] != i)
                return i;
        }
        if (cnt == len - 1)
            return len;
        return -1;
    }
};

/* better solution */
// solution-2: 48ms defeat 24.27%
// 1. 使用binary search
// 2. 如果当前下标和当前值相同，检查数组右半边
// 3. 如果不同，向前查找
// 4. 如果前一个下标和对应值相同，则返回
// 5. 如果不同，则检查数组左半边
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return -1;
        int low = 0, high = len - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] != mid)
            {
                if (mid == 0 || nums[mid - 1] == mid - 1)
                    return mid;
                else
                    high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (low == len)
            return len;
        return -1;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 可能是因为数据量小的原因，所以binary search耗费时间大于遍历耗费时间。
// 2. 
// 3. 

```\n
- offer56-1\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: array */
/* 题目信息 */
/*
 *剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000
 */

/* my solution */
// solution-1: 124ms, defeat 5.48%
// 1. 使用hash表记录每个数字频次
// 2. 找到品次为1的数字
// 3. 返回它们。
// O(n)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        vector<int> res;
        for (auto e : mp)
        {
            if (e.second == 1)
                res.push_back(e.first);
        }
        return res;
    }
};

/* better solution */
// solution-2: 异或


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer57-2\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: two pointers */
/* 题目信息 */
/*剑指 Offer 57 - II. 和为s的连续正数序列
 *输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
// 超时
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3)
            return {{}};
        int l = 1, r = 2;
        int mid = (1 + target) / 2;
        int curSum = l + r;
        vector<int> temp;
        vector<vector<int>> res;
        while (l < r)
        {
            if (curSum == target)
            {
                for (int i = l; i <= r; i++)
                    temp.emplace_back(i);
                res.emplace_back(temp);
                
                while (curSum > target && l < mid)
                {
                    curSum -= l;
                    l++;
                    if (curSum == target)
                    {
                        for (int i = l; i <= r; i++)
                            temp.emplace_back(i);
                        res.emplace_back(temp);
                    }
                }
                r++;
                curSum += r;
            }
        }
        
        return res;
    }
};

/* 一些总结 */
// 2连续序列. 题意: 求一个数的连续求和序列
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer57\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: math */
/* 题目信息 */
/*
 *剑指 Offer 57. 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
 

限制：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
 */

/* my solution */
// solution-1: 1828ms, defeat 5%
// 1. 使用map记录某个值是否出现
// 2. 遍历数组，找到另一个值是否存在
// O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i : nums)
            mp[i] = 1;
        for (int i : nums)
        {
            int remaining = target - i;
            if (mp[remaining] == 1)
                return {remaining, i};
        }
        return {};
    }
};

/* better solution */
// solution-2: 420ms, defeat 95.84%
// two pointers
// 1. 初始指针在数组两端
// 2. 当指针所指的值的和大于target时，和需要小一些，使right--;
// 3. 当指针所指的值的和小于target时, 和需要大一些，使left++;
// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
                return {nums[left], nums[right]};
        }
        return {};
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer58-1\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: two pointers */
/* 题目信息 */
/*
 *输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 8ms, defeat 86.38%
// 1. 双指针初始都在字符串最右边
// 2. 从右向左扫描，每次扫描完一个单词就加入到结果中
// 3. 麻烦的是最后的空格的处理，需要自己进行处理一下。
class Solution {
public:
    string reverseWords(string s) {
        int r = s.size() - 1;
        int l = s.size() - 1;
        string res = "";
        while (l >= 0)
        {
            while (l >= 0 && s[l] != ' ') l--;
            res += s.substr(l + 1, r - l);
            cout << s.substr(l+1, r-l) << endl;
            cout << "l: " << l << endl;
            res += " ";
            // 跳过空格
            while (l >= 0 && s[l] == ' ') l--;
            r = l; // r指向下个单词的词尾
        }
        // remove the first space
        if (res.size() > 0 && res[0] == ' ')
            res.erase(res.begin());
        // remove the last space
        if (res.size() > 0 && res[res.size() - 1] == ' ')
            res.erase(res.begin() + res.size() - 1);
        
        return res;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer58-2\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: string */
/* 题目信息 */
/*
 *剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000

 */

/* my solution */
// solution-1, 4ms, defeat 92.74%
// 1. substr()
// 2. erase()
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp = s.substr(0, n);
        s += temp;
        s.erase(s.begin(), s.begin() + n);
        return s;

    }
};

// solution-2
// 1. 使用循环进行。
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res = "";
        for (int i = n; i < s.size(); i++) res += s[i];
        for (int i = 0; i < n; i++) res += s[i];
        return res;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer59-1\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: 滑动窗口 */
/* 题目信息 */
/*
 *剑指 Offer 59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 */

/* my solution */
// solution-1, 252ms, defeat 12.25%
// brute force
// 1. 使用循环遍历
// O(nk)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};
        int len = nums.size();
        vector<int> res;
        for (int i = 0; i <= len - k; i++)
        {
            int maxVal = INT_MIN;
            for (int j = i; j < i + k; j++)
            {
                if (nums[j] > maxVal)
                    maxVal = nums[j];
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

/* better solution */
// solution-2, 32ms, defeat 97.11%
// monotonic queue(单调队列), 
// deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return res;
        // monotonic queue
        deque<int> q; // only indexes are stored
        for (int i = 0; i < n; i++)
        {
            // 1. 超过范围
            while (!q.empty() && (i - q.front()) >= k)
                q.pop_front();
            // 2. 当前元素值大于队列最后一个值
            while (!q.empty() && nums[i] > nums[q.back()])
                q.pop_back();
            q.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;

    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
- offer59-2\n
```cpp
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: queue */
/* 题目信息 */
/*
 *剑指 Offer 59 - II. 队列的最大值
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 256ms, defeat 95.75%
// brute force
// 使用一个数组，感觉类似双端队列
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;
public:
    MaxQueue() {

    }
    
    int max_value() {
        int res = -1;
        for (int i = begin; i != end; i++)
        {
            res = max(res, q[i]);
        }
        return res;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};
// solution-2
// deque
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (d.empty())
            return -1;
        return d.front();

    }
    
    void push_back(int value) {
        while (!d.empty() && value > d.back())
            d.pop_back();
        d.push_back(value);
        q.push(value);

    }
    
    int pop_front() {
        if (q.empty())
            return -1;
        int num = q.front();
        if (num == d.front())
            d.pop_front();
        q.pop();
        return num;
    }
};


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

```\n
