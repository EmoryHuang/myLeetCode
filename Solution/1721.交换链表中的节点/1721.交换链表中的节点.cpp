/*
 * @Descroption: LeetCode 1721. ���������еĽڵ�
 * @Author: EmoryHuang
 * @Date: 2021-07-25 13:54:14
 * @����˼·:
 * ����ָ��
 * ��ָ������ǰ��k - 1���ڵ㣬Ȼ�����ָ��ͬʱǰ��
 * �ҵ�������k���ڵ�
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = head, *slow = head;
        // �ҵ�������k���ڵ�
        for (int i = 0; i < k - 1; i++) fast = fast->next;
        ListNode* l = fast;
        // �ҵ�������k���ڵ�
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(l->val, slow->val);
        return head;
    }
};