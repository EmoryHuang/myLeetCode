class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        g, preSum = [], [0]
        for i, num in enumerate(nums):
            if num == 1:
                g.append(i - len(g))
                preSum.append(preSum[-1] + g[-1])
        m, res = len(g), inf
        for i in range(m - k + 1):
            mid = i + k // 2
            r = g[mid]
            res = min(res, (1 - k % 2) * r + (preSum[i + k] - preSum[mid + 1]) - (preSum[mid] - preSum[i]))
        return res
