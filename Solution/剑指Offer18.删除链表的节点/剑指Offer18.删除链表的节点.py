'''
Descroption: ��ָ Offer 18. ɾ������Ľڵ�
Author: EmoryHuang
Date: 2021-06-27 15:52:00
����˼·:
���⣬���������
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head == None:
            return head
        if head.val == val:
            return head.next
        head.next = self.deleteNode(head.next, val)
        return head
