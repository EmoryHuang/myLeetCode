'''
Descroption: LeetCode 1276. 不浪费原料的汉堡制作方案
Author: EmoryHuang
Date: 2021-07-17 15:30:48
解题思路:
简单来说，就是求二元一次方程
4x + 2y = tomatoSlices
x + y = cheeseSlices
'''


class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        x = (tomatoSlices - 2 * cheeseSlices) / 2
        y = (4 * cheeseSlices - tomatoSlices) / 2
        if x >= 0 and y >= 0 and x == int(x) and y == int(y):
            return [int(x), int(y)]
        return []