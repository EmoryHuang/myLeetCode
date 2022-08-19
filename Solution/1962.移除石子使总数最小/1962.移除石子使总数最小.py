'''
Descroption: LeetCode 1962. 移除石子使总数最小
Author: EmoryHuang
Date: 2021-10-21 09:16:30
Method:
大根堆
维护一个大根堆，取堆顶元素 / 2 再入堆，计算堆内元素之和
'''


class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = [-num for num in piles]
        heapq.heapify(heap)
        while k > 0:
            cur = -heapq.heappop(heap)
            heapq.heappush(heap, -cur // 2)
            k -= 1
        return -sum(heap)
