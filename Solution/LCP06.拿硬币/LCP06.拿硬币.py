'''
Descroption: LCP 06. ��Ӳ��
Author: EmoryHuang
Date: 2021-07-08 18:48:24
����˼·:
���⣬����2����ȡ��
'''


class Solution:
    def minCount(self, coins: List[int]) -> int:
        ans = 0
        for coin in coins:
            ans += math.ceil(coin / 2)
        return ans
