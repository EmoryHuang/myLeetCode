'''
Descroption: LeetCode 1615. 最大网络秩
Author: EmoryHuang
Date: 2021-08-10 20:32:27
Method:
建图，统计每个节点的度
遍历节点对，寻找度之和最大的节点对
若这两个节点对之间有路径，则减1
'''


class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(list)
        degree = [0] * n
        for u, v in roads:
            graph[u].append(v)
            graph[v].append(u)
            # 统计节点的出入度
            degree[u] += 1
            degree[v] += 1
        ans, sum = 0, 0
        for i in range(1, n):
            for j in range(i):
                sum = degree[i] + degree[j]
                # 如果节点对之间有路径
                if i in graph[j]:
                    sum -= 1
                ans = max(ans, sum)
        return ans