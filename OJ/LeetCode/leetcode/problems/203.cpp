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

