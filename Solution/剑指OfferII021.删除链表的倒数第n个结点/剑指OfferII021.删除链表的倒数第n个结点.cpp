/*
 * @Descroption: ��ָ Offer II 021. ɾ������ĵ����� n �����
 * @Author: EmoryHuang
 * @Date: 2021-08-03 20:50:30
 * @Method:
 * ����ָ�룬�ҵ�������n���ڵ㣬Ȼ��ɾ��
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while (n--) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};