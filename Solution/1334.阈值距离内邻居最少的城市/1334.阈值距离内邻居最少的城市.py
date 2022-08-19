'''
Descroption: LeetCode 1334. 阈值距离内邻居最少的城市
Author: EmoryHuang
Date: 2021-08-02 16:02:58
Method:
转换一下意思，也就是求一个源点，它在阈值内能够到达的城市数量最少
遍历所有城市作为源点，使用spfa算法（Floyd, Djistra）求最短路径
'''


class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # 构建邻接表
        mp = defaultdict(list)
        for u, v, w in edges:
            mp[u].append([v, w])
            mp[v].append([u, w])
        ans, mincnt = -1, float('inf')
        # 遍历所有城市作为源点
        for i in range(n):
            # spfa 算法计算最小距离
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
            # 更新邻居最少的城市
            if cnt <= mincnt:
                mincnt = cnt
                ans = i
        return ans
