'''
Descroption: 剑指 Offer 06. 从尾到头打印链表
Author: EmoryHuang
Date: 2021-06-28 17:03:00
解题思路:
简单题，reverse, 递归, 栈
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # reverse
    def reversePrint(self, head: ListNode) -> List[int]:
        ans = []
        while head != None:
            ans.append(head.val)
            head = head.next
        return ans[::-1]

    # 递归
    # def reversePrint(self, head: ListNode) -> List[int]:
    #     if head is None:
    #         return []
    #     return self.reversePrint(head.next) + [head.val]
