'''
Descroption: LeetCode 999. ���Ա�һ�������������
Author: EmoryHuang
Date: 2021-08-19 19:03:25
Method:
���⣬���ҵ��׳���Ȼ����4���������
'''


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        for i in range(8):
            for j in range(8):
                # �ҵ��׳�
                if board[i][j] == 'R':
                    # ��4���������
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
