'''
Descroption: LeetCode 857. 雇佣 K 名工人的最低成本  
Author: EmoryHuang
Date: 2022-09-11 13:44:27
Method:
贪心 + 大根堆
可以定义每个工人的性价比为 quality / wage
那么按照题目描述，k名工人的性价比由其中性价比最高的人决定
最终的价格为，总工作质量 × k名工人的最高性价比
具体来说，可以按照工人的性价比进行排序，使用大根堆维护工人工作质量
遍历每个工人，维护大根堆元素数量为k，并且工作质量最小
'''


class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        ans, totalq = float('inf'), 0
        heap = []
        # 按照性价比进行排序
        qw = sorted(zip(quality, wage), key=lambda x: x[1] / x[0])
        for q, w in qw:
            # 记录总工作质量
            totalq += q
            heapq.heappush(heap, -q)
            # 维护大根堆中数量为k，并且总工作质量最小
            if len(heap) > k:
                totalq += heapq.heappop(heap)
            if len(heap) == k:
                ans = min(ans, totalq * w / q)
        return ans