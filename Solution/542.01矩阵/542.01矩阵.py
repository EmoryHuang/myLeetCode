'''
Descroption: LeetCode 542. 01 ����
Author: EmoryHuang
Date: 2021-07-30 15:02:05
Method:
�� 0 ��λ�ÿ�ʼ���й����������
ÿ��������һ�� 1���Ϳ��Եõ� 0 ����� 1 ����̾���
Ϊ�˼�㣬������Ԫ�ر�ʶΪ -1 ����δ����
'''


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        q = deque()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.append([i, j])
                else:
                    mat[i][j] = -1

        dx = [0, -1, 0, 1]
        dy = [1, 0, -1, 0]
        while q:
            x, y = q.popleft()
            for i in range(4):
                _x = x + dx[i]
                _y = y + dy[i]
                if 0 <= _x < n and 0 <= _y < m and mat[_x][_y] == -1:
                    mat[_x][_y] = mat[x][y] + 1
                    q.append([_x, _y])
        return mat