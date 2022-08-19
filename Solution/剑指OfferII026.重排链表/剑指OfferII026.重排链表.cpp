/*
 * @Descroption: 剑指 Offer II 026. 重排链表
 * @Author: EmoryHuang
 * @Date: 2021-10-22 14:16:58
 * @Method:
 * 链表操作
 * 快慢指针找到中间节点，原地反转后半部分链表，然后间隔插入
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
    ListNode* reverse(ListNode *node) {
        ListNode *pre = nullptr, *cur = node;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        // 快慢指针找到中间节点
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *q = slow->next;
        slow->next = nullptr;
        ListNode *p = head;
        // 原地反转后半部分链表
        q = reverse(q);
        // 间隔插入
        while (q && p) {
            ListNode *q_nxt = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = q_nxt;
        }
    }
};