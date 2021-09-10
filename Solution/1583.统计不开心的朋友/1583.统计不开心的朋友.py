'''
Descroption: LeetCode 1583. 统计不开心的朋友
Author: EmoryHuang
Date: 2021-08-14 13:46:59
Method:
模拟
获得 y 在 x 处亲近程度的下标并记录配对情况
遍历每个人 x, 获得 x 的配对 y 以及 y 与 x 的亲密程度次序 index
遍历每个可能的 u，0 ~ index - 1，找到与朋友 u 配对的朋友 v
如果 u 与 x 的亲近程度胜过 u 与 v，则 x 不开心
'''


class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]],
                       pairs: List[List[int]]) -> int:
        # 获得 y 在 x 处亲近程度的下标
        order = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n - 1):
                order[i][preferences[i][j]] = j
        # 记录配对情况
        pair = [0] * n
        for x, y in pairs:
            pair[x] = y
            pair[y] = x
        ans = 0
        for x in range(n):
            # 获得 x 的配对 y 以及 y 与 x 的亲密程度次序
            y = pair[x]
            index = order[x][y]
            for i in range(index):
                # 遍历每个可能的 u，找到与朋友 u 配对的朋友 v
                u = preferences[x][i]
                v = pair[u]
                # 如果 u 与 x 的亲近程度胜过 u 与 v
                if order[u][x] < order[u][v]:
                    ans += 1
                    break
        return ans
