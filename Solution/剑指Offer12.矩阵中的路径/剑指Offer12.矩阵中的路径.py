'''
Descroption: 剑指 Offer 12. 矩阵中的路径
Author: EmoryHuang
Date: 2021-06-29 21:15:00
解题思路:
DFS
通过递归，先朝一个方向搜到底，再回溯至上个节点
board[i][j] = ''表示已访问，不再额外开空间
'''


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n, m = len(board), len(board[0])

        def dfs(i: int, j: int, ind: int) -> bool:
            # 如果超出范围或者未找到元素
            if not 0 <= i < n or not 0 <= j < m or board[i][j] != word[ind]:
                return False
            if ind == len(word) - 1:
                return True
            # 标记访问
            board[i][j] = ''
            res = dfs(i + 1, j, ind + 1) or dfs(i - 1, j, ind + 1) or \
                dfs(i, j + 1, ind + 1) or dfs(i, j - 1, ind + 1)
            # 还原
            board[i][j] = word[ind]
            return res

        for i in range(n):
            for j in range(m):
                if dfs(i, j, 0):
                    return True
        return False
