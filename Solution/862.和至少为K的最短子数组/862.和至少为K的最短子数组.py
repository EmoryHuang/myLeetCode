'''
Descroption: LeetCode 862. 和至少为 K 的最短子数组
Author: EmoryHuang
Date: 2022-10-26 09:17:55
Method:
前缀和 + 单调队列
队列存储格式为 [idx, preSum], 维护队列递增
比较队列中最小的前缀和与当前前缀和之差是否 >= k
维护最短子数组
'''


class Solution:

    def shortestSubarray(self, nums: List[int], k: int) -> int:
        preSum, ans = [0], float('inf')
        # 队列存储格式为 [idx, preSum]
        q = deque()
        # 前缀和序列
        for num in nums:
            preSum.append(preSum[-1] + num)
        for i, curSum in enumerate(preSum):
            # 维护队列递增
            while q and q[-1][1] >= curSum:
                q.pop()
            # 考虑和至少为 K 的最短子数组
            while q and curSum - q[0][1] >= k:
                # 维护最小长度
                ans = min(ans, i - q.popleft()[0])
            q.append((i, curSum))
        return ans if ans != float('inf') else -1