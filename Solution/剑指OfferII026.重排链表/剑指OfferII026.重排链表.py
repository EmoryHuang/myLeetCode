'''
Descroption: ��ָ Offer II 026. ��������
Author: EmoryHuang
Date: 2021-10-22 14:08:58
Method:
�������
����ָ���ҵ��м�ڵ㣬ԭ�ط�ת��벿������Ȼ��������
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
        # ����ָ���ҵ��м�ڵ�
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        q = slow.next
        slow.next = None
        # ԭ�ط�ת��벿������
        p, q = head, reverse(q)
        # �������
        while q:
            q_nxt = q.next
            q.next = p.next
            p.next = q
            p, q = q.next, q_nxt
