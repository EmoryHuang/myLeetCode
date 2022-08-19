'''
Descroption: LeetCode 1669. �ϲ���������
Author: EmoryHuang
Date: 2021-07-24 13:34:07
����˼·:
���������
���ҵ�����1�ĵ�a-1���ڵ㣬�ҵ�����1�ĵ�b+1���ڵ�
���ҵ�����2��β�ڵ㣬֮�����Ӽ���
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        p = list1
        # �ҵ�����1�ĵ�a-1���ڵ�
        for i in range(a - 1):
            p = p.next
        # �ҵ�����1�ĵ�b+1���ڵ�
        q = p.next
        for i in range(a, b + 1):
            q = q.next
        # �ҵ�����2��β�ڵ�
        tail = list2
        while tail.next:
            tail = tail.next
        # ����
        p.next = list2
        tail.next = q
        return list1
