#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        
        ListNode* Temp = new ListNode(0);
        Temp->next = nullptr;
        int carry = 0, num1 = 0, num2 = 0;
        
        while (!s1.empty() || !s2.empty() || carry)
        {
            if (!s1.empty())
            {
                num1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                num2 = s2.top();
                s2.pop();
            }
            
            int sum = num1 + num2 + carry;
            int value = sum % 10;
            carry = sum / 10;
            
            num1 = 0;
            num2 = 0;
            
            ListNode* newNode = new ListNode(value);
            newNode->next = Temp->next;
            Temp->next = newNode;
        }
        
        return Temp->next;
        
    }
};

/* 一些总结 */
// 1. 头插法

