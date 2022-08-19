'''
Descroption: LeetCode 2045. 到达目的地的第二短时间
Author: EmoryHuang
Date: 2022-01-24 18:22:20
Method:
BFS
同时维护最短路和次短路，若 d < min_d[x]，则先用 min_d[x] 更新 sec_d[x]，再用 d 更新 min_d[x]
若 min_d[x] < d < sec_d[x]，则用 d 更新 sec_d[x]
对于红绿灯的切换问题: 经过 step 步
若 step % change 为奇，则为红灯，等待时间为 change - (step % change)
若 step % change 为偶，则为绿灯，等待时间为 0 
'''


class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int,
                      change: int) -> int:
        mmap = defaultdict(list)
        for i, j in edges:
            mmap[i].append(j)
            mmap[j].append(i)
        # min_d 和 sec_d 分别表示从 1 到 i 的最小和第二小的路径长度
        min_d, sec_d = [float('inf')] * (n + 1), [float('inf')] * (n + 1)
        min_d[1] = 0
        q = deque([(1, 0)])
        while q:
            u, dis = q.popleft()
            for v in mmap[u]:
                d = dis + 1
                if d < min_d[v]:
                    sec_d[v] = min_d[v]
                    min_d[v] = d
                    q.append((v, min_d[v]))
                    q.append((v, sec_d[v]))
                elif min_d[v] < d < sec_d[v]:
                    sec_d[v] = d
                    q.append((v, sec_d[v]))
        ans = 0
        for i in range(sec_d[n]):
            a, b = ans // change, ans % change
            wait = 0 if a % 2 == 0 else change - b
            ans += time + wait
        return ans