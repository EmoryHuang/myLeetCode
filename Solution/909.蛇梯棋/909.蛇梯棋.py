'''
Descroption: LeetCode 909. 蛇梯棋
Author: EmoryHuang
Date: 2021-06-27 14:06:00
解题思路:
BFS
每次可移动的范围为 6，进行广度优先遍历，得到 next
若 next 为蛇或梯子，那么更新 next
'''

from collections import deque


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)

        def change(pos: int):
            row, col = (pos - 1) // n, (pos - 1) % n
            if row % 2 == 1:
                col = n - col - 1
            return n - 1 - row, col

        q = deque([(1, 0)])  # 记录元素以及到达的需要的次数
        vis = {1}  # 记录元素是否访问
        while q:
            cur, step = q.popleft()
            if cur == n * n:
                return step
            for i in range(1, 7):
                next = cur + i
                if next > n * n:
                    break
                row, col = change(next)
                if board[row][col] > 0:
                    next = board[row][col]
                if next not in vis:
                    vis.add(next)
                    q.append((next, step + 1))
        return -1
