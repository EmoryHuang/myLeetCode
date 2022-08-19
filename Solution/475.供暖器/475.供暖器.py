'''
Descroption: LeetCode 475. ��ů��
Author: EmoryHuang
Date: 2021-06-08 20:55:00
����˼·:
���ַ�
����ÿ�� house, Ѱ�Ҿ��� house ����� heater
����λ�� heater ��࣬��С��Ӧ���� heaters[l] - house
����λ�� heater �Ҳ࣬��С��Ӧ���� house - heaters[r]
'''


class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        heaters = [float("-inf")] + heaters + [float("inf")]
        ans, n = 0, len(heaters)
        for house in houses:
            # Ѱ����߽�
            l, r = 0, n - 1
            while l < r:
                mid = (l + r) // 2
                if heaters[mid] >= house:
                    r = mid
                else:
                    l = mid + 1
            ans = max(ans, min(heaters[l] - house, house - heaters[r - 1]))
        return ans
