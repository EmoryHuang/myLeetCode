'''
Descroption: 剑指 Offer 13. 机器人的运动范围
Author: EmoryHuang
Date: 2021-07-02 14:16:00
解题思路:
计算每个坐标的各位数之后，而后判断
遍历每行每列，若各位数之和大于 k，则加入到 vis
'''


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:

        def get_sum(num: int) -> int:
            res = 0
            while num:
                res += num % 10
                num //= 10
            return res

        vis = set([(0, 0)])
        for i in range(m):
            for j in range(n):
                if get_sum(i) + get_sum(j) <= k and ((i - 1, j) in vis or (i, j - 1) in vis):
                    vis.add((i, j))
        return len(vis)
