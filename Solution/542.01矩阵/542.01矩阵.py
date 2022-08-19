'''
Descroption: LeetCode 542. 01 矩阵
Author: EmoryHuang
Date: 2021-07-30 15:02:05
Method:
从 0 的位置开始进行广度优先搜索
每次搜索到一个 1，就可以得到 0 到这个 1 的最短距离
为了简便，将非零元素标识为 -1 代表未访问
'''


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        q = deque()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append([i, j])
                else:
                    mat[i][j] = -1

        dx = [0, -1, 0, 1]
        dy = [1, 0, -1, 0]
        while q:
            x, y = q.popleft()
            for i in range(4):
                _x = x + dx[i]
                _y = y + dy[i]
                if 0 <= _x < n and 0 <= _y < m and mat[_x][_y] == -1:
                    mat[_x][_y] = mat[x][y] + 1
                    q.append([_x, _y])
        return mat