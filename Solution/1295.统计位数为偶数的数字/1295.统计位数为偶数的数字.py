'''
Descroption: LeetCode 1295. ͳ��λ��Ϊż��������
Author: EmoryHuang
Date: 2021-07-19 18:54:28
����˼·:
�������飬����ż�����ȵ�����
'''


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        cnt = 0
        for num in nums:
            if len(str(num)) % 2 == 0:
                cnt += 1
        return cnt
