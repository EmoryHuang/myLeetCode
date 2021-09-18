'''
Descroption: LeetCode 1860. 增长的内存泄露
Author: EmoryHuang
Date: 2021-09-18 19:10:38
Method:
模拟，每次消耗内存较大的那个
'''


class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        crash = 1
        while max(memory1, memory2) >= crash:
            if memory1 >= memory2:
                memory1 -= crash
            else:
                memory2 -= crash
            crash += 1
        return [crash, memory1, memory2]
