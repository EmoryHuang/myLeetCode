'''
Descroption: ��ָ Offer 13. �����˵��˶���Χ
Author: EmoryHuang
Date: 2021-07-02 14:16:00
����˼·:
����ÿ������ĸ�λ��֮�󣬶����ж�
����ÿ��ÿ�У�����λ��֮�ʹ��� k������뵽 vis
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
