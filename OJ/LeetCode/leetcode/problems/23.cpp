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
 * 23. Merge k Sorted Lists
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
 */

/* my solution */


/* better solution */
// solution 1 ✓:
// 将几个链表中元素的值导入到新的数组中，将数组排序，然后生成新的链表，返回即可。
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            
            ListNode* first = lists[i];
            while (first)
            {
                nums.push_back(first->val);
                first = first->next;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        for (int i = 0; i < nums.size(); i++)
        {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};

// solution 2: priority queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* first = lists[i];
            while (first)
            {
                pq.push(first->val);
                first = first->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;
        ListNode* cur = dummy;
        while (!pq.empty())
        {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }
        
        return dummy->next;
    }
};

// solution 3: use merge two sorted list
// divide and conquer
class solution {
public:
    listnode* mergeklists(vector<listnode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
        
    }
private:
    listnode* merge(vector<listnode*>& lists, int l, int r)
    {
        
        if (l > r) return nullptr;
        if (l == r) return lists[l]; // 注意这一句
        if (l + 1 == r) return mergetwosortedlists(lists[l], lists[r]); // 注意这一句
        int m = l + (r - l) / 2;
        listnode* l1 = merge(lists, l, m);
        listnode* l2 = merge(lists, m + 1, r);
        return mergetwosortedlists(l1, l2);
    }
    listnode* mergetwosortedlists(listnode* l1, listnode* l2)
    {
        listnode* dummy = new listnode(-1);
        listnode* tail = dummy;
        
        while (l1 && l2)
        {
            if (l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 多个输入，一个输出，类似漏斗，可以使用小顶堆
// 2. 
// 3. 

