'''
Descroption: LeetCode 743. �����ӳ�ʱ��
Author: EmoryHuang
Date: 2021-08-02 14:06:11
Method:
�� k ��������������� x ����̾�������ֵ
����һ��SPFA�㷨
��������Floyd�㷨
������������dijkstra�㷨
'''


class Solution:
    # ����һ��SPFA�㷨
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # �����ڽӱ�
        mp = defaultdict(list)
        for u, v, w in times:
            mp[u].append([v, w])
        d = [float('inf')] * (n + 1)
        q = deque()
        inq = [False] * (n + 1)
        d[k] = d[0] = 0
        q.append(k)
        inq[k] = True  # �ڵ��Ƿ��ڶ�����

        while q:
            u = q.popleft()  # ȡ����Ԫ��
            inq[u] = False  # ����
            for j in range(len(mp[u])):  # ������u���ڵĽڵ�
                v = mp[u][j][0]  # �ڵ���
                w = mp[u][j][1]  # ��Ȩ
                if d[v] > d[u] + w:  # ������̾���
                    d[v] = d[u] + w
                    if not inq[v]:
                        q.append(v)
                        inq[v] = True
        for dis in d:
            if dis == float('inf'):
                return -1
        return max(d)

    # ��������Floyd�㷨
    # def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    #     # �����ڽӾ���
    #     mp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    #     for i in range(n + 1):
    #         mp[i][i] = mp[i][0] = mp[0][i] = 0
    #     for u, v, w in times:
    #         mp[u][v] = w

    #     for t in range(1, n + 1):
    #         for i in range(1, n + 1):
    #             for j in range(1, n + 1):
    #                 mp[i][j] = min(mp[i][j], mp[i][t] + mp[t][j])
    #     for i in range(1, n + 1):
    #         if mp[k][i] == float('inf'):
    #             return -1
    #     return max(mp[k])

    # ������������dijkstra�㷨
    # def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
    #     # �����ڽӾ���
    #     mp = [[float('inf')] * (n + 1) for _ in range(n + 1)]
    #     for i in range(n + 1):
    #         mp[i][i] = 0
    #     for u, v, w in times:
    #         mp[u][v] = w

    #     d = [float('inf')] * (n + 1)
    #     vis = [False] * (n + 1)
    #     d[k] = d[0] = 0  # ��㵽����ľ���Ϊ0
    #     for i in range(1, n + 1):
    #         u = -1  # Ѱ�Ҿ�����С�ĵ�
    #         for j in range(1, n + 1):
    #             if not vis[j] and (u == -1 or d[u] > d[j]):
    #                 u = j
    #         vis[u] = True
    #         for v in range(1, n + 1):
    #             d[v] = min(d[v], d[u] + mp[u][v])  # ��uΪ�н��
    #     for dis in d:
    #         if dis == float('inf'):
    #             return -1
    #     return max(d)
