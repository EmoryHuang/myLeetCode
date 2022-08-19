/*
 * @Descroption: LeetCode 160. 相交链表
 * @Author: EmoryHuang
 * @Date: 2021-03-20 15:32:36
 * @解题思路:
 * 简单方法：可以先求出两个链表的长度之差 n，用两个指针指向两个链表的头结点，
 * 让更长链表的指针先走 n 个结点，然后两个指针同时向后移动，第一次相遇的结点就是相交点
 *
 * 这里使用一个更巧妙的方法：用一个指针指向链表 A 头结点，另一个指针指向链表 B 头结点，
 * 然后同时移动，当遍历到链表尾时指针换到另一条链表，当两个指针相遇时就是相交点
 *
 * 初看很难理解，但是其实也很简单， A 和 B 两个链表长度可能不同，但是 A+B 和 B+A 的长度是相同的，
 * 所以遍历 A+B 和遍历 B+A 一定是同时结束，如果 A,B 相交的话 A 和 B 有一段是相同的
 * 例如：
 *    0, 9, 1, 2, 4, | 3, (2, 4)
 *    3, 2, 4, | 0, 9, 1, (2, 4)
 */

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        if (headA == NULL || headB == NULL) return NULL;
        while (p != q) {
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next;
        }
        return p;
    }
};