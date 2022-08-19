'''
Descroption: LeetCode 661. ͼƬƽ����
Author: EmoryHuang
Date: 2022-03-24 09:00:15
Method:
����һ: ģ��
����ÿ���㲢�ж���Χ�ĵ��Ƿ���ڣ�ͳ������Ȼ�����ƽ��ֵ

������: ǰ׺��
ʹ�ö�άǰ׺�Ͷ� img ����Ԥ��������ǰ׺��
Ȼ�����ÿ���㣬ͬ�����ö�άǰ׺������Χ��ľ�ֵ
'''


class Solution:
    # ����һ: ģ��
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

    # ������: ǰ׺��
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
