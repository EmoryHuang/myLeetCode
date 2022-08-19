'''
Descroption: LeetCode 502. IPO
Author: EmoryHuang
Date: 2021-09-08 15:09:49
Method:
堆
最大化资本时，我们不需要减去启动资金，只需要考虑纯利润
基本思想是这样的，首先，我们按启动资金从小到大进行排序
接着选择k个项目，在选择项目时，将所有的启动资金不超过 w 的项目加入优先队列
选择利润最大的那个项目即可
'''


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int],
                             capital: List[int]) -> int:
        # 按启动资金从小到大进行排序
        p = sorted(zip(capital, profits), key=lambda x: x[0])
        pick = []
        i = 0
        for _ in range(k):
            # 将所有的启动资金不超过 w 的任务加入优先队列
            while i < len(profits) and p[i][0] <= w:
                heapq.heappush(pick, -p[i][1])
                i += 1
            if not pick:  # 队列为空
                break
            # 从队列中选择利润最大的项目
            w -= heapq.heappop(pick)
        return w