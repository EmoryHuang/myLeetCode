'''
Descroption: LeetCode 670. 最大交换
Author: EmoryHuang
Date: 2021-11-08 20:57:40
Method:
方法一：暴力
寻找当前字符后面的最大值，若最大值不为当前字符，则进行交换

方法二：排序
对 num 中的数字从大到小的进行排序
然后与原数字一一比较，遇到的第一个不同的值即是需要交换的值
'''


class Solution:
    def maximumSwap(self, num: int) -> int:
        a = list(str(num))
        b = sorted(a, reverse=True)
        idx = -1
        for i in range(len(a)):
            if a[i] != b[i]:
                idx = i
                break
        if idx == -1:
            return num
        for i in range(len(a) - 1, -1, -1):
            if a[i] == b[idx]:
                a[i], a[idx] = a[idx], a[i]
        return int(''.join(a))
