'''
Descroption: LeetCode 2011. ִ�в�����ı���ֵ
Author: EmoryHuang
Date: 2021-10-15 19:53:34
Method:
���⣬ģ��
'''


class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        x = 0
        for op in operations:
            if op[1] == '+':
                x += 1
            elif op[1] == '-':
                x -= 1
        return x