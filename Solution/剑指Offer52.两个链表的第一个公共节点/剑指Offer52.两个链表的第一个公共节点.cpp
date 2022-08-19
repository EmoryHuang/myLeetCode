/*
 * @Descroption: 剑指 Offer 52. 两个链表的第一个公共节点
 * @Author: EmoryHuang
 * @Date: 2021-07-16 18:45:13
 * @解题思路:
 * a + b = b + a
 * 例如：
 *     0, 9, 1, 2, 4, | 3, (2, 4)
 *     3, 2, 4, | 0, 9, 1, (2, 4)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next;
        }
        return p;
    }
};