'''
Descroption: ��ָ Offer 12. �����е�·��
Author: EmoryHuang
Date: 2021-06-29 21:15:00
����˼·:
DFS
ͨ���ݹ飬�ȳ�һ�������ѵ��ף��ٻ������ϸ��ڵ�
board[i][j] = ''��ʾ�ѷ��ʣ����ٶ��⿪�ռ�
'''


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])

        def dfs(i: int, j: int, ind: int) -> bool:
            # ���������Χ����δ�ҵ�Ԫ��
            if not 0 <= i < n or not 0 <= j < m or board[i][j] != word[ind]:
                return False
            if ind == len(word) - 1:
                return True
            # ��Ƿ���
            board[i][j] = ''
            res = dfs(i + 1, j, ind + 1) or dfs(i - 1, j, ind + 1) or \
                dfs(i, j + 1, ind + 1) or dfs(i, j - 1, ind + 1)
            # ��ԭ
            board[i][j] = word[ind]
            return res

        for i in range(n):
            for j in range(m):
                if dfs(i, j, 0):
                    return True
        return False
