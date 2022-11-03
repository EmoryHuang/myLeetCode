/*
 * @Descroption: LeetCode 817. 链表组件
 * @Author: EmoryHuang
 * @Date: 2022-10-12 09:18:50
 * @Method:
 * 链表模拟
 * 使用set存储nums中的元素，之后遍历链表检查是否有连续段
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
    public int numComponents(ListNode head, int[] nums) {
        int cnt = 0;
        Set<Integer> s = new HashSet<Integer>();
        for (int n : nums)
            s.add(n);
        while (head != null) {
            if (s.contains(head.val)) {
                while (head != null && s.contains(head.val)) {
                    head = head.next;
                }
                cnt++;
            } else {
                head = head.next;
            }
        }
        return cnt;
    }
}