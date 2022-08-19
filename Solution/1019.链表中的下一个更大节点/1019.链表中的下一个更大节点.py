'''
Descroption: LeetCode 1019. �����е���һ������ڵ�
Author: EmoryHuang
Date: 2021-07-23 19:04:48
����˼·:
ά��һ���ݼ�ջ��ջ�д洢Ԫ���±�
�������飬��������ջ��Ԫ�ظ����������Ϊ�����ĵ�һ������ڵ�
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        stack, ans = [], [0] * len(nums)
        for i, num in enumerate(nums):
            # ά��һ���ݼ�ջ
            while stack and nums[stack[-1]] < num:
                ans[stack[-1]] = num  # �����ĵ�һ������ֵ
                stack.pop()
            stack.append(i)
        return ans
