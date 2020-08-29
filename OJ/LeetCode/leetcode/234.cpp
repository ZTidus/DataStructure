#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
 */

/* my solution */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = overturn(head);
        vector<int> origin, overturned;
        toVector(head, origin);
        toVector(newHead, overturned);
        
        return origin == overturned;
    }
private:
    void toVector(ListNode* head, vector<int>& v)
    {
        if (!head) return;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    ListNode* overturn(ListNode* head)
    {
        if (!head) return nullptr;
        ListNode* yummy = new ListNode(-1);
        //yummy->next = head;
        while (head)
        {
            ListNode* inserted = new ListNode(head->val);
            inserted->next = yummy->next;
            yummy->next = inserted;
            head = head->next;
        }
        
        return yummy->next;
    }
};

// 将原来的链表和翻转的链表导入数组中进行对比。

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) 
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        
        ListNode* pre = NULL;
        ListNode* cur = slow;
        ListNode* next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        while (pre)
        {
            if (pre->val != head->val)
                return false;
            pre = pre->next;
            head = head->next;
        }
        
        return true;
    }
};

/* 一些总结 */


