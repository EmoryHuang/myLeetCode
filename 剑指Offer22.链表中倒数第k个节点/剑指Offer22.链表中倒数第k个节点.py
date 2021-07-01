'''
Descroption: 剑指 Offer 22. 链表中倒数第k个节点
Author: EmoryHuang
Date: 2021-07-01 17:59:00
解题思路:
快慢指针，快指针先走 k 步，然后快慢指针一起走
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
