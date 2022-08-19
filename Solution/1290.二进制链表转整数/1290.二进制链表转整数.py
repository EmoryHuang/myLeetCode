'''
Descroption: LeetCode 1290. 二进制链表转整数
Author: EmoryHuang
Date: 2021-08-26 18:41:40
Method:
简单题，位运算
每读到一个节点，则左移一位
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        if not head:
            return 0
        ans = 0
        while head:
            ans = (ans << 1) + head.val
            head = head.next
        return ans