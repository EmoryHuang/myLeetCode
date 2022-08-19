'''
Descroption: LeetCode 1222. ���Թ��������Ļʺ�
Author: EmoryHuang
Date: 2021-08-23 19:40:58
Method:
�ӹ�������������8�����򣬲鿴��ǰ�������Ƿ��лʺ�
'''


class Solution:
    def queensAttacktheKing(self, queens: List[List[int]],
                            king: List[int]) -> List[List[int]]:
        dx, dy = [0, -1, -1, -1, 0, 1, 1, 1], [1, 1, 0, -1, -1, -1, 0, 1]
        grid = [[0] * 8 for _ in range(8)]
        for x, y in queens:
            grid[x][y] = 1
        ans = []
        for i in range(8):
            x, y = king[0] + dx[i], king[1] + dy[i]
            while 0 <= x < 8 and 0 <= y < 8:
                if grid[x][y]:
                    ans.append([x, y])
                    break
                x += dx[i]
                y += dy[i]
        return ans