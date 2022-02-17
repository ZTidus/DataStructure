
# LCP_44
type: tree

difficulty: easy

---

## [Problem Info][problem_link]
给定一二叉树，寻找二叉树中的值的种类数。

## Answer - 1

- java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    Set<Integer> nodeValSet = new HashSet<>();
    public int numColor(TreeNode root) {
        preorder(root);
        return nodeValSet.size();
    }
    private void preorder(TreeNode root) {
        if (root == null) return;
        nodeValSet.add(root.val);
        if (root.left != null) {
            preorder(root.left);
        }
        if (root.right != null) {
            preorder(root.right);
        }
    }
}
```

- time: ms
- beat %
- big O:

## Answer - 2

## Attention
- 使用 set 去进行过滤。

[problem_link]: https://leetcode-cn.com/problems/sZ59z6/

