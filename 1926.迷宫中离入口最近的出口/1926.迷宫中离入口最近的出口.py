'''
Descroption: LeetCode 1926. �Թ������������ĳ���
Author: EmoryHuang
Date: 2021-08-16 20:07:25
Method:
����������������߽���Ҳ�����ڣ���˵���ҵ��˳���
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
                # �������߽���Ҳ������
                if (x == 0 or x == m - 1 or y == 0 or y == n - 1) and ans:
                    return ans
                # ����4������
                for i in range(4):
                    nx, ny = x + dx[i], y + dy[i]
                    if 0 <= nx < m and 0 <= ny < n and maze[nx][ny] == '.':
                        # ���Ϊ����
                        maze[nx][ny] = '+'
                        q.append([nx, ny])
        return -1