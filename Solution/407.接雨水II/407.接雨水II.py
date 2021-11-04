'''
Descroption: LeetCode 407. ����ˮ II
Author: EmoryHuang
Date: 2021-11-02 09:21:25
Method:
���ȶ���
ά��һ��С����
ȷ����ǰ���ӵ�Ԫ�ض��ڸ����Ŀ���˵������Χ�ĸ��߶��е���Сֵ����ô����ȷ������ˮ�Ĵ�С
���Ƚ���Ե�������ȶ��У����󲻶����ڲ���С��Χ
�����Χ�ĸ߶ȴ��ڵ�ǰ�߶ȣ���ô���Թ�ˮ
'''


class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if len(heightMap) == 0:
            return 0
        m, n = len(heightMap), len(heightMap[0])
        ans = 0
        # vis ����Ƿ����
        vis = [[0] * n for _ in range(m)]
        # ά��һ��С����
        # ȷ����ǰ���ӵ�Ԫ�ض��ڸ����Ŀ���˵������Χ�ĸ��߶��е���Сֵ
        # ��ô����ȷ������ˮ�Ĵ�С
        heap = []
        # ����Ե�������ȶ���
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    vis[i][j] = 1
        while heap:
            h, i, j = heapq.heappop(heap)
            for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n and not vis[x][y]:
                    # �����Χ�ĸ߶ȴ��ڵ�ǰ�߶ȣ���ô���Թ�ˮ
                    if h > heightMap[x][y]:
                        ans += h - heightMap[x][y]
                    heapq.heappush(heap, (max(h, heightMap[x][y]), x, y))
                    vis[x][y] = 1
        return ans
