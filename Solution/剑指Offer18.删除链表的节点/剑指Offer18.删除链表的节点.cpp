/*
 * @Descroption: 剑指 Offer 18. 删除链表的节点
 * @Author: EmoryHuang
 * @Date: 2021-06-27 15:53:00
 * @解题思路:
 * 简单题，链表基础题
 */

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return head;
        if (head->val == val) return head->next;
        head->next = deleteNode(head->next, val);
        return head;
    }
};