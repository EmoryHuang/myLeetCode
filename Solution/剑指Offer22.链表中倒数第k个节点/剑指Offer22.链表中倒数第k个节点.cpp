/*
 * @Descroption: ��ָ Offer 22. �����е�����k���ڵ�
 * @Author: EmoryHuang
 * @Date: 2021-07-01 18:01:00
 * @����˼·:
 * ����ָ�룬��ָ������ k ����Ȼ�����ָ��һ����
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head, *fast = head;
        while (k--) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};