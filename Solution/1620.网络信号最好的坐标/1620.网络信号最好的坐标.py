'''
Descroption: LeetCode 1620. 网络信号最好的坐标
Author: EmoryHuang
Date: 2022-11-02 09:20:30
Method:
暴力枚举
由于数据范围较小，可以直接暴力枚举每个坐标的信号强度
'''


class Solution:

    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:

        def t2q(i, j, x, y, q):
            dis = math.sqrt((i - x)**2 + (j - y)**2)
            if dis > radius:
                return 0
            else:
                return q // (1 + dis)

        ans, max_q = [0, 0], 0
        for i in range(51):
            for j in range(51):
                cur_q = sum([t2q(i, j, x, y, q) for x, y, q, in towers])
                if cur_q > max_q:
                    max_q = cur_q
                    ans = [i, j]
        return ans
