/*
 * @Description: LeetCode 24. 两两交换链表中的节点
 * @Author: EmoryHuang
 * @Date: 2023-08-14 09:56:20
 * @解题思路:
 * 模拟
 */

import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode cur = dummy;
        while (cur.next != null && cur.next.next != null) {
            ListNode a = cur.next;
            ListNode b = cur.next.next;
            cur.next = b;
            a.next = b.next;
            b.next = a;
            cur = a;
        }
        return dummy.next;
    }
}