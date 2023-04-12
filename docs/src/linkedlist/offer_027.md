
# offer_027
type:

difficulty:

---

## [Problem Info][problem_link]
给定一链表，看链表是不是回文链表。

## Attention

## Answer - 1
先将链表转化为数组，再用双指针。

- java
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> nodeList = new ArrayList<>();

        while (head != null) {
            nodeList.add(head.val);
            head = head.next;
        }

        int l = 0, r = nodeList.size()-1;

        while (l < r) {
            if (nodeList.get(l) != nodeList.get(r)) {
                return false;
            }
            
            l++;
            r--;
        }
        return true;
    }
}
```

- time: ms
- beat 51.55%
- big O:

## Answer - 2

[problem_link]:

