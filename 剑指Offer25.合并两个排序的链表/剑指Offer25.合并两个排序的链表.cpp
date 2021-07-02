/*
 * @Descroption: ��ָ Offer 25. �ϲ��������������
 * @Author: EmoryHuang
 * @Date: 2021-07-02 14:49:00
 * @����˼·:
 * ��������⣬���αȽ���������Ԫ�ش�С
 * ����һ������
 * ���������ݹ�
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
    // ����һ������
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     ListNode *head = new ListNode(-1), *pre = head;
    //     while (l1 && l2) {
    //         if (l1->val < l2->val) {
    //             pre->next = l1;
    //             l1 = l1->next;
    //         } else {
    //             pre->next = l2;
    //             l2 = l2->next;
    //         }
    //         pre = pre->next;
    //     }
    //     pre->next = l1 ? l1 : l2;
    //     return head->next;
    // }

    // ���������ݹ�
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
};