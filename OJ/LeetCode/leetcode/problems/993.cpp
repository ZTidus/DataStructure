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
