'''
Descroption: LeetCode 149. 直线上最多的点数
Author: EmoryHuang
Date: 2021-06-24 15:12:00
解题思路:
方法一：暴力遍历
遍历任意两个点，然后比较与其他点的斜率是否相同，找到最大值
方法二：哈希表存储
计算两个点之间的斜率，用哈希表记录斜率出现的次数
出现次数最多的斜率即为直线上最多的点数
'''


class Solution:
    # 方法一：暴力遍历
    # def maxPoints(self, points: List[List[int]]) -> int:
    #     n = len(points)
    #     ans = 1
    #     for i in range(n):
    #         x = points[i]
    #         for j in range(i + 1, n):
    #             y = points[j]
    #             cnt = 2
    #             for k in range(j + 1, n):
    #                 z = points[k]
    #                 d1 = (y[1] - x[1]) * (z[0] - y[0])
    #                 d2 = (z[1] - y[1]) * (y[0] - x[0])
    #                 if d1 == d2:
    #                     cnt += 1
    #             ans = max(ans, cnt)
    #     return ans

    # 方法二：哈希表存储
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n):
            hash = {}
            for j in range(i + 1, n):
                if i != j:
                    dx = points[i][0] - points[j][0]
                    dy = points[i][1] - points[j][1]
                    k = dy / dx if dx != 0 else 0x3f3f3f3f  # 计算斜率
                    if k in hash:  # 统计斜率出现的次数
                        hash[k] += 1
                    else:
                        hash[k] = 2
                    ans = max(ans, hash[k])
        return ans
