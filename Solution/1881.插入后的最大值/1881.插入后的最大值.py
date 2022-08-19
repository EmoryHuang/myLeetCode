'''
Descroption: LeetCode 1881. 插入后的最大值
Author: EmoryHuang
Date: 2021-09-10 20:15:06
Method:
如果 n 是负数，寻找 n 中第一个比 x 大的位置插入
如果 n 是正数，寻找 n 中第一个比 x 小的位置插入
'''


class Solution:
    def maxValue(self, n: str, x: int) -> str:
        if n[0] == '-':
            for i, s in enumerate(n):
                if i == 0: continue
                if int(s) > x:
                    return n[:i] + str(x) + n[i:]
            return n + str(x)
        else:
            for i, s in enumerate(n):
                if int(s) < x:
                    return n[:i] + str(x) + n[i:]
            return n + str(x)
