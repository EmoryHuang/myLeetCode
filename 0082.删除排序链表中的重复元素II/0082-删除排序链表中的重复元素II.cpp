/*
 * @Descroption: LeetCode 82. ɾ�����������е��ظ�Ԫ�� II
 * @Author: EmoryHuang
 * @Date: 2021-03-20 20:22:36
 * @����˼·: ����˼·��[83. ɾ�����������е��ظ�Ԫ��]
 * ��ͬ������Ҫɾ������Ԫ�أ������Ҫ����һ��ǰ��ָ�룬�Ա�ɾ�������ظ�Ԫ��
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);  //ͷָ��
        dummy->next = head;
        ListNode *p = head, *pre = dummy;
        while (p && p->next) {
            if (p->val == p->next->val) {  //�����ǰԪ������һ��Ԫ����ͬ
                while (p->next && p->val == p->next->val) {  //ֱ������ͬΪֹ
                    ListNode* temp = p;
                    p = p->next;  //��ǰԪ�غ���
                    delete temp;
                }
                ListNode* del = p;    //ɾ����ǰԪ��
                pre->next = p->next;  //��������
                p = p->next;
                delete del;
            } else {  //����ͬ�򶼺���
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};