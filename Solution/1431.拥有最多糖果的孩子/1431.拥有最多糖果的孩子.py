'''
Descroption: LeetCode 1431. ӵ������ǹ��ĺ���
Author: EmoryHuang
Date: 2021-10-20 19:31:33
Method:
���⣬�������������ֵ�Ƚ�
'''


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxc = max(candies)
        return [num + extraCandies >= maxc for num in candies]