'''
Descroption: LeetCode 437. 路径总和 III
Author: EmoryHuang
Date: 2021-09-28 16:25:38
Method:
dfs
建立双重递归，第一个递归遍历每个节点，将其作为起始节点
第二个递归处理以每个 root 为根节点的树
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        def dfs1(root: TreeNode):
            if not root:
                return
            dfs2(root, root.val)
            dfs1(root.left)
            dfs1(root.right)

        def dfs2(root: TreeNode, val: int):
            if not root:
                return
            if val == targetSum:
                self.ans += 1
            if root.left:
                dfs2(root.left, val + root.left.val)
            if root.right:
                dfs2(root.right, val + root.right.val)

        self.ans = 0
        dfs1(root)
        return self.ans
