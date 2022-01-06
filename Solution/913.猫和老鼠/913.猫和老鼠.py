'''
Descroption: LeetCode 913. 猫和老鼠
Author: EmoryHuang
Date: 2022-01-04 12:37:51
Method:
动态规划 + 记忆化搜索
dp[k][i][j]表示进行了 k 步，老鼠的位置为 i，猫位置为 j的获胜情况
0,1,2分别代表平局，老鼠赢，猫赢
存在老鼠先手和猫先手的情况，所以需要两个状态
'''


class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(time, mouse, cat):
            if mouse == 0:
                return 1
            if mouse == cat:
                return 2
            if time >= 2 * n:
                return 0
            if not time % 2:  # 老鼠
                ans = 2
                for next in graph[mouse]:
                    cur = dfs(time + 1, next, cat)
                    if cur == 1:
                        return 1
                    elif cur == 0:
                        ans = 0
                return ans
            else:  # 猫
                ans = 1
                for next in graph[cat]:
                    if next == 0:
                        continue
                    cur = dfs(time + 1, mouse, next)
                    if cur == 2:
                        return 2
                    elif cur == 0:
                        ans = 0
                return ans

        n = len(graph)
        # dp[k][i][j]表示进行了 k 步，老鼠的位置为 i，猫位置为 j的获胜情况
        # 0,1,2分别代表平局，老鼠赢，猫赢
        # 存在老鼠先手和猫先手的情况，所以需要两个状态
        return dfs(0, 1, 2)
