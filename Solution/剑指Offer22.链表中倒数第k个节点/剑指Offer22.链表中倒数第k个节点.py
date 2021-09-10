'''
Descroption: ��ָ Offer 22. �����е�����k���ڵ�
Author: EmoryHuang
Date: 2021-07-01 17:59:00
����˼·:
����ָ�룬��ָ������ k ����Ȼ�����ָ��һ����
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slow = fast = head
        for i in range(k):
            fast = fast.next
        while fast:
            fast = fast.next
            slow = slow.next
        return slow
