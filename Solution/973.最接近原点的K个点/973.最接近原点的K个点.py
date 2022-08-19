'''
Descroption: LeetCode 973. 最接近原点的 K 个点
Author: EmoryHuang
Date: 2021-08-19 19:43:55
Method:
方法一：直接排序
方法二：堆
可以使用一个大根堆实时维护前 k 个最小的距离平方
将每个节点与原点的距离以及节点编号加入堆
由于python是小根堆，因此存储时存储相反数
'''


class Solution:
    # 方法一：直接排序
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return sorted(points, key=lambda x: (x[0]**2 + x[1]**2))[:k]

    # 方法二：堆
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
