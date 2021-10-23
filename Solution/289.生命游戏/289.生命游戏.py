'''
Descroption: LeetCode 289. 生命游戏
Author: EmoryHuang
Date: 2021-10-23 09:17:53
Method:
利用一个 two bits 的状态机来记录细胞状态，第一位表示下一状态, 第二位表示当前状态
00: dead -> dead
01: livd -> dead
10: dead -> live
11: live -> live
遍历矩阵，记录细胞周围活细胞的数量，根据定律改变细胞状态
最后将数右移一位即可
'''


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) < 1:
            return
        dx = [1, 1, 1, 0, -1, -1, -1, 0]
        dy = [1, 0, -1, -1, -1, 0, 1, 1]
        m, n = len(board), len(board[0])
        # 利用一个 two bits 的状态机来记录细胞状态
        # 第一位表示下一状态, 第二位表示当前状态
        # 00: dead -> dead
        # 01: livd -> dead
        # 10: dead -> live
        # 11: live -> live
        for i in range(m):
            for j in range(n):
                cnt = 0  # 细胞周围活细胞的数量
                for k in range(8):
                    x, y = i + dx[k], j + dy[k]
                    if 0 <= x < m and 0 <= y < n:
                        cnt += (board[x][y] & 1)
                # 定律 1 & 3：对应状态 1
                # live -> live
                if board[i][j] & 1 == 1:
                    if cnt == 2 or cnt == 3:
                        board[i][j] = 3
                # dead -> live
                else:
                    if cnt == 3:
                        board[i][j] = 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
