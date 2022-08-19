'''
Descroption: LeetCode 733. 图像渲染
Author: EmoryHuang
Date: 2021-08-11 20:40:30
Method:
dfs
从给定的起点开始，进行深度优先搜索
每次搜索到一个方格时，如果其与初始位置的方格颜色相同，就将该方格的颜色更新
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