'''
Descroption: LeetCode 944. 删列造序
Author: EmoryHuang
Date: 2022-05-12 08:54:45
Method:
简单题，遍历比较当前行和上一行元素即可
'''


class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans = 0
        for i in zip(*strs):
            if list(i) != sorted(i):
                ans += 1
        return ans
