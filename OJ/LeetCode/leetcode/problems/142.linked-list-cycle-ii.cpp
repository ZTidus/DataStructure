// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        ListNode* res;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                res = fast;
                break;
            }
        }
        return res;
        //int index = 0;
        //while (head)
        //{
        //    if (head != res)
        //        index++;
        //}
        //return 
        
    }
};
// @lc code=end

