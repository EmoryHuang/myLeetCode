'''
Descroption: LeetCode 427. 建立四叉树
Author: EmoryHuang
Date: 2022-04-29 13:41:24
Method:
dfs
对于给定矩阵判断，行 r0 到 r1, 列 c0 到 c1是否均为 0 或 1
若不为 0 或 1，则递归地判断四个子矩阵
'''

"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""


class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def dfs(r0, c0, r1, c1):
            if all(grid[i][j] == grid[r0][c0] for i in range(r0, r1)
                   for j in range(c0, c1)):
                return Node(grid[r0][c0] == 1, True)
            else:
                node = Node(True, False)
                node.topLeft = dfs(r0, c0, (r0 + r1) // 2, (c0 + c1) // 2)
                node.topRight = dfs(r0, (c0 + c1) // 2, (r0 + r1) // 2, c1)
                node.bottomLeft = dfs((r0 + r1) // 2, c0, r1, (c0 + c1) // 2)
                node.bottomRight = dfs((r0 + r1) // 2, (c0 + c1) // 2, r1, c1)
                return node

        return dfs(0, 0, len(grid), len(grid[0]))
