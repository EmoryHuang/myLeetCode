'''
Descroption: LeetCode 1860. �������ڴ�й¶
Author: EmoryHuang
Date: 2021-09-18 19:10:38
Method:
ģ�⣬ÿ�������ڴ�ϴ���Ǹ�
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
