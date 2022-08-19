'''
Descroption: LeetCode 899. 有序队列
Author: EmoryHuang
Date: 2022-08-03 09:28:02
Method:
当 k = 1 时只能移动第一个字符，相当于寻找循环字符串的最小字典序
当 k > 1 时由于没有规定移动次数，实际上相当于对字符串进行任意排列
'''


class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k == 1:
            return min(s[i:] + s[:i] for i in range(len(s)))
        else:
            return ''.join(sorted(s))