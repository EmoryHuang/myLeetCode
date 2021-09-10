/*
 * @Descroption: LeetCode 203. 移除链表元素
 * @Author: EmoryHuang
 * @Date: 2021-03-21 14:22:36
 * @解题思路: 链表基础题，删除链表中值为 val 的元素
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = head, *pre = dummy;
        while (p) {
            if (p->val == val) {
                ListNode *del = p;
                p = p->next;
                pre->next = p;
                delete del;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};