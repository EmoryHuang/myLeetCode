'''
Descroption: LeetCode 1893. ����Ƿ�����������������������
Author: EmoryHuang
Date: 2021-07-20 20:13:09
����˼·:
�����������ڵ�ÿһ����������¼λ�������ڵ�Ԫ�ص�����
'''


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        cnt = 0
        for i in range(left, right + 1):
            for l, r in ranges:
                if l <= i <= r:
                    cnt += 1
                    break
        return cnt == right - left + 1
