'''
Descroption: LeetCode 210. 课程表 II
Author: EmoryHuang
Date: 2021-10-23 14:39:09
Method:
拓扑排序
维护一个队列，将入度为 0 的节点入队，然后将其连接的节点入度减一
直到队列为空
'''


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        edges = defaultdict(list)
        indegree = [0] * numCourses
        # 建立邻接表
        for a, b in prerequisites:
            edges[b].append(a)
            indegree[a] += 1
        q = deque()
        # 将入度为 0 的节点入队
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
        ans = []
        while q:
            u = q.popleft()
            ans.append(u)
            for v in edges[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
        if len(ans) != numCourses:
            return []
        return ans
