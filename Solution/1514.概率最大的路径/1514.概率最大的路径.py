'''
Descroption: LeetCode 1514. ��������·��
Author: EmoryHuang
Date: 2021-06-16 14:04:00
����˼·:
spfa�㷨
���ڽӾ���洢ͼ
��ø�������·��
'''


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        mp = collections.defaultdict(list)
        for i, (x, y) in enumerate(edges):
            mp[x].append((y, succProb[i]))
            mp[y].append((x, succProb[i]))
        d = [0] * n
        inq = [0] * n
        q = [start]
        inq[start] = 1  # ����ڶ�����
        d[start] = 1    # ��㵽����ĸ���Ϊ1
        while q:
            u = q[0]
            q = q[1:]
            inq[u] = 0  # u���ڶ�����
            # �����ڽӽڵ�
            for v, dis in mp[u]:
                if d[v] < d[u] * dis:  # ���ʸ����·��
                    d[v] = d[u] * dis
                    if not inq[v]:
                        q.append(v)
                        inq[v] = 1
        return d[end]
