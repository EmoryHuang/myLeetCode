'''
Descroption: LeetCode 1784. 检查二进制字符串字段
Author: EmoryHuang
Date: 2021-08-05 20:00:03
Method:
简单题，记录数字变化的次数
'''


class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        cnt = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                cnt += 1
        return cnt <= 1
