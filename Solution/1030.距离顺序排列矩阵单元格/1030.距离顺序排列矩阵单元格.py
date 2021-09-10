'''
Descroption: LeetCode 1030. ����˳�����о���Ԫ��
Author: EmoryHuang
Date: 2021-08-18 19:36:25
Method:
����һ��ֱ������
������λ�ü������飬Ȼ�������پ�������
��������BFS
���չ�����ȱ�����˼�룬�������������꣬��ӵ�˳��ʵ���Ͼ��������پ���
'''


class Solution:
    # ����һ��ֱ������
    # def allCellsDistOrder(self, rows: int, cols: int, rCenter: int,
    #                       cCenter: int) -> List[List[int]]:
    #     ans = []
    #     for i in range(rows):
    #         for j in range(cols):
    #             ans.append([i, j])
    #     return sorted(ans, key=lambda x: abs(x[0] - rCenter) + abs(x[1] - cCenter))

    # ��������BFS
    def allCellsDistOrder(self, rows: int, cols: int, rCenter: int,
                          cCenter: int) -> List[List[int]]:
        dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
        q = deque()
        q.append([rCenter, cCenter])
        vis = [[False] * cols for _ in range(rows)]
        vis[rCenter][cCenter] = True
        ans = []
        while q:
            r, c = q.popleft()
            ans.append([r, c])
            for i in range(4):
                nr, nc = r + dx[i], c + dy[i]
                if 0 <= nr < rows and 0 <= nc < cols and not vis[nr][nc]:
                    q.append([nr, nc])
                    vis[nr][nc] = True
        return ans
