'''
Descroption: LeetCode 1217. 玩筹码
Author: EmoryHuang
Date: 2021-09-11 20:25:55
Method:
奇数移动到奇数位置无消耗，偶数移动到偶数位置无消耗
那么只需要统计奇数偶数的数量，然后在选择数量较少的一方
'''


class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        odd, even = 0, 0
        for num in position:
            if num % 2 == 0:
                even += 1
            else:
                odd += 1
        return min(even, odd)
