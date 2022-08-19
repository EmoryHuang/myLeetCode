'''
Descroption: LeetCode 987. 二叉树的垂序遍历
Author: EmoryHuang
Date: 2021-07-31 13:31:33
Method:
dfs + 排序
dfs 得到所有节点的坐标，然后按列排序
像相同列号的元素放入同一矩阵
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        nodes = []

        def dfs(node: TreeNode, x: int, y: int) -> None:
            if not node:
                return
            nodes.append([y, x, node.val])
            dfs(node.left, x + 1, y - 1)
            dfs(node.right, x + 1, y + 1)

        # dfs 得到所有节点的坐标
        dfs(root, 0, 0)
        # 按列排列
        nodes.sort()
        ans = []
        precol = float('-inf')  # 前一个节点的列
        for y, x, val in nodes:
            # 如果不在同一列
            if y != precol:
                precol = y
                ans.append(list())
            ans[-1].append(val)
        return ans
