#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: linked list */
/* 题目信息 */
/*
 *147. Insertion Sort List
Sort a linked list using insertion sort.
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
 */

/* my solution */
// solution-1, 116ms, defeat 8.84%
// 将链表转化为数组，然后使用插入排序，再转化为链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        insertionSort(nums);
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
private:    
    void insertionSort(vector<int>& R)
    {
        int temp;
        for (int i = 1; i < R.size(); i++)
        {
            temp = R[i];
            int j = i - 1;
            while (j >= 0 && temp < R[j])
            {
                R[j + 1] = R[j];
                j--;
            }
            R[j + 1] = temp;
        }
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

