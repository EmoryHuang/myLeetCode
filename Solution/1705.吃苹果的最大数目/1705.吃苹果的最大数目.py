'''
Descroption: LeetCode 1705. 吃苹果的最大数目
Author: EmoryHuang
Date: 2021-12-24 09:04:16
Method:
模拟 + 优先队列
维护一个小根堆，分别存储每天采摘信息 (days[i], apples[i], pickday)
每天要吃苹果时，取堆顶元素，直到堆顶的苹果不是腐烂的
吃完后，更新第 pickday 天的苹果数量
'''


class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        heap = []
        ans, i = 0, 0
        while heap or i < len(days):
            eat = False
            if i < len(days) and apples[i] != 0:
                # 维护一个小根堆，分别存储每天采摘信息 (days[i] + pickday, apples[i])
                heapq.heappush(heap, (days[i] + i, apples[i]))
            while heap and not eat:
                # 取堆顶元素，直到堆顶的苹果不是腐烂的
                day, apple = heapq.heappop(heap)
                # 检查苹果是否腐烂
                if i >= day:
                    continue
                ans += 1
                eat = True
                # 更新第 pick 天的苹果数量
                if apple - 1 != 0:
                    heapq.heappush(heap, (day, apple - 1))
            i += 1
        return ans
