'''
Descroption: LeetCode 1518. »»¾ÆÎÊÌâ
Author: EmoryHuang
Date: 2021-08-11 15:15:19
Method:
¼òµ¥Ìâ£¬ÂúÆ¿»»³É¿ÕÆ¿
'''


class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        empty = numBottles
        while empty >= numExchange:
            numBottles += empty // numExchange
            empty = empty % numExchange + empty // numExchange
        return numBottles
