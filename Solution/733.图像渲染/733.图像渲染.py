'''
Descroption: LeetCode 733. ͼ����Ⱦ
Author: EmoryHuang
Date: 2021-08-11 20:40:30
Method:
dfs
�Ӹ�������㿪ʼ�����������������
ÿ��������һ������ʱ����������ʼλ�õķ�����ɫ��ͬ���ͽ��÷������ɫ����
'''


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int,
                  newColor: int) -> List[List[int]]:
        if image[sr][sc] == newColor:
            return image
        dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
        m, n = len(image), len(image[0])
        cur = image[sr][sc]

        def dfs(x: int, y: int) -> None:
            if 0 <= x < m and 0 <= y < n and image[x][y] == cur:
                image[x][y] = newColor
                for i in range(4):
                    dfs(x + dx[i], y + dy[i])

        dfs(sr, sc)
        return image