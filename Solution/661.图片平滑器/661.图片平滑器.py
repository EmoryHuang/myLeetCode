'''
Descroption: LeetCode 661. 图片平滑器
Author: EmoryHuang
Date: 2022-03-24 09:00:15
Method:
方法一: 模拟
遍历每个点并判断周围的点是否存在，统计数量然后计算平均值

方法二: 前缀和
使用二维前缀和对 img 进行预处理，计算前缀和
然后遍历每个点，同样利用二维前缀计算周围点的均值
'''


class Solution:
    # 方法一: 模拟
    # def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
    #     m, n = len(img), len(img[0])
    #     res = [[0] * n for _ in range(m)]
    #     for i in range(m):
    #         for j in range(n):
    #             cnt = 0
    #             for x in range(-1, 2):
    #                 for y in range(-1, 2):
    #                     if 0 <= i + x < m and 0 <= j + y < n:
    #                         res[i][j] += img[i + x][j + y]
    #                         cnt += 1
    #             res[i][j] //= cnt
    #     return res

    # 方法二: 前缀和
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        sum = [[0] * (n + 5) for _ in range(m + 5)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - \
                            sum[i - 1][j - 1] + img[i - 1][j - 1]
        res = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                a, b = max(0, i - 1), max(0, j - 1)
                c, d = min(m - 1, i + 1), min(n - 1, j + 1)
                cnt = (d - b + 1) * (c - a + 1)
                res[i][j] = (sum[c + 1][d + 1] - sum[c + 1][b] - sum[a][d + 1] +
                             sum[a][b]) // cnt
        return res
