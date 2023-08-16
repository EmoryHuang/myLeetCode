/*
 * @Description: LeetCode 142. 环形链表 II
 * @Author: EmoryHuang
 * @Date: 2023-08-09 10:18:10
 * @解题思路:
 * 首先创建快慢指针，判断链表是否存在环
 * 然后找到入环结点，
 * 定义两个指针，一快一满。慢指针每次只移动一步，而快指针每次移动两步。
 * 如果快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。
 */

import java.util.*;

/**
 * Definition for singly-linked list.
 * class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) {
 * val = x;
 * next = null;
 * }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head, slow = head;
        while (true) {
            if (fast == null || fast.next == null) {
                return null;
            }
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) {
                break;
            }
        }
        fast = head;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
}