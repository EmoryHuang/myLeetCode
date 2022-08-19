'''
Descroption: 面试题 02.05. 链表求和
Author: EmoryHuang
Date: 2021-07-16 19:32:04
解题思路:
大数加法原理
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        node = dummy = ListNode(-1)  # 头节点
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            node.next = ListNode(carry % 10)
            node = node.next
            carry //= 10
        return dummy.next