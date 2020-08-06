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
                break;
            } 
            else if (!l1)
            {
                head->next = l2;
                break;
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


/* 一些总结 */


