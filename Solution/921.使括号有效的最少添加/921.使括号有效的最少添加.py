'''
Descroption: LeetCode 921. 使括号有效的最少添加
Author: EmoryHuang
Date: 2021-07-23 20:31:15
解题思路:
使用栈存储
遍历字符串，若读到 '('，则入栈；
若读到 ')'，若此时栈是否为空，则说明没有匹配的 '('，cnt += 1，否则出栈
'''


class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        cnt = 0
        for c in s:
            if c == '(':
                stack.append(c)
            else:
                if not stack:
                    cnt += 1
                else:
                    stack.pop()
        return cnt + len(stack)
