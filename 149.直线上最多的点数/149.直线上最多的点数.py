'''
Descroption: LeetCode 149. ֱ�������ĵ���
Author: EmoryHuang
Date: 2021-06-24 15:12:00
����˼·:
����һ����������
�������������㣬Ȼ��Ƚ����������б���Ƿ���ͬ���ҵ����ֵ
����������ϣ��洢
����������֮���б�ʣ��ù�ϣ���¼б�ʳ��ֵĴ���
���ִ�������б�ʼ�Ϊֱ�������ĵ���
'''


class Solution:
    # ����һ����������
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

    # ����������ϣ��洢
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 1
        for i in range(n):
            hash = {}
            for j in range(i + 1, n):
                if i != j:
                    dx = points[i][0] - points[j][0]
                    dy = points[i][1] - points[j][1]
                    k = dy / dx if dx != 0 else 0x3f3f3f3f  # ����б��
                    if k in hash:  # ͳ��б�ʳ��ֵĴ���
                        hash[k] += 1
                    else:
                        hash[k] = 2
                    ans = max(ans, hash[k])
        return ans
