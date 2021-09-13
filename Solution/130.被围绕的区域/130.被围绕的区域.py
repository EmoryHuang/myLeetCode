'''
Descroption: LeetCode 130. 被围绕的区域
Author: EmoryHuang
Date: 2021-09-13 20:30:40
Method:
dfs/bfs
从边界 O 出发，找到所有与边界 O 相邻的 O，标记为 #
然后再次遍历矩阵，将所有剩下的 O 转为 X，# 转为 O 
'''


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])

        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                board[i][j] = '#'
                for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                    dfs(x, y)

        for i in range(m):
            if board[i][0] == "O": dfs(i, 0)
            if board[i][n - 1] == "O": dfs(i, n - 1)
        for j in range(n):
            if board[0][j] == "O": dfs(0, j)
            if board[m - 1][j] == "O": dfs(m - 1, j)
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'