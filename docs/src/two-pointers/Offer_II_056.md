
# Offer_II_056
type: two pointers

difficulty: easy

---

## [Problem Info][problem_link]
给定一BST，和一整数k，查看树中是否有两个数字只和为k。

## Attention

## Answer - 1
先中序遍历得有序数组，对有序数组进行双指针查找。

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
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> nodeList = new ArrayList<>();
        inorder(root, nodeList);
        int left = 0;
        int right = nodeList.size() - 1;
        boolean res = false;
        while (left < right) {
            int num1 = nodeList.get(left);
            int num2 = nodeList.get(right);
            if (num1 + num2 < k) {
                left++;
            } else if (num1 + num2 > k) {
                right--;
            } else {
                res = true;
                break;
            }
        }
        return res;
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
- time: 2ms
- beat 97.90%
- big O:

## Answer - 2

[problem_link]: https://leetcode-cn.com/problems/opLdQZ/

