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

/* 一些总结 */
// 1. 第一步判断想到了，就是44到45这个判断。

