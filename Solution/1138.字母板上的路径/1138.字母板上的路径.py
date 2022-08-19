'''
Descroption: LeetCode 1138. 字母板上的路径
Author: EmoryHuang
Date: 2021-08-23 15:53:56
Method:
由于字母板是比较规则的，因此可以计算出当前字母所在的行列
并与前一个字符所在的位置进行比较，根据相对位置确定路径
注意，由于 z 右边没有位置，因此先满足 z，移动时 R 的优先级最低
'''


class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        row, col = 0, 0
        ans = ''
        for c in target:
            # 更新前一个字符的位置
            prow, pcol = row, col
            # 当前字符所在的位置
            row, col = (ord(c) - ord('a')) // 5, (ord(c) - ord('a')) % 5
            ans += 'L' * (pcol - col) +'D' * (row - prow) + \
                    'U' * (prow - row) + 'R' * (col - pcol) + '!'
        return ans
