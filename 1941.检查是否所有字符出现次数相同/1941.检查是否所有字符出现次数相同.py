'''
Descroption: LeetCode 1941. 检查是否所有字符出现次数相同
Author: EmoryHuang
Date: 2021-07-29 19:41:33
Method:
简单题，使用哈希表计数
'''


class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len(set(Counter(s).values())) == 1