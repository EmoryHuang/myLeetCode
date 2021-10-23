'''
Descroption: LeetCode 289. ������Ϸ
Author: EmoryHuang
Date: 2021-10-23 09:17:53
Method:
����һ�� two bits ��״̬������¼ϸ��״̬����һλ��ʾ��һ״̬, �ڶ�λ��ʾ��ǰ״̬
00: dead -> dead
01: livd -> dead
10: dead -> live
11: live -> live
�������󣬼�¼ϸ����Χ��ϸ�������������ݶ��ɸı�ϸ��״̬
���������һλ����
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
        # ����һ�� two bits ��״̬������¼ϸ��״̬
        # ��һλ��ʾ��һ״̬, �ڶ�λ��ʾ��ǰ״̬
        # 00: dead -> dead
        # 01: livd -> dead
        # 10: dead -> live
        # 11: live -> live
        for i in range(m):
            for j in range(n):
                cnt = 0  # ϸ����Χ��ϸ��������
                for k in range(8):
                    x, y = i + dx[k], j + dy[k]
                    if 0 <= x < m and 0 <= y < n:
                        cnt += (board[x][y] & 1)
                # ���� 1 & 3����Ӧ״̬ 1
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
