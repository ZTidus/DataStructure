/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

/* algorithms	Medium (42.78%)	3000	140
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
// @lc code=start
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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        vector<int> nums;
        to_vector(head, nums);
        sort(nums.begin(), nums.end());
        ListNode* yummy = new ListNode(-1);
        ListNode* cur = yummy;
        for (int i : nums)
        {
            cur->next = new ListNode(i);
            cur = cur->next;
        }

        return yummy->next;
    }
private:
    void to_vector(ListNode* head, vector<int>& nums)
    {
        if (!head) return;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
    }
};
// @lc code=end

