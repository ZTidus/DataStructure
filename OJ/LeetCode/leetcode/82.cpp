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

