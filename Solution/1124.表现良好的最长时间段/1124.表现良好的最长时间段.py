'''
Descroption: LeetCode 1124. 表现良好的最长时间段
Author: EmoryHuang
Date: 2023-02-14 09:25:35
Method:
前缀和 + 单调栈

'''


class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        n = len(hours)
        score = [0] * n
        for i in range(n):
            if hours[i] > 8:
                score[i] = 1
            else:
                score[i] = -1
        presum = [0] * (n + 1)
        for i in range(1, n + 1):
            presum[i] = presum[i - 1] + score[i - 1]
        ans = 0
        stack = []
        for i in range(n + 1):
            if not stack or presum[i] < presum[stack[-1]]:
                stack.append(i)
        i = n
        while i > ans:
            while stack and presum[stack[-1]] < presum[i]:
                ans = max(ans, i - stack[-1])
                stack.pop()
            i -= 1
        return ans
