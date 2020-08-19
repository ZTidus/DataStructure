#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *
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

