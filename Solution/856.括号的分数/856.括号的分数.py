'''
Descroption: LeetCode 856. 括号的分数
Author: EmoryHuang
Date: 2022-10-09 09:24:47
Method:
栈
依次遍历元素，若为（，则分数 0 入栈，否则
若栈顶元素cur == 0, 则）前面只有（，分值为 1
若栈顶元素cur != 0, 则cur为）前面的分值
'''


class Solution:

    def scoreOfParentheses(self, s: str) -> int:
        stack = [0] # 初始化分数为0
        for c in s:
            if c == '(':
                stack.append(0)
            else:
                # 若栈顶元素cur == 0, 则）前面只有（，分值为 1
                # 若栈顶元素cur != 0, 则cur为）前面的分值
                cur = stack.pop()
                stack[-1] += max(cur * 2, 1)
        return stack[-1]