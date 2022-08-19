'''
Descroption: LeetCode 815. ����·��
Author: EmoryHuang
Date: 2021-06-28 14:04:00
����˼·:
BFS��������·��Ȼ���ٸ�����·�ҳ�վ
ʹ�� map ��¼ (վ���ţ�[վ�����ڵ�·�߱��])
����������ȵķ�����������ǰվ�����ڵ�·�ߣ�����ǰ·��δ���ʣ����������·�ߵ�����վ��
���ҵ��� target����ô�ͷ����Ѿ�������·�ߵ���Ŀ
'''

from collections import defaultdict, deque


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        n, ans = len(routes), 1
        q = deque()
        q.append(source)
        vis = [0] * n  # ��¼·���Ƿ����
        map = defaultdict(set)  # (վ���ţ�[վ�����ڵ�·�߱��])
        for i in range(n):
            for station in routes[i]:
                map[station].add(i)
        while q:
            l = len(q)
            for i in range(l):
                cur = q.popleft()  # ��ǰվ��
                for route in map[cur]:  # ������ǰվ�����ڵ�·��
                    if not vis[route]:  # ����ǰ·��δ����
                        vis[route] = 1
                        for station in routes[route]:  # ��������·�ߵ�����վ��
                            if station == target:  # ���� target
                                return ans
                            q.append(station)
            ans += 1
        return -1
