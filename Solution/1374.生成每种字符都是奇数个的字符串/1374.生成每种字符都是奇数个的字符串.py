'''
Descroption: LeetCode 1374. 生成每种字符都是奇数个的字符串
Author: EmoryHuang
Date: 2022-08-01 09:04:08
Method:
简单题，直接取巧构造即可
'''


class Solution:
    def generateTheString(self, n: int) -> str:
        if n % 2 == 1:
            return 'a' * n
        else:
            return 'a' * (n - 1) + 'b'