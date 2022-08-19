'''
Descroption: LeetCode 1614. 括号的最大嵌套深度
Author: EmoryHuang
Date: 2021-10-20 08:41:44
Method:
简单题，使用栈记录括号的最大嵌套深度
'''


class Solution:
    def maxDepth(self, s: str) -> int:
        stack = deque()
        ans = 0
        for c in s:
            if c == '(':
                stack.append(c)
                ans = max(ans, len(stack))
            elif c == ')':
                stack.pop()
        return ans