'''
Descroption: ������ 08.03. ħ������
Author: EmoryHuang
Date: 2021-07-28 19:02:28
Method:
���⣬��������
'''


class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            if num == i:
                return num
        return -1
