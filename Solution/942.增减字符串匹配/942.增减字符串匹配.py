'''
Descroption: LeetCode 942. 增减字符串匹配
Author: EmoryHuang
Date: 2021-06-04 14:03:00
解题思路:
维护当前未使用的最小和最大的数，从左向右扫描字符串，
如果碰到 'I'，就取出当前最小的数，否则取出当前最大的数
'''


class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        low, high = 0, len(s)
        ans = []
        for c in s:
            if c == 'I':
                ans.append(low)
                low += 1
            elif c == 'D':
                ans.append(high)
                high -= 1
        ans.append(low)
        return ans
