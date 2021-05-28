/*
 * @Descroption: LeetCode 328. ��ż����
 * @Author: EmoryHuang
 * @Date: 2021-05-28 16:19:17
 * @����˼·:
 * ������ż����Ȼ��ϲ�
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *even = head->next, *odd = head;
        ListNode* evenHead = even;  // ż�������ͷ�ڵ�
        while (even && even->next) {
            odd->next = odd->next->next;    // ������һ�������ڵ�
            even->next = even->next->next;  // ������һ��ż���ڵ�
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};