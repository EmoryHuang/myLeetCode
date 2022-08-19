'''
Descroption: 剑指 Offer II 021. 删除链表的倒数第 n 个结点
Author: EmoryHuang
Date: 2021-08-03 20:43:36
Method:
快慢指针，找到倒数第n个节点，然后删除
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
