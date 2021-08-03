/*
 * @Descroption: 剑指 Offer II 023. 两个链表的第一个重合节点
 * @Author: EmoryHuang
 * @Date: 2021-08-03 20:31:44
 * @Method:
 * 用一个指针指向链表 A 头结点，另一个指针指向链表 B 头结点，
 * 然后同时移动，当遍历到链表尾时指针换到另一条链表，当两个指针相遇时就是相交点
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
        ListNode *ha = headA, *hb = headB;
        if (!ha || !hb) return nullptr;
        while (ha != hb) {
            ha = ha ? ha->next : headB;
            hb = hb ? hb->next : headA;
        }
        return ha;
    }
};