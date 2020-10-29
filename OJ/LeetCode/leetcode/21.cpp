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


