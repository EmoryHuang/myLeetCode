/*
 * @Descroption: LeetCode 1669. �ϲ���������
 * @Author: EmoryHuang
 * @Date: 2021-07-24 13:39:52
 * @����˼·:
 * ���������
 * ���ҵ�����1�ĵ�a-1���ڵ㣬�ҵ�����1�ĵ�b+1���ڵ�
 * ���ҵ�����2��β�ڵ㣬֮�����Ӽ���
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // �ҵ�����1�ĵ�a-1���ڵ�
        ListNode* p = list1;
        for (int i = 0; i < a - 1; i++) p = p->next;
        // �ҵ�����1�ĵ�b+1���ڵ�
        ListNode* q = p->next;
        for (int i = a; i < b + 1; i++) q = q->next;
        // �ҵ�����2��β�ڵ�
        ListNode* tail = list2;
        while (tail->next) tail = tail->next;
        // ����
        p->next = list2;
        tail->next = q;
        return list1;
    }
};