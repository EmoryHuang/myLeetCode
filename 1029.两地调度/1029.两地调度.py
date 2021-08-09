'''
Descroption: LeetCode 1029. ���ص���
Author: EmoryHuang
Date: 2021-08-09 14:00:58
Method:
���� price_A - price_B ��С��������
��ǰ N ���˷��� A �У������˷��� B ��
'''


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs) // 2
        ans = 0
        costs.sort(key=lambda x: x[0] - x[1])
        for i in range(n):
            ans += costs[i][0] + costs[i + n][1]
        return ans
