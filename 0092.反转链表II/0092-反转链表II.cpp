/*
 * @Descroption: LeetCode 92. ��ת���� II
 * @Author: EmoryHuang
 * @Date: 2021-03-18 15:31:36
 * @����˼·:
 * ���Ƚ�ָ���ƶ��� `left` ��ǰ����Ȼ��ʹ��ͷ�巨��ֱ�� `right` ����
 * ����Ҫ��ת�������ÿ������һ���ڵ㣬������½ڵ�������ת���ֵ���ʼλ��
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);  //����һ��ͷָ��
        ListNode *p = head, *pre = dummy, *q;
        for (int i = 1; i < left; i++) {
            pre = pre->next;  //Ѱ�� left ��ǰ��
        }
        p = pre->next;  //��ǰ���
        for (int i = left; i < right; i++) {
            q = p->next;  //��ǰ���ĺ��
            p->next = q->next;
            q->next = pre->next;
            pre->next = q;
        }
        return dummy->next;
    }
};