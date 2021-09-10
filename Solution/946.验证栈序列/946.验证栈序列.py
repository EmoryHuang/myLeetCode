'''
Descroption: LeetCode 946. 验证栈序列
Author: EmoryHuang
Date: 2021-07-03 14:23:32
解题思路:
模拟，使用stack模拟入栈，
若栈非空，并且栈顶元素等于出栈元素，则出栈
'''


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        cnt = 0
        for num in pushed:
            stack.append(num)
            # 若栈非空，并且栈顶元素等于出栈元素
            while stack and cnt < len(popped) and stack[-1] == popped[cnt]:
                cnt += 1
                stack.pop()
        return cnt == len(popped)
