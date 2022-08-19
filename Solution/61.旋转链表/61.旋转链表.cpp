/*
 * @Descroption: LeetCode 61. ��ת����
 * @Author: EmoryHuang
 * @Date: 2021-03-27 10:17:36
 * @����˼·: �ҵ�ԭ��������һ���ڵ㣬������ԭ�����ͷ����������ɻ�������ͳ�������ȣ�
 * ������Ч k ֵ����ԭ�����ͷ�ڵ�������ҵ���Ҫ�Ͽ��ĵ㣬���жϿ�
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        int len = 1;
        ListNode *p = head, *node;
        while (p->next) {
            len++;
            p = p->next;
        }
        k %= len;
        if (k == 0) return head;
        p->next = head;  //��β����
        for (int i = 0; i < len - k; i++) p = p->next;
        node = p->next;     //�µ�ͷ�ڵ�
        p->next = nullptr;  //�γɵ�����
        return node;
    }
};