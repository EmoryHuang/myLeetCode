'''
Descroption: LeetCode 1822. ����Ԫ�ػ��ķ���
Author: EmoryHuang
Date: 2021-06-17 15:38:00
����˼·:
���⣬������������������жϳ˻����
'''


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        neg = 0
        for num in nums:
            if num == 0:
                return 0
            elif num < 0:
                neg += 1
        return 1 if neg % 2 == 0 else -1
