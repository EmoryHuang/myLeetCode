'''
Descroption: LeetCode 1742. 盒子中小球的最大数量
Author: EmoryHuang
Date: 2022-11-23 09:08:11
Method:
使用哈希表记录每个盒子的小球数量
'''


class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        hash = [0] * 50
        for num in range(lowLimit, highLimit + 1):
            box = 0
            while num:
                box += num % 10
                num //= 10
            hash[box] += 1
        return max(hash)
