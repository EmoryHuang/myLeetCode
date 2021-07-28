'''
Descroption: LeetCode 841. 钥匙和房间
Author: EmoryHuang
Date: 2021-07-28 16:55:16
Method:
dfs或bfs
使用一个列表记录已经访问的房间，使用队列记录当前可以打开的房间号
若当前房间未访问，则标记为访问，并将其中的要是加入队列
'''


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        q = deque()
        for key in rooms[0]:
            q.append(key)
        ans = [0]
        while q:
            num = q.popleft()
            if num not in ans:
                ans.append(num)
                for key in rooms[num]:
                    q.append(key)
        return len(ans) == n
