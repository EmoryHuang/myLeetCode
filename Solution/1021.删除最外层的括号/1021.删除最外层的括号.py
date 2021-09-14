'''
Descroption: LeetCode 1021. 删除最外层的括号
Author: EmoryHuang
Date: 2021-09-14 16:36:05
Method:
栈，在栈非空时将括号加入 ans
遇到 ( / ) 时入栈/出栈
'''


class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        ans = ''
        for c in s:
            if c == ')':
                stack.pop()
            if stack:
                ans += c
            if c == '(':
                stack.append('(')
        return ans