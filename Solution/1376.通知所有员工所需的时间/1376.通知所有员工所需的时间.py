'''
Descroption: LeetCode 1376. 通知所有员工所需的时间
Author: EmoryHuang
Date: 2021-08-09 15:04:33
Method:
建有向图，dfs,bfs遍历
方法一：DFS
方法二：BFS
'''

class Solution:
    # 方法一：DFS
    # def numOfMinutes(self, n: int, headID: int, manager: List[int],
    #                  informTime: List[int]) -> int:
    #     if n == 1:
    #         return 0
    #     mp = defaultdict(list)
    #     for i, u in enumerate(manager):
    #         mp[u].append([i, informTime[i]])

    #     def dfs(cur: int) -> int:
    #         cnt = 0
    #         for u, val in mp[cur]:
    #             cnt = max(cnt, dfs(u) + val)
    #         return cnt

    #     return dfs(-1)

    # 方法二：BFS
    def numOfMinutes(self, n: int, headID: int, manager: List[int],
                     informTime: List[int]) -> int:
        if n == 1:
            return 0
        mp = defaultdict(list)
        for i, u in enumerate(manager):
            if u != -1:
                mp[u].append(i)
        q = deque()
        q.append([headID, 0])
        ans = 0
        while q:
            cur, val = q.popleft()
            ans = max(ans, val)
            for child in mp[cur]:
                q.append([child, val + informTime[cur]])
        return ans
