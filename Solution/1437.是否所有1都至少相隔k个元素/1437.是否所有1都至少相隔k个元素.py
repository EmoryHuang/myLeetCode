'''
Descroption: LeetCode 1437. �Ƿ����� 1 ��������� k ��Ԫ��
Author: EmoryHuang
Date: 2021-06-05 15:58:00
����˼·:
�������飬��¼�������� 1 ֮��ľ��룬��С�� k �򷵻� false
'''


class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        pre = -1  # ǰһ��1��λ��
        for i, num in enumerate(nums):
            if num == 1:
                if pre != -1 and (i - pre - 1) < k:
                    return False
                pre = i
        return True
