/*
 * @Descroption: 剑指 Offer 52. 两个链表的第一个公共节点
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:32:17
 * @Method:
 * 循环遍历两个链表，a + b = b + a
 */

import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
class Solution {
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p = headA, q = headB;
        while (p != q) {
            p = p != null ? p.next : headB;
            q = q != null ? q.next : headA;
        }
        return q;
    }
}