'''
Descroption: LeetCode 909. ������
Author: EmoryHuang
Date: 2021-06-27 14:06:00
����˼·:
BFS
ÿ�ο��ƶ��ķ�ΧΪ 6�����й�����ȱ������õ� next
�� next Ϊ�߻����ӣ���ô���� next
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

        q = deque([(1, 0)])  # ��¼Ԫ���Լ��������Ҫ�Ĵ���
        vis = {1}  # ��¼Ԫ���Ƿ����
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
