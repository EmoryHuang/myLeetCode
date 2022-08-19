'''
Descroption: LeetCode 1706. �����δ�
Author: EmoryHuang
Date: 2022-02-24 09:07:17
Method:
ģ��
���ڵ�ǰС��λ��[x, y]��ÿ�ο����ƶ���[x+1, y+1]����[x+1, y-1]
��ô������ next = y + grid[x][y] ��ʾС����һ��λ�õ�y����
�������߽���˵������ס��
�� grid[x][y] != grid[x][next] ��˵������ס
'''


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        def next_pos(i):
            x, y = 0, i
            while x < m:
                next = y + grid[x][y]
                if next < 0 or next >= n:
                    return -1
                # ����ס
                if grid[x][y] != grid[x][next]:
                    return -1
                x += 1
                y = next
            return y

        m, n = len(grid), len(grid[0])
        ans = []
        for i in range(n):
            ans.append(next_pos(i))
        return ans
