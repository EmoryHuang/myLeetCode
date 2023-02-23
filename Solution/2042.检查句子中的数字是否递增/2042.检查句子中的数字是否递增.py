'''
Descroption: LeetCode 2042. 检查句子中的数字是否递增
Author: EmoryHuang
Date: 2023-01-03 10:10:40
Method:
位运算
记录出现字符的位置即可
'''


class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        pre = 0
        for c in s.split():
            if c[0].isdigit():
                cur = int(c)
                if cur <= pre:
                    return False
                pre = cur
        return True