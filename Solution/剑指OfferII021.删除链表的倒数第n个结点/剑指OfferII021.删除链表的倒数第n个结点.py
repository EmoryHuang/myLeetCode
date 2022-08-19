'''
Descroption: ��ָ Offer II 021. ɾ������ĵ����� n �����
Author: EmoryHuang
Date: 2021-08-03 20:43:36
Method:
����ָ�룬�ҵ�������n���ڵ㣬Ȼ��ɾ��
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head or not head.next:
            return None
        slow, fast = head, head
        for i in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return head
