'''
Descroption: LeetCode 419. �װ��ϵ�ս��
Author: EmoryHuang
Date: 2021-12-18 08:45:47
Method:
����һ: dfs
����û�����ڵ�ս������˿��Լ�ʹ��dfs, ���鼯�ȷ������

������: һ��ɨ��
���ҽ���ĳ�� X ���ӵġ��Ϸ���&���󷽡���Ϊ X ʱ���ø���Ϊս���׸����ӣ����Խ��м���
ͬʱע��߽�����
'''


class Solution:
    # ����һ: dfs
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

    # ������: һ��ɨ��
    def countBattleships(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        count = 0
        for i in range(m):
            for j in range(n):
                # ���ҽ���ĳ�� X ���ӵġ��Ϸ���&���󷽡���Ϊ X ʱ���ø���Ϊս���׸����ӣ����Խ��м���
                # ͬʱע��߽�����
                if i > 0 and board[i - 1][j] == 'X':
                    continue
                if j > 0 and board[i][j - 1] == 'X':
                    continue
                if board[i][j] == 'X':
                    count += 1
        return count
