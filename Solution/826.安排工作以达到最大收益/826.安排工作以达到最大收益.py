'''
Descroption: LeetCode 826. 安排工作以达到最大收益
Author: EmoryHuang
Date: 2021-06-19 15:16:00
解题思路:
按照工人能力大小排序
对于每个工人，找到其能完成的工作的最大收益
'''


class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        # i 指向第 i 个工作
        # tmp 为可以完成的工作的最大利润
        i = ans = tmp = 0
        for cap in sorted(worker):  # 遍历每个工人
            while i < len(jobs) and cap >= jobs[i][0]:
                tmp = max(tmp, jobs[i][1])  # 找到利润最大的工作
                i += 1
            ans += tmp
        return ans
