'''
Descroption: LeetCode 1140. 石子游戏 II
Author: EmoryHuang
Date: 2023-02-22 09:24:10
Method:
前缀和 + 记忆化搜索
dfs(pos, m) 表示从下标pos开始拿，可以拿到的最大石子数量
'''


class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        @cache
        def dfs(i, m):
            if m * 2 >= n - i:
                return s[n] - s[i]
            return max(s[n] - s[i] - dfs(i + x, max(m, x)) for x in range(1, m << 1 | 1))

        n = len(piles)
        s = list(accumulate(piles, initial=0))
        return dfs(0, 1)
