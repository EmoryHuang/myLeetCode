'''
Descroption: LeetCode 802. 找到最终的安全状态
Author: EmoryHuang
Date: 2021-08-05 14:10:30
Method:
反向图 + 拓扑排序
统计每个节点的出度，并将图存储为反向图
首先将出度为 0 的节点入队
通过拓扑排序，不断去除边，然后将出度为 0 的节点入队
最后统计出度为 0 的节点
'''


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        mp = defaultdict(list)
        outdegree = [0] * n
        q = deque()
        for i, nodes in enumerate(graph):
            # 统计所有节点的出度
            outdegree[i] = len(nodes)
            if not outdegree[i]:
                # 将出度为 0 的节点入队
                q.append(i)
            else:
                # 构建反向图
                for node in nodes:
                    mp[node].append(i)
        # 拓扑排序
        while q:
            node = q.popleft()
            for ne in mp[node]:
                outdegree[ne] -= 1
                if not outdegree[ne]:
                    q.append(ne)
        # 统计出度为 0 的节点
        return [i for i in range(n) if not outdegree[i]]
