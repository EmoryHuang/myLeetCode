/*
 * @Descroption: LeetCode 1721. 交换链表中的节点
 * @Author: EmoryHuang
 * @Date: 2021-07-25 13:54:14
 * @解题思路:
 * 快慢指针
 * 快指针首先前进k - 1个节点，然后快慢指针同时前进
 * 找到倒数第k个节点
 */

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        // 找到正数第k个节点
        for (int i = 0; i < k - 1; i++) fast = fast->next;
        ListNode* l = fast;
        // 找到倒数第k个节点
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(l->val, slow->val);
        return head;
    }
};