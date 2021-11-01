#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 206. Reverse Linked List
 *Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/* my solution */
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
    ListNode* reverseList(ListNode* head) {
        // 头插法
        ListNode* newHead = new ListNode(0);
        ListNode* node;
        while (head)
        {
            node = head;
            head = head->next;
            
            node->next = newHead->next;
            newHead->next = node;
            

        }
        
        return newHead->next;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 
// 反转链表
// 需要注意的点: 
// 1. 头插法
// 2. 
// 3. 

