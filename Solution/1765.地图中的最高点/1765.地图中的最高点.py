'''
Descroption: LeetCode 1765. ��ͼ�е���ߵ�
Author: EmoryHuang
Date: 2021-08-27 16:00:53
Method:
�ҵ����е�ˮ�򣬷������
Ȼ����й�����ȱ�������4������Ѱ��½�أ��޸ĸ߶� + 1
'''


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        ans = [[0] * n for _ in range(m)]
        q = deque()
        # �ҵ����е�ˮ�򣬷������
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    q.append([i, j])
        while q:
            i, j = q.popleft()
            for dx, dy in [[0, 1], [-1, 0], [0, -1], [1, 0]]:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and isWater[x][y] == 0:
                    ans[x][y] = ans[i][j] + 1
                    isWater[x][y] = 1
                    q.append([x, y])
        return ans
