#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:   a1 -> a2 
              \
               c1 -> c2 -> c3
              /
B: b1->b2->b3

begin to intersect at node c1.

 

Example 1:

A:   4 -> 1 
              \
               8 -> 4 -> 5
              /
B: 5->6->1

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Each value on each linked list is in the range [1, 10^9].
Your code should preferably run in O(n) time and use only O(1) memory.
 */

/* my solution */
// none

/* better solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int countA = 0, countB = 0;
        
        // compute len of list A
        while (curA)
        {
            curA = curA->next;
            countA++;
        }
        
        // compute len of list B
        while (curB)
        {
            curB = curB->next;
            countB++;
        }
        
        // find out the longer one 
        int diff = abs(countA - countB);
        if (countB > countA)
            swap(headA, headB);
        
        while (diff--)
        {
            headA = headA->next;
        }
        
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};

/* 一些总结 */
// 1. [题意]寻找两个链表相同部分的第一个结点。two pointers, 计算两个的长度，让指针向前走，是当前长度相同，当两个指针相同时，返回即可
// 2. the diff should be positive

