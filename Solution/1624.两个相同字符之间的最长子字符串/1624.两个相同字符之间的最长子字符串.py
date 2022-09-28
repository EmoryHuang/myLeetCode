'''
Descroption: LeetCode 1624. 两个相同字符之间的最长子字符串
Author: EmoryHuang
Date: 2022-09-17 09:21:20
Method:
使用哈希表记录元素第一次出现的位置
若再次出现则计算中间字符长度
'''


class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        hash = defaultdict(int)
        ans = -1
        for i, c in enumerate(s):
            if c in hash.keys():
                ans = max(ans, i - hash[c] - 1)
            else:
                hash[c] = i
        return ans
