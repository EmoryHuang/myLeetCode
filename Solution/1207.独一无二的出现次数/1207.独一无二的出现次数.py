'''
Descroption: LeetCode 1207. 独一无二的出现次数
Author: EmoryHuang
Date: 2021-06-21 21:08:00
解题思路:
简单题，使用map记录数字出现的次数，然后用set排除重复数
'''


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        c = Counter(arr).values()
        return len(c) == len(set(c))
