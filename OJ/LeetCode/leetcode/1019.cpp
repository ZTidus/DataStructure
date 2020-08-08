#include <stdio.h>
#include <vector>
using namespace std;

/* Leetcode */
/* 题目信息 */
/*
 *1019. Next Greater Node In Linked List
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.

Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.

 

Example 1:

Input: [2,1,5]
Output: [5,5,0]
Example 2:

Input: [2,7,4,3,5]
Output: [7,0,5,5,0]
Example 3:

Input: [1,7,5,1,9,2,5,1]
Output: [7,9,9,9,0,5,0,0]
 

Note:

1 <= node.val <= 10^9 for each node in the linked list.
The given list has length in the range [0, 10000].
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> input;
        stack<int> s;
        
        while (head)
        {
            input.push_back(head->val);
            head = head->next;  
        }
        
        int size = input.size();
        vector<int> res(size);
        
        for (int i = size-1; i >= 0; i--)
        {
            while (!s.empty() && input[i] >= s.top())
                s.pop();
            if (s.empty())
                res[i] = 0;
            else
                res[i] = s.top();
            
            s.push(input[i]);
        }
        
        return res;
    }
};

/* 一些总结 */
// 1. 一开始我的想法是固定每一次的head，然后遍历head后的每一个值与head做对比，但是显然这样的效率很低。

