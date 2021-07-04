'''
Descroption: 剑指 Offer 63. 股票的最大利润
Author: EmoryHuang
Date: 2021-07-04 13:56:55
解题思路:
因为买入价一定在卖出价之前，因此维护一个最小值，遍历价格寻找最大利润
'''


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        ans, min = 0, math.inf
        for price in prices:
            if price < min:
                min = price
            else:
                ans = max(ans, price - min)
        return ans
