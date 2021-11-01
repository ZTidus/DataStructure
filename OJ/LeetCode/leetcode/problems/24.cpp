#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
 */

/* my solution */


/* better solution */
// iterative 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevNode = dummy;
        
        while (head && head->next)
        {
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;
            
            // swap
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            
            prevNode = firstNode;
            head = firstNode->next;
        }
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 自己手动模拟即可
// 2. 
// 3. 

