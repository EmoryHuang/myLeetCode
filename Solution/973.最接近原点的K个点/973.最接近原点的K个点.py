'''
Descroption: LeetCode 973. ��ӽ�ԭ��� K ����
Author: EmoryHuang
Date: 2021-08-19 19:43:55
Method:
����һ��ֱ������
����������
����ʹ��һ�������ʵʱά��ǰ k ����С�ľ���ƽ��
��ÿ���ڵ���ԭ��ľ����Լ��ڵ��ż����
����python��С���ѣ���˴洢ʱ�洢�෴��
'''


class Solution:
    # ����һ��ֱ������
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return sorted(points, key=lambda x: (x[0]**2 + x[1]**2))[:k]

    # ����������
    # def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
    #     q = []
    #     for i, (x, y) in enumerate(points[:k]):
    #         q.append([-x**2 - y**2, i])
    #     heapq.heapify(q)
    #     for i in range(k, len(points)):
    #         x, y = points[i]
    #         d = -x**2 - y**2
    #         heapq.heappushpop(q, [d, i])
    #     ans = [points[i] for _, i in q]
    #     return ans
