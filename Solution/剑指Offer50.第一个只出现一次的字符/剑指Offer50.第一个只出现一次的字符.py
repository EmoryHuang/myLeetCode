'''
Descroption: 剑指 Offer 50. 第一个只出现一次的字符
Author: EmoryHuang
Date: 2021-07-29 19:24:06
Method:
简单题，使用哈希表计数
'''


class Solution:
    def firstUniqChar(self, s: str) -> str:
        hash = defaultdict(int)
        for c in s:
            hash[c] += 1
        for c in s:
            if hash[c] == 1:
                return c
        return ' '