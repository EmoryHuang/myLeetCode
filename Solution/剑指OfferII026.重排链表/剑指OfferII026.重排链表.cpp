/*
 * @Descroption: ��ָ Offer II 026. ��������
 * @Author: EmoryHuang
 * @Date: 2021-10-22 14:16:58
 * @Method:
 * �������
 * ����ָ���ҵ��м�ڵ㣬ԭ�ط�ת��벿������Ȼ��������
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
    ListNode* reverse(ListNode *node) {
        ListNode *pre = nullptr, *cur = node;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        // ����ָ���ҵ��м�ڵ�
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *q = slow->next;
        slow->next = nullptr;
        ListNode *p = head;
        // ԭ�ط�ת��벿������
        q = reverse(q);
        // �������
        while (q && p) {
            ListNode *q_nxt = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = q_nxt;
        }
    }
};