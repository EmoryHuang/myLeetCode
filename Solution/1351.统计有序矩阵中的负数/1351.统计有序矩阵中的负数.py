'''
Descroption: LeetCode 1351. ͳ����������еĸ���
Author: EmoryHuang
Date: 2021-06-22 19:30:00
����˼·:
����ǰ��Ϊ��������ôʣ�µ�����ȻҲ�Ǹ����������������һ��
'''


class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] < 0:
                    cnt += n - j
                    break
        return cnt
