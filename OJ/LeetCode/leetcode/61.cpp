#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: Linked list */
/* 题目信息 */
/*
 *61. Rotate List
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */

/* my solution */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        // len
        int len = 0;
        ListNode* cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        k %= len;
        if (k == 0) return head; // !!!
        int process = len - k;
        ListNode* prev = head;
        while (--process)
            prev = prev->next;
        ListNode* newHead = prev->next;
        prev->next = nullptr;
        cur = newHead;
        while (cur->next)
            cur = cur->next;
        cur->next = head;
        
        return newHead;
    }
};

/* better solution */


/* 一些总结 */
// 1. 题意: 给定链表和一个k值，把链表顺时针循环移动k次
//
// 需要注意的点: 
// 1. 重要的点就是k = k % len, 这个取余需要注意。循环移动k次 ↔ 循环移动k%len次
// 2. 还有一些边界条件例如k%len == 0时，直接返回head即可，等价于没有移动。
// 3. 

