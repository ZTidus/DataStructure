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

