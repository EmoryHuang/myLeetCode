'''
Descroption: ��ָ Offer 03. �������ظ�������
Author: EmoryHuang
Date: 2021-06-28 16:22:00
����˼·:
���⣬��ϣ�����
'''


class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        hash = set()
        for num in nums:
            if num in hash:
                return num
            else:
                hash.add(num)
