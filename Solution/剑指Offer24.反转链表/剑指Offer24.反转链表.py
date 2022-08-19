'''
Descroption: ��ָ Offer 24. ��ת����
Author: EmoryHuang
Date: 2021-07-01 18:46:00
����˼·:
��������ָ�룬preָ��գ�curָ��head
next�ݴ�cur.next��ͷ�巨��ת
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre
