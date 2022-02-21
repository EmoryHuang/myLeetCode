'''
Descroption: LeetCode 717. 1比特与2比特字符
Author: EmoryHuang
Date: 2022-02-20 10:32:07
Method:
简单题，从左向右扫描最后一位之前的字符串，记录之前的匹配状态
'''

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        idx, n = 0, len(bits)
        while idx < n - 1:
            if bits[idx] == 0:
                idx += 1
            else:
                idx += 2
        return idx == n - 1