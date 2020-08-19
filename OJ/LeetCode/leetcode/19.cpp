#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        int len = computeLen(head);
        int processNum = len - n - 1;
        printf("%d\n", processNum);
        ListNode* cur = head;
        while (processNum--)
        {
            cur = cur->next;
        }
        printf("%d \n", cur->val);
        cur->next = cur->next->next;
        
        return head;
    }
private:
    int computeLen(ListNode* head)
    {
        if (!head) return 0;
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
};
// 不知道问题在哪？提交说有nullptr

/* better solution */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head;
        int len = 0;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        int processNum = len - n;
        cur = dummy;
        while (processNum--)
            cur = cur->next;
        cur->next = cur->next->next;
        
        return dummy->next;
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

