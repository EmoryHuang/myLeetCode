'''
Descroption: LeetCode 1721. 交换链表中的节点
Author: EmoryHuang
Date: 2021-07-25 13:50:11
Method:
快慢指针
快指针首先前进k - 1个节点，然后快慢指针同时前进
找到倒数第k个节点
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        fast, slow = head, head
        # 找到正数第k个节点
        for _ in range(k - 1):
            fast = fast.next
        l = fast
        # 找到倒数第k个节点
        while fast.next:
            slow = slow.next
            fast = fast.next
        l.val, slow.val = slow.val, l.val
        return head
