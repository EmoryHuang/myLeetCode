/*
 * @Descroption: LeetCode 234. 回文链表
 * @Author: EmoryHuang
 * @Date: 2021-05-23 16:03:11
 * @解题思路:
 * 首先使用快慢指针找到中间节点
 * 然后翻转后半个链表，依次遍历比较即可
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