'''
Descroption: LCP 06. 拿硬币
Author: EmoryHuang
Date: 2021-07-08 18:48:24
解题思路:
简单题，除以2向上取整
'''


class Solution:
    def minCount(self, coins: List[int]) -> int:
        ans = 0
        for coin in coins:
            ans += math.ceil(coin / 2)
        return ans
