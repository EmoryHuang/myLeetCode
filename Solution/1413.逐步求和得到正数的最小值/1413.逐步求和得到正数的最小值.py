'''
Descroption: LeetCode 1413. ����͵õ���������Сֵ
Author: EmoryHuang
Date: 2021-06-05 15:11:00
����˼·:
�ҵ������������ۻ�����С��sum������Ҫ�����С����Ϊ 1 - sum
'''


class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        ans, sum = 0, 0
        for num in nums:
            sum += num
            ans = min(sum, ans)
        return 1 - ans
