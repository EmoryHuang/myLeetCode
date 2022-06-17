'''
Descroption: LeetCode 1022. 从根到叶的二进制数之和
Author: EmoryHuang
Date: 2022-05-30 12:42:24
Method:
dfs
简单题，dfs 计算每条路径的和
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node: TreeNode, cur: int):
            if node is None:
                return 0
            cur = cur << 1 | node.val
            # 如果是叶子结点，则返回路径上的值
            if node.left is None and node.right is None:
                return cur
            # 递归
            return dfs(node.left, cur) + dfs(node.right, cur)

        return dfs(root, 0)
