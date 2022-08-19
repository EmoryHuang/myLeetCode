'''
Descroption: LeetCode 794. ��Ч�ľ�����Ϸ
Author: EmoryHuang
Date: 2021-11-05 15:35:18
Method:
�����ж������Ƿ��������
Ȼ����������ж��Ƿ����Ӯ�ң�������������Ҫ��
'''


class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        def win(c) -> bool:
            for i in range(3):
                if all(board[i][j] == c for j in range(3)):
                    return True
                if all(board[j][i] == c for j in range(3)):
                    return True
            return c == board[0][0] == board[1][1] == board[2][2] or c == board[0][
                2] == board[1][1] == board[2][0]

        s = ''.join(board)
        cnt = Counter(s)
        # �ж������Ƿ��������
        if (cnt['X'] - cnt['O']) not in [0, 1]:
            return False
        if win('X') and cnt['X'] != cnt['O'] + 1:
            return False
        if win('O') and cnt['X'] != cnt['O']:
            return False
        return True
