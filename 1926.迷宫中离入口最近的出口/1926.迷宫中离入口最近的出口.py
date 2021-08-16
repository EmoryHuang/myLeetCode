'''
Descroption: LeetCode 1926. 迷宫中离入口最近的出口
Author: EmoryHuang
Date: 2021-08-16 20:07:25
Method:
层序遍历，如果到达边界点且不是入口，则说明找到了出口
'''


class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
        m, n = len(maze), len(maze[0])
        ans = -1
        q = deque([entrance])
        maze[entrance[0]][entrance[1]] = '+'
        while q:
            lenq = len(q)
            ans += 1
            for _ in range(lenq):
                x, y = q.popleft()
                # 如果到达边界点且不是入口
                if (x == 0 or x == m - 1 or y == 0 or y == n - 1) and ans:
                    return ans
                # 遍历4个方向
                for i in range(4):
                    nx, ny = x + dx[i], y + dy[i]
                    if 0 <= nx < m and 0 <= ny < n and maze[nx][ny] == '.':
                        # 标记为访问
                        maze[nx][ny] = '+'
                        q.append([nx, ny])
        return -1