#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *1669. Merge In Between Linked Lists
 */

/* my solution */
// solution-x, ms, defeat %
 // Definition for singly-linked list.
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur = new ListNode(-1);
        ListNode* cur1 = list1;
        int len1 = 0;
        
        ListNode* last = new ListNode(-1);
        while (cur1) {
            len1++;
            cur1 = cur1->next;
            if (len1 == b)
                last->next = cur1->next;
        }
        
        int cnt = 0;
        cur = list1;
        while (cur) {
            if (cnt == a - 1) {
                cur->next = list2;
            }
            cnt++;
            
            if (cur->next == NULL) // 使cur指向第二个链表末端
                break;
            cur = cur->next;
        }
        cur->next = last->next;
        
        return list1;
    }
};
/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 截取链表并粘连链表
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    return 0;
}

