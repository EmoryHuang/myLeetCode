/*
 * @Descroption: LeetCode 24. �������������еĽڵ�
 * @Author: EmoryHuang
 * @Date: 2021-03-23 10:23:36
 * @����˼·: �������⣬����һ�Ƚϳ��棬���� p �� pre ����ָ���������ƣ�Ȼ�� ac
 *  ������ʹ���˵ݹ飬�Ƚ�����
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
    // ����һ
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = head, *pre = dummy;
        while (p && p->next) {
            pre->next = p->next;
            p->next = p->next->next;
            pre->next->next = p;
            pre = p;
            p = pre->next;
        }
        return dummy->next;
    }

    // ���������ݹ�
    // ListNode* swapPairs(ListNode* head) {
    //     if (!head || !head->next) return head;  //��ֹ����
    //     ListNode* next = head->next;
    //     head->next = swapPairs(next->next);  //�����Ѿ�������ɺ��������
    //     next->next = head;
    //     return next;
    // }
};
