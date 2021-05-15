/*
 * @Descroption: LeetCode 876. 链表的中间结点
 * @Author: EmoryHuang
 * @Date: 2021-04-25 15:24:36
 * @解题思路:
 * 简单题，设置快慢指针
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
    ListNode* middleNode(ListNode* head) {
        ListNode *q = head, *p = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};