#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 * 141. Linked List Cycle
 *
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

3 -> 2 -> 0 -> -4
     ^          |
     |          |
     ------------
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
   bool hasCycle(ListNode *head) {
	   if (head == NULL || head->next == NULL)
		   return false;
	   ListNode *fast = head, *slow = head;
	   while (fast && fast->next)
	   {
		   fast = fast->next->next;
		   slow = slow->next;
		   
		   if (fast == slow)
			   return true;
	   }
	   
	   return false;
   }
};

/* 一些总结 */
// [题意]查看链表中有没有环。two pointers, 在操场上慢跑，一个快，一个慢，快的每次两个结点，慢的一个结点，如果有环，肯定会相遇。
