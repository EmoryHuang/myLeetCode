'''
Descroption: LeetCode 1334. ��ֵ�������ھ����ٵĳ���
Author: EmoryHuang
Date: 2021-08-02 16:02:58
Method:
ת��һ����˼��Ҳ������һ��Դ�㣬������ֵ���ܹ�����ĳ�����������
�������г�����ΪԴ�㣬ʹ��spfa�㷨��Floyd, Djistra�������·��
'''


class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # �����ڽӱ�
        mp = defaultdict(list)
        for u, v, w in edges:
            mp[u].append([v, w])
            mp[v].append([u, w])
        ans, mincnt = -1, float('inf')
        # �������г�����ΪԴ��
        for i in range(n):
            # spfa �㷨������С����
            dis = [float('inf')] * n
            inq = [False] * n
            q = deque()
            q.append(i)
            inq[i] = True
            dis[i] = 0
            while q:
                u = q.popleft()
                inq[u] = False
                for j in range(len(mp[u])):
                    v = mp[u][j][0]
                    w = mp[u][j][1]
                    if dis[v] > dis[u] + w:
                        dis[v] = dis[u] + w
                        if not inq[v]:
                            q.append(v)
                            inq[v] = True
            cnt = 0
            for k in range(n):
                if dis[k] <= distanceThreshold:
                    cnt += 1
            # �����ھ����ٵĳ���
            if cnt <= mincnt:
                mincnt = cnt
                ans = i
        return ans
