/*
 * @Descroption: LeetCode 19. ɾ������ĵ����� N �����
 * @Author: EmoryHuang
 * @Date: 2021-03-22 15:37:36
 * @����˼·:
 * ����һӦ�ú������뵽�����ÿ���2��ָ�룬��ָ������n����Ȼ�����һ���ߣ�ֱ����ָ���ߵ����
 * �������������￴���ģ����Ӻ��㣬�ݹ鵽���һ����㣬Ȼ������������ n �����
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
    // ����һ��˫ָ��
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode *p = head, *q = head;
        for (int i = 0; i < n; i++) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }

    // ���������ݹ�
    // int c = 0;
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if (!head) return nullptr;
    //     head->next = removeNthFromEnd(head->next, n);
    //     c++;
    //     if (n == c) return head->next;
    //     return head;
    // }
};