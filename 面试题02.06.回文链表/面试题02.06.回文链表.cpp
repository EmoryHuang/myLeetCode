/*
 * @Descroption: LeetCode 234. ��������
 * @Author: EmoryHuang
 * @Date: 2021-05-23 16:03:11
 * @����˼·:
 * ����ʹ�ÿ���ָ���ҵ��м�ڵ�
 * Ȼ��ת�����������α����Ƚϼ���
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
    ListNode *reverse(ListNode *head) {
        ListNode *p = nullptr, *pre = nullptr;
        while (head != nullptr) {
            p = head->next;
            head->next = pre;
            pre = head;
            head = p;
        }
        return pre;
    }
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast) {
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
        }
        slow = reverse(slow);
        while (head && slow) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};