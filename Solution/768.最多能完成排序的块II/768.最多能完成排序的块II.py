'''
Descroption: LeetCode 768. 最多能完成排序的块 II
Author: EmoryHuang
Date: 2022-08-13 10:09:50
Method:
单调栈
如果当前元素大于等于栈顶元素则入栈（新增块），即每块的最大值
如果当前元素小于栈顶元素，则判断当前块是否可以被划分，直到栈顶元素小于等于当前元素为止
'''

class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stack = []
        for num in arr:
            if not stack or stack[-1] <= num:
                # 当前元素大于等于栈顶元素则入栈（新增块）
                # 即每块的最大值
                stack.append(num)
            else:
                # 当前元素小于栈顶元素，则判断当前块是否可以被划分
                # 直到栈顶元素小于等于当前元素为止
                top = stack.pop()
                while stack and stack[-1] > num:
                    stack.pop()
                stack.append(top)
        return len(stack)
