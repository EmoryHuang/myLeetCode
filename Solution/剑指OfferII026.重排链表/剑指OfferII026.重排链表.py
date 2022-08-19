'''
Descroption: 剑指 Offer II 026. 重排链表
Author: EmoryHuang
Date: 2021-10-22 14:08:58
Method:
链表操作
快慢指针找到中间节点，原地反转后半部分链表，然后间隔插入
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        def reverse(node: ListNode) -> ListNode:
            pre, cur = None, node
            while cur:
                nxt = cur.next
                cur.next = pre
                pre, cur = cur, nxt
            return pre

        if not head and not head.next:
            return
        # 快慢指针找到中间节点
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        q = slow.next
        slow.next = None
        # 原地反转后半部分链表
        p, q = head, reverse(q)
        # 间隔插入
        while q:
            q_nxt = q.next
            q.next = p.next
            p.next = q
            p, q = q.next, q_nxt
