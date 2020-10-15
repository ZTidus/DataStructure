#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Leetcode */
/* Type: linked list */
/* 题目信息 */
/*
 *142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

 

Example 1:
3 → 2 → 0 → -4
    |        |
    ---------
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */

/* my solution */


/* better solution */
// solution 1 : 利用哈希表保存访问过的节点,
// 同时遍历过程中检查哈希表中是否已存在相同的节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mp;
        ListNode* cur = head;
        while (cur)
        {
            if (mp.count(cur))
                return cur;
            mp[cur]++;
            cur = cur->next;
        }
        
        return NULL;
        
    }
};

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 一开始使用快慢指针做，但是结果不对，不知道是什么原因?
// 2. 
// 3. 

