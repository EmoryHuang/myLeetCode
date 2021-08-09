'''
Descroption: LeetCode 1029. 两地调度
Author: EmoryHuang
Date: 2021-08-09 14:00:58
Method:
按照 price_A - price_B 从小到大排序；
将前 N 个人飞往 A 市，其余人飞往 B 市
'''


class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs) // 2
        ans = 0
        costs.sort(key=lambda x: x[0] - x[1])
        for i in range(n):
            ans += costs[i][0] + costs[i + n][1]
        return ans
