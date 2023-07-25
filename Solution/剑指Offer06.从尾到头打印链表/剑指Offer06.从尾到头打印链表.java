/*
 * @Descroption: 剑指 Offer 06. 从尾到头打印链表
 * @Author: EmoryHuang
 * @Date: 2023-07-24 09:43:30
 * @Method:
 * 递归
 */

import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        return dfs(head, 0);
    }

    int[] dfs(ListNode node, int size) {
        if (node == null) {
            return new int[size];
        }
        int[] nums = dfs(node.next, size + 1);
        nums[nums.length - size - 1] = node.val;
        return nums;
    }
}