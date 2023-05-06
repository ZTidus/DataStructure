
# golden_0203
type:

difficulty:

---

## [Problem Info][problem_link]
给定一结点node，在链表中删除此结点。

## Attention

## Answer - 1
复制大法。简单来说就是替换掉要删除的结点。

- java
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val; // 将下一结点的值复制到要删除的结点
        node.next = node.next.next; 
    }
}
```

- time: ms
- beat %
- big O:

## Answer - 2

[problem_link]:

