/*
 * @Descroption: 剑指 Offer 22. 链表中倒数第k个节点
 * @Author: EmoryHuang
 * @Date: 2021-07-01 18:01:00
 * @解题思路:
 * 快慢指针，快指针先走 k 步，然后快慢指针一起走
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