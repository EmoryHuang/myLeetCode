'''
Descroption: LeetCode 999. 可以被一步捕获的棋子数
Author: EmoryHuang
Date: 2021-08-19 19:03:25
Method:
简单题，先找到白车，然后向4个方向遍历
'''


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        for i in range(8):
            for j in range(8):
                # 找到白车
                if board[i][j] == 'R':
                    # 向4个方向遍历
                    for dx, dy in [(0, 1), (-1, 0), (0, -1), (1, 0)]:
                        x, y = i, j
                        while True:
                            x += dx
                            y += dy
                            if x < 0 or x >= 8 or y >= 8 or y < 0 or board[x][y] == 'B':
                                break
                            if board[x][y] == 'p':
                                ans += 1
                                break
                    return ans
        return 0
