'''
Descroption: LeetCode 1052. 爱生气的书店老板
Author: EmoryHuang
Date: 2021-08-06 15:57:33
Method:
滑动窗口
首先排除掉不生气时的顾客，只考虑生气时的顾客
建立大小为 minutes 的滑动窗口，计算不生气时的最大顾客数目
'''


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int],
                     minutes: int) -> int:
        n, ans = len(customers), 0
        # 计算不生气时的顾客人数
        for i, customer in enumerate(customers):
            if grumpy[i] == 0:
                ans += customer
                customers[i] = 0
        # 滑动窗口
        sumn = sum(customers[:minutes])
        r, maxn = minutes, sumn
        while r < n:
            sumn += customers[r]
            sumn -= customers[r - minutes]
            maxn = max(maxn, sumn)
            r += 1
        return ans + maxn
