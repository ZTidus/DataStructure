
# Offer_II_052
type: tree

difficulty: easy

---

## [Problem Info][problem_link]
将BST变成一个只有右孩子节点的树。

## Attention

## Answer - 1

- java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode increasingBST(TreeNode root) {
        List<Integer> nodeList = new ArrayList<>();
        inorder(root, nodeList);
        TreeNode res = new TreeNode();
        TreeNode temp = res;
        for (int i = 0; i < nodeList.size(); i++) {
            temp.right = new TreeNode(nodeList.get(i));
            temp = temp.right;
        }
        return res.right;

    }
    private void inorder(TreeNode root, List<Integer> nodeList) {
        if (root == null) return;
        if (root.left != null) {
            inorder(root.left, nodeList);
        }
        nodeList.add(root.val);
        if (root.right != null) {
            inorder(root.right, nodeList);
        }
    }
}
```
- time: 0ms
- beat 100%
- big O: O(n)

## Answer - 2

[problem_link]: https://leetcode-cn.com/problems/NYBBNL/

