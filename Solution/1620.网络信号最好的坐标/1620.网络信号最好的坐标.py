'''
Descroption: LeetCode 1620. 网络信号最好的坐标
Author: EmoryHuang
Date: 2021-11-05 20:07:33
Method:
遍历所有点，找到网络信号最好的坐标
'''


class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        ans = [0, 0]
        maxq = 0
        # 遍历所有点
        for i in range(51):
            for j in range(51):
                cur = 0
                for x, y, q in towers:
                    d = sqrt((x - i)**2 + (y - j)**2)
                    if d <= radius:
                        cur += int(q / (1 + d))
                if cur > maxq:
                    maxq = cur
                    ans = [i, j]
        return ans