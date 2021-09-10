'''
Descroption: LeetCode 1910. 删除一个字符串中所有出现的给定子字符串
Author: EmoryHuang
Date: 2021-07-22 18:48:07
解题思路:
查找字符串中part出现的位置，替换为空
'''


class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, '', 1)
        return s
