'''
Descroption: LeetCode 1019. 链表中的下一个更大节点
Author: EmoryHuang
Date: 2021-07-23 19:04:48
解题思路:
维护一个递减栈，栈中存储元素下标
遍历数组，若遇到比栈顶元素更大的数，即为遇见的第一个更大节点
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
            # 维护一个递减栈
            while stack and nums[stack[-1]] < num:
                ans[stack[-1]] = num  # 遇到的第一个更大值
                stack.pop()
            stack.append(i)
        return ans
