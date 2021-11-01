#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: Linked List */
/* 题目信息 */
/*
 *92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

/* my solution */


/* better solution */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre, *front, *last;
        // cur to m
        for (int i = 0; i < m - 1; i++) cur = cur->next;
        pre = cur;
        last = cur->next;
        
        for (int i = m; i <= n; i++) // 注意是<=n
        {
            cur = pre->next;
            pre->next =  cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 循环的那四步是怎么想出来的???自己动手模拟了一遍，看懂了，但是肯定写不出来
// 2. 
// 3. 

