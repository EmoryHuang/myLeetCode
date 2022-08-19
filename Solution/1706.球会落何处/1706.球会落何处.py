'''
Descroption: LeetCode 1706. 球会落何处
Author: EmoryHuang
Date: 2022-02-24 09:07:17
Method:
模拟
对于当前小球位置[x, y]，每次可以移动到[x+1, y+1]或者[x+1, y-1]
那么可以用 next = y + grid[x][y] 表示小球下一个位置的y坐标
若超出边界则说明被卡住；
若 grid[x][y] != grid[x][next] 则说明被卡住
'''


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        def next_pos(i):
            x, y = 0, i
            while x < m:
                next = y + grid[x][y]
                if next < 0 or next >= n:
                    return -1
                # 被卡住
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
