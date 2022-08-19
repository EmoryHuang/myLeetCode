'''
Descroption: LeetCode 794. 有效的井字游戏
Author: EmoryHuang
Date: 2021-11-05 15:35:18
Method:
首先判断数量是否满足情况
然后遍历数组判断是否存在赢家，并且满足数量要求
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
        # 判断数量是否满足情况
        if (cnt['X'] - cnt['O']) not in [0, 1]:
            return False
        if win('X') and cnt['X'] != cnt['O'] + 1:
            return False
        if win('O') and cnt['X'] != cnt['O']:
            return False
        return True
