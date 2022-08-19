'''
Descroption: LeetCode 1812. 判断国际象棋棋盘中一个格子的颜色
Author: EmoryHuang
Date: 2021-06-17 15:49:00
解题思路:
简单题，横竖序号相加若为奇数，则是白色，否则为黑
'''


class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        ind = ord(coordinates[0]) + int(coordinates[1])
        return ind % 2 == 1
