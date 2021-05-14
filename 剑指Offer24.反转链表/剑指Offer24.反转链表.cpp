/*
 * @Descroption: LeetCode 206. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-03-18 19:49:36
 * @����˼·: ��ת����ʹ��ͷ�巨
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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *pre = nullptr, *n;
        while (p) {
            n = p->next;
            p->next = pre;
            pre = p;
            p = n;
        }
        return pre;
    }
};