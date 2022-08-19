'''
Descroption: LeetCode 475. 供暖器
Author: EmoryHuang
Date: 2021-06-08 20:55:00
解题思路:
二分法
遍历每个 house, 寻找距离 house 最近的 heater
房子位于 heater 左侧，最小就应该是 heaters[l] - house
房子位于 heater 右侧，最小就应该是 house - heaters[r]
'''


class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        heaters = [float("-inf")] + heaters + [float("inf")]
        ans, n = 0, len(heaters)
        for house in houses:
            # 寻找左边界
            l, r = 0, n - 1
            while l < r:
                mid = (l + r) // 2
                if heaters[mid] >= house:
                    r = mid
                else:
                    l = mid + 1
            ans = max(ans, min(heaters[l] - house, house - heaters[r - 1]))
        return ans
