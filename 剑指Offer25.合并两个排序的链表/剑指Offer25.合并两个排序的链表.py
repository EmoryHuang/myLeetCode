'''
Descroption: 剑指 Offer 25. 合并两个排序的链表
Author: EmoryHuang
Date: 2021-07-02 14:45:00
解题思路:
链表基础题，依次比较两个链表元素大小
方法一：迭代
方法二：递归
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 方法一：迭代
    # def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
    #     pre = head = ListNode(0)
    #     while l1 and l2:
    #         if l1.val > l2.val:
    #             pre.next = l2
    #             l2 = l2.next
    #         else:
    #             pre.next = l1
    #             l1 = l1.next
    #         pre = pre.next
    #     pre.next = l1 if l1 else l2
    #     return head.next

    # 方法二：递归
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
