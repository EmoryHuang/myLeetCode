'''
Descroption: 面试题 01.05. 一次编辑
Author: EmoryHuang
Date: 2022-05-13 09:04:42
Method:
依次比较两个字符串中元素
若第 i 个位置的元素不相同，则判断以下情况
first[i + 1:] == second[i + 1:] or first[i:] == second[i + 1:] or first[i + 1:] == second[i:]
'''


class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        n, m = len(first), len(second)
        if abs(n - m) > 1:
            return False
        for i in range(min(n, m)):
            if first[i] != second[i]:
                return first[i + 1:] == second[i + 1:] or first[i:] == second[i + 1:] \
                        or first[i + 1:] == second[i:]
        return abs(n-m) <= 1
