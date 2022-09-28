'''
Descroption: LeetCode 面试题 01.02. 判定是否互为字符重排
Author: EmoryHuang
Date: 2022-09-27 09:04:20
Method:
简单题，判断字符是否相同
'''


class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return Counter(s1) == Counter(s2)