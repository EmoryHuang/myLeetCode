'''
Descroption: LeetCode 419. 甲板上的战舰
Author: EmoryHuang
Date: 2021-12-18 08:45:47
Method:
方法一: dfs
由于没有相邻的战舰，因此可以简单使用dfs, 并查集等方法解决

方法二: 一次扫描
当且仅当某个 X 格子的「上方」&「左方」不为 X 时，该格子为战舰首个格子，可以进行计数
同时注意边界问题
'''


class Solution:
    # 方法一: dfs
    # def countBattleships(self, board: List[List[str]]) -> int:
    #     def dfs(i, j):
    #         board[i][j] = '.'
    #         for dx, dy in {(0, 1), (1, 0), (-1, 0), (0, -1)}:
    #             x, y = i + dx, j + dy
    #             if 0 <= x < m and 0 <= y < n and board[x][y] == 'X':
    #                 dfs(x, y)

    #     if not board:
    #         return 0
    #     m, n = len(board), len(board[0])
    #     count = 0
    #     for i in range(m):
    #         for j in range(n):
    #             if board[i][j] == 'X':
    #                 dfs(i, j)
    #                 count += 1
    #     return count

    # 方法二: 一次扫描
    def countBattleships(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        count = 0
        for i in range(m):
            for j in range(n):
                # 当且仅当某个 X 格子的「上方」&「左方」不为 X 时，该格子为战舰首个格子，可以进行计数
                # 同时注意边界问题
                if i > 0 and board[i - 1][j] == 'X':
                    continue
                if j > 0 and board[i][j - 1] == 'X':
                    continue
                if board[i][j] == 'X':
                    count += 1
        return count
