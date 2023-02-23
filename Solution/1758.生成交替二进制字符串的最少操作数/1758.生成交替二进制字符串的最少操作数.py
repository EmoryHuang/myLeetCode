'''
Descroption: LeetCode 1758. 生成交替二进制字符串的最少操作数
Author: EmoryHuang
Date: 2022-11-29 09:15:33
Method:
将字符串与0101...和1010...比较
'''

class Solution:
    def minOperations(self, s: str) -> int:
        cnt = sum(int(c) != i % 2 for i, c in enumerate(s))
        return min(cnt, len(s) - cnt)
