'''
Descroption: 剑指 Offer 24. 反转链表
Author: EmoryHuang
Date: 2021-07-01 18:46:00
解题思路:
设置两个指针，pre指向空，cur指向head
next暂存cur.next，头插法反转
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
