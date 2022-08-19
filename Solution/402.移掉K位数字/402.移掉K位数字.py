'''
Descroption: LeetCode 402. 移掉 K 位数字
Author: EmoryHuang
Date: 2021-08-03 14:11:05
Method:
遍历字符，维护一个单调栈，进行k次弹出
最后还要注意截掉字符串左边的前导0
'''


class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        remain = len(num) - k
        for n in num:
            # 维护一个单调栈
            while k and stack and stack[-1] > n:
                stack.pop()
                k -= 1
            stack.append(n)
        return ''.join(stack[:remain]).lstrip('0') or '0'
