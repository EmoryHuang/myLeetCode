'''
Descroption: 剑指 Offer 52. 两个链表的第一个公共节点
Author: EmoryHuang
Date: 2021-07-16 18:44:41
解题思路:
a + b = b + a
例如：
    0, 9, 1, 2, 4, | 3, (2, 4)
    3, 2, 4, | 0, 9, 1, (2, 4)
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        h1, h2 = headA, headB
        while h1 != h2:
            h1 = headB if not h1 else h1.next
            h2 = headA if not h2 else h2.next
        return h1
