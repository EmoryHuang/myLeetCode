/*
 * @Description: LeetCode 234. 回文链表
 * @Author: EmoryHuang
 * @Date: 2023-08-09 10:14:30
 * @Method:
 * 快慢指针找到中间节点，然后反转后半部分，遍历判断是否是回文
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
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }
        ListNode fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode mid = reverse(slow.next);

        while (mid != null) {
            if (mid.val != head.val) {
                return false;
            }
            mid = mid.next;
            head = head.next;
        }
        return true;
    }

    ListNode reverse(ListNode node) {
        ListNode pre = null, cur = node;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
}