#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        
        int carry = 0; 
        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            cur->next = new ListNode(sum);
            cur = cur->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
            cur->next = new ListNode(carry);
        
        return head->next;
    }
};

// 2
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        int carry = 0;
        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
                carry = 0;
            tail->next = new ListNode(sum);
            tail = tail->next;
            
            //if (l1) l1 = l1->next;
            //if (l2) l2 = l2->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry)
            tail->next = new ListNode(carry);
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. dummy head
// 2. l1 = l1 ? l1->next : nullptr;
