'''
Descroption: LeetCode 2185. 统计包含给定前缀的字符串
Author: EmoryHuang
Date: 2023-01-08 09:11:55
Method:
简单题，依次比较前缀即可
'''


class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(w.startswith(pref) for w in words)
