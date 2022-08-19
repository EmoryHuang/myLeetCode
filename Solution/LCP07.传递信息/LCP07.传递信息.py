'''
Descroption: LCP 07. 传递信息
Author: EmoryHuang
Date: 2021-07-01 13:23:00
解题思路:
总体的思路还是简单的，建立邻接矩阵
判断当前节点是否到达目标节点，并且步数为 k
方法一：DFS
方法二：BFS
'''


class Solution:
    # 方法一：DFS
    # def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
    #     self.ans = 0
    #     map = collections.defaultdict(list)
    #     for p, q in relation:
    #         map[p].append(q)

    #     def dfs(cur: int, step: int) -> None:
    #         if step == k:
    #             if cur == n - 1:
    #                 self.ans += 1
    #             return
    #         for next in map[cur]:
    #             dfs(next, step + 1)

    #     dfs(0, 0)
    #     return self.ans

    # 方法二：BFS
    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        map = collections.defaultdict(list)
        ans = 0
        for p, q in relation:
            map[p].append(q)
        q = collections.deque()
        q.append([0, 0])  # 记录当前节点以及到达步数
        while q:
            cur, step = q.popleft()
            if step > k:
                break
            # 找到一条路径
            if cur == n - 1 and step == k:
                ans += 1
            for next in map[cur]:
                q.append([next, step + 1])
        return ans
