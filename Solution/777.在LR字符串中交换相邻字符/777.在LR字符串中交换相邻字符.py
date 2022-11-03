'''
Descroption: LeetCode 777. 在LR字符串中交换相邻字符
Author: EmoryHuang
Date: 2022-10-02 10:42:18
Method:
双指针
比较字符串，X可以忽略，理解题意为
L 只能左移且不能越过 R, R 只能右移且不能越过 L
即可比较 L, R 的相对位置
'''


class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        i, j = 0, 0
        while True:
            # 忽略 X
            while i < n and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1
            if i >= n and j >= n:
                return True
            # 判断LR字符的相对位置
            if i >= n or j >= n or start[i] != end[j]:
                return False
            # L 只能左移
            if start[i] == 'L' and i < j:
                return False
            # R 只能右移
            if start[i] == 'R' and i > j:
                return False
            i, j = i + 1, j + 1
