'''
Descroption: LeetCode 394. 字符串解码
Author: EmoryHuang
Date: 2021-08-24 16:12:53
Method:
使用栈记录 '[' 前的情况，前面的结果以及重复数字
如果遇到 '[' 则将前面的结果以及重复数字入栈
如果遇到 ']' 则进行重复
'''


class Solution:
    def decodeString(self, s: str) -> str:
        stack = []  # (ans, num) 前面的结果以及重复数字
        num = 0
        ans = ''
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                # 如果遇到 '[' 则将前面的结果以及重复数字入栈
                stack.append((ans, num))
                ans, num = '', 0
            elif c == ']':
                # 如果遇到 ']' 则进行重复
                top = stack.pop()
                ans = top[0] + ans * top[1]
            else:
                ans += c
        return ans
