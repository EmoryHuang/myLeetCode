'''
Descroption: LeetCode 1669. 合并两个链表
Author: EmoryHuang
Date: 2021-07-24 13:34:07
解题思路:
链表基础题
先找到链表1的第a-1个节点，找到链表1的第b+1个节点
再找到链表2的尾节点，之后连接即可
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        p = list1
        # 找到链表1的第a-1个节点
        for i in range(a - 1):
            p = p.next
        # 找到链表1的第b+1个节点
        q = p.next
        for i in range(a, b + 1):
            q = q.next
        # 找到链表2的尾节点
        tail = list2
        while tail.next:
            tail = tail.next
        # 连接
        p.next = list2
        tail.next = q
        return list1
