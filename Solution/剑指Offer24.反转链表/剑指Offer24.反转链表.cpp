/*
 * @Descroption: ��ָ Offer 24. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-07-01 18:53:00
 * @����˼·:
 * ��������ָ�룬preָ��գ�curָ��head
 * next�ݴ�cur.next��ͷ�巨��ת
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};