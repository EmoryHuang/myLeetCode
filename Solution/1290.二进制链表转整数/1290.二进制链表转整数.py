'''
Descroption: LeetCode 1290. ����������ת����
Author: EmoryHuang
Date: 2021-08-26 18:41:40
Method:
���⣬λ����
ÿ����һ���ڵ㣬������һλ
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