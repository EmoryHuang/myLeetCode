'''
Descroption: LeetCode 847. 访问所有节点的最短路径
Author: EmoryHuang
Date: 2021-08-06 15:15:58
Method:
BFS + 状态压缩
为了标识城市的访问状态，使用状态压缩，即一位表示一个节点是否访问
当均为遍历时，mask = (000) = 0，当遍历完时，mask = (111) = 2^n - 1
同样的，更新第 i 个节点的状态时：next_mask = mask | (1 << i)
回到题目，一开始，由于起点不确定，因此将所有节点均入队
使用BFS进行多个起点的遍历
'''


class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        # 由于起点不确定，因此vis为n行2^n列，以记录每个的状态
        vis = [[False] * (1 << n) for _ in range(n)]
        q = deque()
        for i in range(n):
            # 将节点序号id，状态mask和距离dis入队
            # 状态mask使用位标识每个节点是否访问
            q.append([i, 1 << i, 0])
            vis[i][1 << i] = True
        while q:
            id, mask, dis = q.popleft()
            # 如果已经访问了全部节点，即状态为 2^n - 1
            if mask == (1 << n) - 1:
                return dis
            for ne in graph[id]:
                next_mask = mask | (1 << ne)  # 或运算得到下一个状态
                if not vis[ne][next_mask]:
                    q.append([ne, next_mask, dis + 1])
                    vis[ne][next_mask] = True
        return 0
