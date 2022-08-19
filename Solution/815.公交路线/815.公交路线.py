'''
Descroption: LeetCode 815. 公交路线
Author: EmoryHuang
Date: 2021-06-28 14:04:00
解题思路:
BFS，先找线路，然后再根据线路找车站
使用 map 记录 (站点编号，[站点所在的路线编号])
采样广度优先的方法，遍历当前站点所在的路线，若当前路线未访问，则遍历这条路线的所有站点
若找到了 target，那么就返回已经遍历的路线的数目
'''

from collections import defaultdict, deque


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        n, ans = len(routes), 1
        q = deque()
        q.append(source)
        vis = [0] * n  # 记录路线是否访问
        map = defaultdict(set)  # (站点编号，[站点所在的路线编号])
        for i in range(n):
            for station in routes[i]:
                map[station].add(i)
        while q:
            l = len(q)
            for i in range(l):
                cur = q.popleft()  # 当前站点
                for route in map[cur]:  # 遍历当前站点所在的路线
                    if not vis[route]:  # 若当前路线未访问
                        vis[route] = 1
                        for station in routes[route]:  # 遍历这条路线的所有站点
                            if station == target:  # 到达 target
                                return ans
                            q.append(station)
            ans += 1
        return -1
