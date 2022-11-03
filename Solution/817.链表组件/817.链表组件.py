'''
Descroption: LeetCode 817. 链表组件
Author: EmoryHuang
Date: 2022-10-12 09:14:20
Method:
链表模拟
使用set存储nums中的元素，之后遍历链表检查是否有连续段
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        cnt = 0
        s = set(nums)
        while head:
            if head.val not in s:
                head = head.next
            else:
                while head and head.val in s:
                    head = head.next
                cnt += 1
        return cnt
